use super::{offsets::Offset, spawn::Spawn};
use crate::dmntcht::DmntReader;
use alloc::boxed::Box;
use core::cmp;
use pkm_rs::{Pk9, Pk9Data};

// 30 is the hardcoded max.  For reference: .text + 0x830eb4 in 1.0.0
const MAX_BATTLE_POKEMON_COUNT: u8 = 30;

pub fn get_player_singleton() -> DmntReader {
    DmntReader::new_from_main_nso(Offset::PlayerSingleton).follow(0)
}

fn read_pokemon_from_poke_param(reader: DmntReader) -> Pk9 {
    reader
        .follow(0x98)
        .follow(0x10)
        .read_offset::<Pk9Data>(0)
        .into()
}

fn get_party() -> DmntReader {
    get_player_singleton().follow(0xd0).follow(0x58)
}

fn read_party_pokemon(index: u8) -> Pk9 {
    let party_member_param = get_party().follow(0x58 + (index as u64) * 8);
    read_pokemon_from_poke_param(party_member_param)
}

fn read_party_count() -> u8 {
    let read_size = get_party().read_offset(0x88);
    cmp::min(read_size, 6)
}

fn get_battle_setup() -> DmntReader {
    DmntReader::new_from_main_nso(Offset::BattleSingleton)
        .follow(0)
        .follow(0xb0)
        .follow(0xe0)
        .follow(0xd0)
}

fn read_wild_pokemon_count() -> u8 {
    let read_battle_pokemon_count = get_battle_setup().read_offset::<u32>(0x1a0) as u8;
    let safe_battle_count = cmp::min(read_battle_pokemon_count, MAX_BATTLE_POKEMON_COUNT);
    let party_count = read_party_count();

    if safe_battle_count < party_count {
        0
    } else {
        safe_battle_count - read_party_count()
    }
}

fn read_wild_pokemon(index: u8) -> Pk9 {
    let party_count = read_party_count();
    let battle_setup = get_battle_setup();
    let safe_index = cmp::min(party_count + index, MAX_BATTLE_POKEMON_COUNT);
    let pokemon_container = battle_setup.follow(0xb0 + 8 * (safe_index as u64));
    let poke_param = pokemon_container.follow(0x70).follow(0x60);
    read_pokemon_from_poke_param(poke_param)
}

// Todo: make better after playing the game
fn get_spawn_list() -> DmntReader {
    DmntReader::new_from_main_nso(Offset::SpawnSingleton)
        .follow(0)
        .follow(0x330)
}

fn read_spawn_count() -> usize {
    let spawn_list_byte_size = get_spawn_list().read_offset::<u32>(0x18) as usize;
    (spawn_list_byte_size / Spawn::DATA_SIZE) - 1
}

fn read_spawn(index: usize) -> Spawn {
    // Same value as Spawn::DATA_SIZE, but they aren't linked
    let list_start = get_spawn_list().add(0x70);
    let offset = index * Spawn::DATA_SIZE;
    list_start.read_offset(offset as u64)
}

fn read_active_spawn_count() -> usize {
    let spawn_count = read_spawn_count();

    let mut active_spawn_count = 0;

    for index in 0..spawn_count {
        let spawn = read_spawn(index);
        if spawn.get_is_active() {
            active_spawn_count += 1;
        }
    }

    active_spawn_count
}

fn read_next_active_spawn(start_index: usize) -> (Spawn, usize) {
    let spawn_count = read_spawn_count();

    for index in start_index..spawn_count {
        let spawn = read_spawn(index);
        if spawn.get_is_active() {
            return (spawn, index);
        }
    }

    (Spawn::default(), 0)
}

mod c_api {
    use super::*;

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_party_pokemon(index: u8) -> *mut Pk9 {
        Box::into_raw(Box::new(read_party_pokemon(index)))
    }

    #[no_mangle]
    pub extern "C" fn arceus_read_wild_pokemon_count() -> u8 {
        read_wild_pokemon_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_wild_pokemon(index: u8) -> *mut Pk9 {
        Box::into_raw(Box::new(read_wild_pokemon(index)))
    }

    #[no_mangle]
    pub extern "C" fn arceus_read_active_spawn_count() -> usize {
        read_active_spawn_count()
    }

    #[no_mangle]
    pub extern "C" fn arceus_read_spawn_count() -> usize {
        read_spawn_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_spawn(index: usize) -> *mut Spawn {
        Box::into_raw(Box::new(read_spawn(index)))
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_next_active_spawn(
        start_index: usize,
        found_index: *mut usize,
    ) -> *mut Spawn {
        let (spawn, index) = read_next_active_spawn(start_index);

        assert!(!found_index.is_null());

        *found_index = index;

        Box::into_raw(Box::new(spawn))
    }
}
