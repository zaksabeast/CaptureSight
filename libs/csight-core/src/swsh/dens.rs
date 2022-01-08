use super::{
    den_encounter::{DenEncounter, DenEncounters},
    den_hashes,
    den_shiny_details::DenShinyDetails,
    shield_nests, sword_nests,
};
use crate::titles::SupportedGame;
use no_std_io::Reader;

type DenBytes = [u8; Den::SIZE];

pub struct Den {
    data: DenBytes,
    index: usize,
    game: SupportedGame,
}

impl Reader for Den {
    fn get_slice(&self) -> &[u8] {
        &self.data
    }
}

impl Den {
    pub const SIZE: usize = 0x18;

    pub fn new(data: DenBytes, index: usize, game: SupportedGame) -> Self {
        Self { data, index, game }
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
                .get(self.index)
                .unwrap_or(&den_hashes::Nest::N12ad4e9a799417a5);
        }

        return *den_hashes::NORMAL_DENS
            .get(self.index)
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
