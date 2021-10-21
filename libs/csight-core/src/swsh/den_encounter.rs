use pkm_rs::types;

#[derive(Clone, Copy, Debug)]
pub struct DenEncounter {
    pub species: types::Species,
    pub flawless_ivs: u8,
    pub probabilities: [u32; 5],
}

impl Default for DenEncounter {
    fn default() -> Self {
        Self {
            species: types::Species::None,
            flawless_ivs: 0,
            probabilities: [0, 0, 0, 0, 0],
        }
    }
}

pub type DenEncounters = [DenEncounter; 12];
