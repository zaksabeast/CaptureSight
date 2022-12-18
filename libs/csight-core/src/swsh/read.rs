use super::offsets::{BlockOffset, MyStatus8Offset, Pk8Offset};
use crate::{dmntcht::DmntReader, trainer_info::TrainerInfo};
use pkm_rs::{Ek8, Pk8};

pub fn read_trainer_info() -> TrainerInfo {
    DmntReader::new_from_heap(
        u64::from(BlockOffset::MyStatus8) + u64::from(MyStatus8Offset::SidTid),
    )
    .read_offset(0)
}

pub fn read_party_pokemon(index: u8) -> Pk8 {
    DmntReader::new_from_heap(u64::from(Pk8Offset::Party) + ((index as u64) * 0x158))
        .read_offset::<Ek8>(0)
        .into()
}

pub fn read_wild_pokemon() -> Pk8 {
    DmntReader::new_from_heap(Pk8Offset::Wild)
        .read_offset::<Ek8>(0)
        .into()
}

pub fn read_wild_legend_pokemon() -> Pk8 {
    DmntReader::new_from_heap(Pk8Offset::WildLegend)
        .read_offset::<Ek8>(0)
        .into()
}

pub fn read_trade_pokemon() -> Pk8 {
    DmntReader::new_from_heap(Pk8Offset::Trade)
        .read_offset::<Ek8>(0)
        .into()
}

pub fn read_raid_pokemon() -> Pk8 {
    DmntReader::new_from_heap(Pk8Offset::Raid)
        .read_offset::<Ek8>(0)
        .into()
}

mod c_api {
    use crate::{
        dmntcht::DmntReader,
        swsh::{Den, DenType},
        titles::SupportedGame,
        trainer_info::TrainerInfo,
    };
    use pkm_rs::Pk8;

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_trainer_info(out: *mut TrainerInfo) {
        *out = super::read_trainer_info();
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_party_pokemon(index: u8) -> *mut Pk8 {
        crate::utils::boxed!(super::read_party_pokemon(index))
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_wild_pokemon() -> *mut Pk8 {
        crate::utils::boxed!(super::read_wild_pokemon())
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_wild_legend_pokemon() -> *mut Pk8 {
        crate::utils::boxed!(super::read_wild_legend_pokemon())
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_trade_pokemon() -> *mut Pk8 {
        crate::utils::boxed!(super::read_trade_pokemon())
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_raid_pokemon() -> *mut Pk8 {
        crate::utils::boxed!(super::read_raid_pokemon())
    }

    #[no_mangle]
    pub unsafe extern "C" fn swsh_read_den(
        is_sword: bool,
        index: usize,
        den_type: DenType,
    ) -> *mut Den {
        let game = if is_sword {
            SupportedGame::Sword
        } else {
            SupportedGame::Shield
        };

        let base_offset = den_type.get_offset();
        let offset = u64::from(base_offset) + (index * Den::SIZE) as u64;
        let data = DmntReader::new_from_heap(offset).read_offset(0);

        let den_hash_index = den_type.get_den_hash_index(index);

        let den = Den::new(data, den_hash_index, game);

        crate::utils::boxed!(den)
    }
}
