use super::{
    den_encounter::{DenEncounter, DenEncounters},
    den_hashes,
    den_shiny_details::DenShinyDetails,
    offsets::DenOffset,
    shield_nests, sword_nests,
};
use crate::{swsh::ShinyType, titles::SupportedGame};
use alloc::string::ToString;
use no_std_io::Reader;

type DenBytes = [u8; Den::SIZE];

pub struct Den {
    data: DenBytes,
    den_hash_index: usize,
    game: SupportedGame,
}

impl Reader for Den {
    fn get_slice(&self) -> &[u8] {
        &self.data
    }
}

impl Den {
    pub const SIZE: usize = 0x18;

    pub fn new(data: DenBytes, den_hash_index: usize, game: SupportedGame) -> Self {
        Self {
            data,
            den_hash_index,
            game,
        }
    }

    pub fn seed(&self) -> u64 {
        self.default_read(0x8)
    }

    fn stars(&self) -> u8 {
        core::cmp::min(self.default_read(0x10), 4)
    }

    fn rand_roll(&self) -> u8 {
        self.default_read(0x11)
    }

    fn den_type(&self) -> u8 {
        self.default_read(0x12)
    }

    pub fn is_active(&self) -> bool {
        self.den_type() > 0
    }

    fn is_rare(&self) -> bool {
        self.is_active() && (self.den_type() & 1) == 0
    }

    fn flag_byte(&self) -> u8 {
        self.default_read(0x13)
    }

    // Keeping for documentation
    // fn has_watts(&self) -> bool {
    //     (self.flag_byte() & 1) == 0
    // }

    pub fn is_event(&self) -> bool {
        ((self.flag_byte() >> 1) & 1) == 1
    }

    fn nest(&self) -> den_hashes::Nest {
        if self.is_rare() {
            return *den_hashes::RARE_DENS
                .get(self.den_hash_index)
                .unwrap_or(&den_hashes::Nest::N12ad4e9a799417a5);
        }

        return *den_hashes::NORMAL_DENS
            .get(self.den_hash_index)
            .unwrap_or(&den_hashes::Nest::N12ad4e9a799417a5);
    }

    fn possible_encounters(&self) -> &'static DenEncounters {
        let hash = self.nest();
        match self.game {
            SupportedGame::Sword => sword_nests::get_encounters(hash),
            _ => shield_nests::get_encounters(hash),
        }
    }

    pub fn encounter(&self) -> DenEncounter {
        if self.is_event() {
            return DenEncounter::default();
        }

        let mut user_probability = 1u32;
        let stars = self.stars() as usize;
        let rand_roll = self.rand_roll() as u32;
        let nest = self.possible_encounters();

        for encounter in nest {
            let nest_probability = match encounter.probabilities.get(stars) {
                Some(probability) => *probability,
                None => 0,
            };
            user_probability += nest_probability;

            if user_probability > rand_roll {
                return *encounter;
            }
        }

        DenEncounter::default()
    }

    pub fn shiny_details(&self, max_advances: u32) -> DenShinyDetails {
        DenShinyDetails::get_shiny_details(self.seed(), max_advances)
    }
}

// This is used by c, but rust doesn't know it's actually in use
#[allow(dead_code)]
#[repr(C)]
pub enum DenType {
    Vanilla = 0,
    IslandOfArmor = 1,
    CrownTundra = 2,
}

impl DenType {
    pub fn get_offset(&self) -> DenOffset {
        match self {
            DenType::Vanilla => DenOffset::Vanilla,
            DenType::IslandOfArmor => DenOffset::IslandOfArmor,
            DenType::CrownTundra => DenOffset::CrownTundra,
        }
    }

    pub fn get_den_hash_index(&self, index: usize) -> usize {
        let offset = match self {
            DenType::Vanilla => 0,
            DenType::IslandOfArmor => 100,
            DenType::CrownTundra => 190,
        };

        index + offset
    }
}

mod c_api {
    use super::*;
    use crate::c_str;

    #[no_mangle]
    pub unsafe extern "C" fn free_den(ptr: *mut Den) {
        crate::utils::free!(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn den_shiny_details_string(
        ptr: *mut Den,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        let den = crate::utils::open_box!(ptr);

        let shiny_details = den.shiny_details(10000);

        let shiny_text = match (shiny_details.shiny_type, shiny_details.advances) {
            (ShinyType::Star, Some(advances)) => alloc::format!("★ in {}", advances),
            (ShinyType::Square, Some(advances)) => alloc::format!("■ in {}", advances),
            (_, _) => "No nearby shiny".to_string(),
        };

        c_str::copy_as_c_str(&shiny_text, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn den_species_string(
        ptr: *mut Den,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        let den = crate::utils::open_box!(ptr);

        if den.is_event() {
            c_str::copy_as_c_str("Event", dst, dst_length)
        } else {
            let value = den.encounter().species;
            c_str::copy_display_as_c_str(value, dst, dst_length)
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn den_is_event(ptr: *mut Den) -> bool {
        crate::utils::run_method!(ptr, is_event)
    }

    #[no_mangle]
    pub unsafe extern "C" fn den_is_active(ptr: *mut Den) -> bool {
        crate::utils::run_method!(ptr, is_active)
    }

    #[no_mangle]
    pub unsafe extern "C" fn den_seed(ptr: *mut Den) -> u64 {
        crate::utils::run_method!(ptr, seed)
    }
}
