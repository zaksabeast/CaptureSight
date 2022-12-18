use super::offsets::Offsets;
use crate::dmntcht::DmntReader;
use pkm_rs::{Ek9, Pk9};

fn read_pokemon_from_core_param(reader: DmntReader) -> Pk9 {
    reader
        .follow(0x70)
        .follow(0x10)
        .read_offset::<Ek9>(0)
        .into()
}

fn read_party_pokemon(index: u8) -> Pk9 {
    let party = DmntReader::new_from_main_nso(u64::from(Offsets::Party))
        .follow(0)
        .follow(0x28);
    let slot = party.follow(8 * index as u64 + 0x30);
    read_pokemon_from_core_param(slot)
}

const RAID_SEED_ADDRS: [u64; 7] = [
    0x7100943acc,
    0x7100943b2c,
    0x71011aa5a4,
    0x7101865708,
    0x7101865b58,
    0x7101867d98,
    0x7101de188c,
];

fn read_top_level_raid_seed() -> u64 {
    let list = DmntReader::new_from_main_nso(u64::from(Offsets::MainSingleton))
        .follow(0)
        .follow(0x1c0);

    let mut addr;
    // The game does this in an infinite loop,
    // but we're going to cap to something reasonable.
    for i in 0..100 {
        // The game actually:
        // 1. Calls the function
        // 2. Follows the return value in an infinite loop: `while(true) { result = *result; if result == 0 || result == 0x7104340888 { break } }`
        // 3. Returns false if 0 is found, true if the other value is found
        // 4. If true, that's the item used to get the seed
        //
        // However, that seems unecessary - checking only the first value seems to work
        let item = list.follow(i * 8);
        let func = item.follow(0x28).follow(0);
        addr = func.nso_address();
        // The game looks for a value these functions are hardcoded to return
        if RAID_SEED_ADDRS
            .iter()
            .find(|seed_addr| **seed_addr == addr)
            .is_some()
        {
            return item.read_offset(0x40);
        }
    }

    0
}

mod c_api {
    use pkm_rs::Pk9;

    #[no_mangle]
    pub unsafe extern "C" fn sv_read_party_pokemon(index: u8) -> *mut Pk9 {
        crate::utils::boxed!(super::read_party_pokemon(index))
    }

    #[no_mangle]
    pub unsafe extern "C" fn sv_read_top_level_raid_seed() -> u64 {
        super::read_top_level_raid_seed()
    }
}
