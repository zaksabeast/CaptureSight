use super::offsets::Offset;
use crate::dmntcht::DmntReader;
use core::cmp;
use pkm_rs::{Ea8, Pa8};

// 30 is the hardcoded max.  For reference: .text + 0x830eb4 in 1.0.0
const MAX_BATTLE_POKEMON_COUNT: u8 = 30;

pub fn get_player_singleton() -> DmntReader {
    DmntReader::new_from_main_nso(Offset::PlayerSingleton).follow(0)
}

fn read_pokemon_from_poke_param(reader: DmntReader) -> Pa8 {
    reader
        .follow(0x98)
        .follow(0x10)
        .read_offset::<Ea8>(0)
        .into()
}

fn get_party() -> DmntReader {
    get_player_singleton().follow(0xd0).follow(0x58)
}

fn read_party_pokemon(index: u8) -> Pa8 {
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

fn read_wild_pokemon(index: u8) -> Pa8 {
    let party_count = read_party_count();
    let battle_setup = get_battle_setup();
    let safe_index = cmp::min(party_count + index, MAX_BATTLE_POKEMON_COUNT);
    let pokemon_container = battle_setup.follow(0xb0 + 8 * (safe_index as u64));
    let poke_param = pokemon_container.follow(0x70).follow(0x60);
    read_pokemon_from_poke_param(poke_param)
}

mod c_api {
    use super::*;

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_party_pokemon(index: u8) -> *mut Pa8 {
        crate::utils::boxed!(read_party_pokemon(index))
    }

    #[no_mangle]
    pub extern "C" fn arceus_read_wild_pokemon_count() -> u8 {
        read_wild_pokemon_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_wild_pokemon(index: u8) -> *mut Pa8 {
        crate::utils::boxed!(read_wild_pokemon(index))
    }
}
