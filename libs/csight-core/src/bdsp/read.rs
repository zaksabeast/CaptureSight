use super::offsets;
use crate::{dmntcht::DmntReader, trainer_info::TrainerInfo};
use core::mem;
use no_std_io::EndianRead;
use pkm_rs::{Ek8, Pk8};

fn get_player_prefs_provider() -> DmntReader {
    DmntReader::new_from_main_nso(offsets::get_player_prefs_provider_instance())
        .follow(0)
        .follow(0x18)
        .follow(0xc0)
        .follow(0x28)
        .follow(0xb8)
        .follow(0x0)
}

fn get_field_manager() -> DmntReader {
    DmntReader::new_from_main_nso(offsets::get_field_manager())
        .follow(0)
        .follow(0xb8)
        .follow(0x0)
}

fn get_battle_setup_param() -> DmntReader {
    get_player_prefs_provider().follow(0x800)
}

fn get_read_player_party() -> DmntReader {
    get_player_prefs_provider().follow(0x808)
}

fn get_daycare() -> DmntReader {
    get_player_prefs_provider().add(0x450)
}

fn get_underground_main_proc() -> DmntReader {
    get_field_manager().follow(0xa8).follow(0x10)
}

fn read_pokemon_from_poke_param(reader: DmntReader) -> Pk8 {
    reader
        .follow(0x20)
        .follow(0x18)
        .read_offset::<Ek8>(0x20)
        .into()
}

fn read_pokemon_in_party(reader: DmntReader, index: u8) -> Pk8 {
    let poke_param = reader.follow(0x10).follow(0x20 + (8 * (index as u64)));
    read_pokemon_from_poke_param(poke_param)
}

fn read_party_pokemon(index: u8) -> Pk8 {
    let player_party = get_read_player_party();
    read_pokemon_in_party(player_party, index)
}

fn read_pokemon_count_in_party(reader: DmntReader) -> u32 {
    let count = reader.read_offset(0x18);
    core::cmp::min(count, 6)
}

fn read_party_pokemon_count() -> u32 {
    let player_party = get_read_player_party();
    read_pokemon_count_in_party(player_party)
}

fn read_encounter_party() -> DmntReader {
    // Wild Pokemon are set up in a fake party
    get_battle_setup_param().follow(0x58).follow(0x28)
}

fn read_encounter_pokemon(index: u8) -> Pk8 {
    let encounter_party = read_encounter_party();
    read_pokemon_in_party(encounter_party, index)
}

fn read_encounter_pokemon_count() -> u32 {
    let encounter_party = read_encounter_party();
    read_pokemon_count_in_party(encounter_party)
}

fn get_union_room_manager() -> DmntReader {
    DmntReader::new_from_main_nso(offsets::get_union_room_manager())
        .follow(0)
        .follow(0x18)
        .follow(0xb8)
        .follow(0)
}

fn read_other_player_union_trade_pokemon() -> Pk8 {
    let trade_poke_param = get_union_room_manager()
        .follow(0x110)
        .follow(0x28)
        .follow(0x68);
    read_pokemon_from_poke_param(trade_poke_param)
}

#[derive(Clone, Copy, Default, EndianRead)]
#[repr(C)]
pub struct EggDetails {
    exists: bool,
    #[no_std_io(pad_before = 7)]
    seed: u64,
    step_count: i32,
}

fn read_egg_details() -> EggDetails {
    get_daycare().read_offset(8)
}

fn read_underground_pokemon_count() -> usize {
    get_underground_main_proc().read_offset::<u8>(0x18) as usize
}

fn read_underground_pokemon(index: usize) -> Pk8 {
    get_underground_main_proc()
        .follow(0x10)
        .follow(0x20 + ((index as u64) * 8))
        .follow(0x10)
        .follow(0x10)
        .read_offset::<Ek8>(0x20)
        .into()
}

fn read_trainer_info() -> TrainerInfo {
    get_player_prefs_provider().read_offset(0xe8)
}

#[derive(Clone, Copy, Default, EndianRead)]
#[repr(C)]
pub struct Roamer {
    pub area_id: i32,
    pub rng_seed_low: u32,
    pub rng_seed_high: u32,
    pub species: u32,
    pub hp: u32,
    pub level: u8,
    #[no_std_io(pad_before = 3)]
    pub status: u32,
    pub encounter_status: u8,
}

fn get_roamer_reader() -> DmntReader {
    get_player_prefs_provider().follow(0x2a0)
}

fn read_roamer_count() -> usize {
    get_roamer_reader().read_offset(0x18)
}

pub fn read_roamer(index: usize) -> Roamer {
    let offset = 0x20 + mem::size_of::<Roamer>() * index;
    get_roamer_reader().read_offset(offset as u64)
}

pub fn read_random_group_state_reader() -> DmntReader {
    get_player_prefs_provider().follow(0x348)
}

mod c_api {
    use super::*;

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_trainer_info(out: *mut TrainerInfo) {
        *out = read_trainer_info();
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_egg_details(out: *mut EggDetails) {
        *out = read_egg_details();
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_encounter_pokemon_count() -> u32 {
        read_encounter_pokemon_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_encounter_pokemon(index: u8) -> *mut Pk8 {
        crate::utils::boxed!(read_encounter_pokemon(index))
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_party_pokemon(index: u8) -> *mut Pk8 {
        crate::utils::boxed!(read_party_pokemon(index))
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_party_pokemon_count() -> u32 {
        read_party_pokemon_count()
    }

    #[no_mangle]
    pub extern "C" fn bdsp_read_underground_pokemon_count() -> usize {
        read_underground_pokemon_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_underground_pokemon(index: usize) -> *mut Pk8 {
        crate::utils::boxed!(read_underground_pokemon(index))
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_other_player_union_trade_pokemon() -> *mut Pk8 {
        crate::utils::boxed!(read_other_player_union_trade_pokemon())
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_roamer_count() -> usize {
        read_roamer_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_read_roamer(out: *mut Roamer, index: usize) {
        *out = read_roamer(index)
    }
}

#[cfg(test)]
mod test {
    use super::*;

    mod roamer {
        use super::*;

        #[test]
        fn should_be_size_32() {
            assert_eq!(core::mem::size_of::<Roamer>(), 32);
        }
    }

    mod egg_details {
        use super::*;

        #[test]
        fn should_be_size_24() {
            assert_eq!(core::mem::size_of::<EggDetails>(), 24);
        }
    }
}
