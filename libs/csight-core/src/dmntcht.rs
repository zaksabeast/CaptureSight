use safe_transmute::{transmute_one_to_bytes_mut, TriviallyTransmutable};

type NxResultCode = i32;
type NxResult<T> = Result<T, NxResultCode>;

#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
pub struct DmntChtMemoryBase {
    pub main_nso: u64,
    pub heap: u64,
}

#[cfg(target_os = "horizon")]
extern "C" {
    fn dmntchtMemoryBase(base: *mut DmntChtMemoryBase) -> NxResultCode;
    fn dmntchtReadCheatProcessMemory(address: u64, buffer: *mut u8, size: usize) -> NxResultCode;
}

#[cfg(not(target_os = "horizon"))]
#[allow(non_snake_case)]
unsafe fn dmntchtMemoryBase(_base: *mut DmntChtMemoryBase) -> NxResultCode {
    0
}

#[cfg(not(target_os = "horizon"))]
#[allow(non_snake_case)]
unsafe fn dmntchtReadCheatProcessMemory(
    _address: u64,
    _buffer: *mut u8,
    _size: usize,
) -> NxResultCode {
    0
}

fn parse_nx_result_code(result_code: NxResultCode) -> NxResult<()> {
    if result_code != 0 {
        return Err(result_code);
    }

    Ok(())
}

pub fn get_memory_base() -> NxResult<DmntChtMemoryBase> {
    let mut out = Default::default();
    let result_code = unsafe { dmntchtMemoryBase(&mut out) };

    parse_nx_result_code(result_code)?;

    Ok(out)
}

fn read_cheat_process_memory_into_slice(address: u64, out: &mut [u8]) -> NxResult<()> {
    let result_code =
        unsafe { dmntchtReadCheatProcessMemory(address, out.as_mut_ptr(), out.len()) };
    parse_nx_result_code(result_code)
}

pub fn read_cheat_process_memory<T: TriviallyTransmutable + Default>(address: u64) -> NxResult<T> {
    let mut out: T = Default::default();
    let out_bytes = transmute_one_to_bytes_mut(&mut out);

    read_cheat_process_memory_into_slice(address, out_bytes)?;

    Ok(out)
}

pub fn read_cheat_process_memory_default<T: TriviallyTransmutable + Default>(address: u64) -> T {
    read_cheat_process_memory::<T>(address).unwrap_or_default()
}

pub struct DmntReader {
    address: u64,
}

impl DmntReader {
    pub fn new_from_main_nso<T: Into<u64>>(offset: T) -> Self {
        let base = get_memory_base().unwrap_or_default();
        Self {
            address: base.main_nso + offset.into(),
        }
    }

    pub fn new_from_heap<T: Into<u64>>(offset: T) -> Self {
        let base = get_memory_base().unwrap_or_default();
        Self {
            address: base.heap + offset.into(),
        }
    }

    pub fn follow(&self, offset: u64) -> Self {
        Self {
            address: read_cheat_process_memory_default(self.address + offset),
        }
    }

    pub fn add(&self, offset: u64) -> Self {
        Self {
            address: self.address + offset,
        }
    }

    pub fn read_offset<T: TriviallyTransmutable + Default>(&self, offset: u64) -> T {
        read_cheat_process_memory_default(self.address + offset)
    }
}
