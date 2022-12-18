use crate::rng::Rng;
use crate::rng::Xoroshiro;
use pkm_rs::{Pk8, Pkx};

// Placeholder
const EMPTY_IV: u8 = u8::MAX;

fn get_rand_less_than_6(rng: &mut Xoroshiro) -> usize {
    loop {
        let rand = rng.next() & 7;
        if rand < 6 {
            return rand as usize;
        }
    }
}

fn find_empty_iv(ivs: &[u8], rng: &mut Xoroshiro) -> usize {
    loop {
        let iv_index = get_rand_less_than_6(rng);
        if ivs[iv_index] == EMPTY_IV {
            return iv_index;
        }
    }
}

fn generate_pk8_ivs(mut rng: Xoroshiro, flawless_iv_count: u8) -> [u8; 6] {
    let mut ivs = [EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV, EMPTY_IV];

    // Get flawless ivs
    for _ in 0..flawless_iv_count {
        let iv_index = find_empty_iv(&ivs, &mut rng);
        ivs[iv_index] = 31;
    }

    // Fill in empty ivs
    for iv in ivs.iter_mut() {
        if *iv == EMPTY_IV {
            *iv = (rng.next() & 31) as u8;
        }
    }

    ivs
}

fn check_if_seed_creates_ivs(rng: Xoroshiro, ivs: [u8; 6]) -> bool {
    for flawless_iv_count in 1..6 {
        let rng_copy = rng;
        let test_ivs = generate_pk8_ivs(rng_copy, flawless_iv_count);

        if ivs == test_ivs {
            return true;
        }
    }
    false
}

fn find_raid_seed(ec: u32, pid: u32, ivs: [u8; 6]) -> Option<u64> {
    let s1 = 0x82A2B175229D6A5B;
    let pid_mask = 0x3FC000;
    let masked_pid = pid & pid_mask;
    let s0_low = (ec as u64).wrapping_sub(s1) & 0xFFFFFFFF;

    let mut temp_low = (s0_low ^ s1) & 0xFFFFFFFF;
    temp_low = temp_low ^ (temp_low << 16);

    for i in 0..=0xFFu64 {
        for j in 0..0xFFu64 {
            let s0_high = ((j ^ temp_low).rotate_right(24) & 0xFFFFFFFF00000000) | (i << 32);
            let partial_test_seed = s0_low | s0_high;
            let mut rng = Xoroshiro::new(partial_test_seed & 0xffffffffffff);
            rng.next_u64(); // ec
            rng.next_u64(); // sidtid
            let test_pid = rng.next() & pid_mask; // pid

            if test_pid == masked_pid {
                for k in 0..=0xFFFFu64 {
                    let seed = (k << 48).wrapping_add(partial_test_seed);
                    let mut rng = Xoroshiro::new(seed);
                    rng.next_u64(); // ec
                    rng.next_u64(); // sidtid
                    let generated_pid = rng.next(); // pid

                    if generated_pid == pid && check_if_seed_creates_ivs(rng, ivs) {
                        return Some(seed);
                    }
                }
            }
        }
    }

    None
}

fn find_pk8_raid_seed(pk8: &Pk8) -> Option<u64> {
    let ivs = pk8.ivs();
    let iv_array = [ivs.hp, ivs.atk, ivs.def, ivs.spa, ivs.spd, ivs.spe];
    find_raid_seed(pk8.encryption_constant(), pk8.pid(), iv_array)
}

mod c_api {
    use pkm_rs::{Pa8, Pk8, Pk9};

    #[no_mangle]
    pub unsafe extern "C" fn find_pk8_raid_seed(out: *mut u64, ptr: *mut Pk8) -> bool {
        let pk8 = crate::utils::open_box!(ptr);
        let seed = super::find_pk8_raid_seed(pk8);

        match seed {
            Some(seed) => {
                *out = seed;
                true
            }
            None => false,
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn find_pa8_raid_seed(_out: *mut u64, _ptr: *mut Pa8) -> bool {
        false
    }

    #[no_mangle]
    pub unsafe extern "C" fn find_pk9_raid_seed(_out: *mut u64, _ptr: *mut Pk9) -> bool {
        false
    }
}

#[cfg(test)]
mod test {
    use super::*;

    mod find_raid_seed {
        use super::*;

        #[test]
        fn should_find_raid_seed() {
            let seed = find_raid_seed(0x23a70881, 0x20a40afe, [31, 31, 22, 31, 31, 31]);
            assert_eq!(seed, Some(0xd22e197401099e26))
        }
    }

    mod check_if_seed_creates_ivs {
        use super::*;

        #[test]
        fn should_return_true_if_rng_creates_ivs() {
            let mut rng = Xoroshiro::new(0xd22e197401099e26);
            rng.next_u64(); // ec
            rng.next_u64(); // pid

            let result = check_if_seed_creates_ivs(rng, [31, 31, 22, 31, 31, 31]);
            assert_eq!(result, true)
        }

        #[test]
        fn should_return_false_if_rng_does_not_create_ivs() {
            let mut rng = Xoroshiro::new(0xd22e197401099e26);
            rng.next_u64(); // ec
            rng.next_u64(); // pid

            let result = check_if_seed_creates_ivs(rng, [0, 0, 0, 0, 0, 0]);
            assert_eq!(result, false)
        }
    }
}
