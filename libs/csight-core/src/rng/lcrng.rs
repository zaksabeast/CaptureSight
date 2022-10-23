use super::{Rng, RngState};
use alloc::{vec, vec::Vec};
use no_std_io::EndianRead;

#[derive(Clone, Copy, Eq, PartialEq, Debug, Default, EndianRead)]
pub struct LcrngState {
    s0: u64,
}

impl RngState for LcrngState {
    const STATE_COUNT: usize = 1;
    type StateItem = u64;

    fn get_inner(&self) -> Vec<u64> {
        vec![self.s0]
    }
}

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
        self.state.s0.wrapping_mul(0x6c078965).wrapping_add(1) as u32
    }
}
