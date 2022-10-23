use crate::rng;
use crate::rng::Rng;

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum ShinyType {
    None,
    Star,
    Square,
}

fn get_shiny_value(value: u32) -> u32 {
    (value >> 16) ^ (value & 0xFFFF)
}

fn get_shiny_type(pid: u32, sid_tid: u32) -> ShinyType {
    let psv = get_shiny_value(pid);
    let tsv = get_shiny_value(sid_tid);

    if psv == tsv {
        return ShinyType::Square;
    }

    if (psv ^ tsv) < 16 {
        return ShinyType::Star;
    }

    ShinyType::None
}

pub struct DenShinyDetails {
    pub shiny_type: ShinyType,
    pub advances: Option<u32>,
}

impl DenShinyDetails {
    pub fn get_shiny_details(seed: u64, max_advances: u32) -> Self {
        let mut advances = 0u32;
        let mut shiny_type = ShinyType::None;
        let mut current_seed = seed;

        while advances < max_advances && shiny_type == ShinyType::None {
            let mut rng = rng::Xoroshiro::new(current_seed);

            // Normally used to get the EC,
            // but used as the next seed if there isn't a Pokemon
            current_seed = rng.next_u64();

            let sid_tid = rng.next();
            let pid = rng.next();

            shiny_type = get_shiny_type(pid, sid_tid);
            advances += 1;
        }

        Self {
            shiny_type,
            advances: if shiny_type == ShinyType::None {
                None
            } else {
                Some(advances)
            },
        }
    }
}
