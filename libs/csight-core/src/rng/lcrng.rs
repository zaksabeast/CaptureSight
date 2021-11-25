use super::Rng;

pub type LcrngState = [u64; 1];

#[derive(Clone, Copy, Debug)]
pub struct Lcrng {
    state: LcrngState,
}

impl Rng for Lcrng {
    type State = LcrngState;

    fn from_state(state: Self::State) -> Self {
        Self { state }
    }

    fn set_state(&mut self, state: Self::State) {
        self.state = state;
    }

    fn get_state(&self) -> Self::State {
        self.state
    }

    fn next(&mut self) -> u32 {
        self.state[0].wrapping_mul(0x6c078965).wrapping_add(1) as u32
    }
}
