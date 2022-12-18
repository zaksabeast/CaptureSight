#[cfg(test)]
use alloc::vec::Vec;
#[cfg(test)]
use core::convert::TryFrom;
#[cfg(test)]
use mocktopus::mocking::{MockResult, Mockable};

use alloc::vec;
use core::mem;
use no_std_io::{EndianRead, Reader};

type NxResultCode = i32;
type NxResult<T> = Result<T, NxResultCode>;

#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
pub struct DmntChtMemoryBase {
    main_nso: u64,
    heap: u64,
    alias: u64,
    title_id: u64,
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

pub fn get_title_id() -> Option<u64> {
    let base = get_memory_base().ok()?;
    Some(base.title_id)
}

#[cfg_attr(test, mocktopus::macros::mockable)]
fn read_cheat_process_memory_into_slice(address: u64, out: &mut [u8]) -> NxResult<()> {
    let result_code =
        unsafe { dmntchtReadCheatProcessMemory(address, out.as_mut_ptr(), out.len()) };
    parse_nx_result_code(result_code)
}

#[cfg(test)]
pub fn configure_mock_dmnt_read(data: Vec<u8>) {
    read_cheat_process_memory_into_slice.mock_safe(move |offset: u64, out: &mut [u8]| {
        // This is currently only supported on 64 bit machines
        let offset = usize::try_from(offset).unwrap();
        let out_size = out.len() + offset;

        if out_size < data.len() {
            out.copy_from_slice(&data[offset..out_size]);
            MockResult::Return(Ok(()))
        } else {
            MockResult::Return(Err(-1))
        }
    });
}

pub fn read_cheat_process_memory<T: EndianRead>(address: u64) -> NxResult<T> {
    let mut out = vec![0u8; mem::size_of::<T>()];

    read_cheat_process_memory_into_slice(address, &mut out)?;

    out.read_le(0).map_err(|_| 0x1234i32)
}

pub fn read_cheat_process_memory_default<T: EndianRead + Default>(address: u64) -> T {
    read_cheat_process_memory(address).unwrap_or_default()
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
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

    pub fn nso_address(&self) -> u64 {
        let base = get_memory_base().unwrap_or_default();
        self.address - base.main_nso + 0x7100000000
    }

    pub fn read_offset<T: EndianRead + Default>(&self, offset: u64) -> T {
        read_cheat_process_memory_default(self.address + offset)
    }
}
