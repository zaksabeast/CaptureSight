mod xoroshiro;
pub use xoroshiro::*;

mod xorshift;
pub use xorshift::*;

mod lcrng;
pub use lcrng::*;

/// An RNG
pub trait Rng: Copy {
    type State: PartialEq;

    /// Creates the rng.
    fn from_state(state: Self::State) -> Self;

    // Sets the state.
    fn set_state(&mut self, state: Self::State);

    /// Returns the current state.
    fn get_state(&self) -> Self::State;

    /// Gets the next random number.
    fn next(&mut self) -> u32;

    /// Advances to the given state and returns the number of advances
    /// that were taken.
    ///
    /// The rng is not advanced if the state cannot be reached, and
    /// None will be returned.
    fn advance_to_state(&mut self, state: Self::State) -> Option<u64> {
        let mut advances = 0;
        let mut copy = *self;

        // 10,000 is an arbitary limit to avoid an infinite loop
        while copy.get_state() != state {
            copy.next();
            advances += 1;

            if advances > 10_000 {
                return None;
            }
        }

        self.set_state(copy.get_state());

        Some(advances)
    }
}
