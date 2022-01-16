use super::{Rng, RngState};
use alloc::vec::Vec;
use safe_transmute::TriviallyTransmutable;

#[derive(Clone, Copy, PartialEq, Debug, Default)]
pub struct LcrngState([u64; 1]);

impl RngState for LcrngState {
    const STATE_COUNT: usize = 1;
    type StateItem = u64;

    fn get_inner(&self) -> Vec<u64> {
        self.0.to_vec()
    }
}

unsafe impl TriviallyTransmutable for LcrngState {}

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
        self.state.0[0].wrapping_mul(0x6c078965).wrapping_add(1) as u32
    }
}
