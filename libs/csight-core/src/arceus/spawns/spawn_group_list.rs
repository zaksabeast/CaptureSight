use super::spawn_group::SpawnGroup;
use crate::{arceus::offsets::Offset, dmntcht::DmntReader};
use alloc::boxed::Box;
use core::cmp;

pub struct SpawnGroupList {
    reader: DmntReader,
}

impl SpawnGroupList {
    pub fn new(reader: DmntReader) -> Self {
        Self { reader }
    }

    pub fn get_spawn_group_count(&self) -> usize {
        let spawn_list_byte_size = self.reader.read_offset::<u32>(0x18) as usize;
        let read_spawn_group_count = (spawn_list_byte_size / SpawnGroup::DATA_SIZE) - 1;
        cmp::min(read_spawn_group_count, 510)
    }

    pub fn get_spawn_group(&self, index: usize) -> SpawnGroup {
        if self.get_spawn_group_count() >= index {
            return SpawnGroup::default();
        }

        let list_start = self.reader.add(0x70);
        let offset = index * SpawnGroup::DATA_SIZE;
        list_start.read_offset(offset as u64)
    }
}

fn read_spawn_group_list() -> SpawnGroupList {
    let reader = DmntReader::new_from_main_nso(Offset::SpawnSingleton)
        .follow(0)
        .follow(0x330);

    SpawnGroupList::new(reader)
}

mod c_api {
    use super::*;

    #[no_mangle]
    pub extern "C" fn arceus_read_spawn_group_count() -> usize {
        let spawn_group_list = read_spawn_group_list();
        spawn_group_list.get_spawn_group_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_spawn_group(index: usize) -> *mut SpawnGroup {
        let spawn_group_list = read_spawn_group_list();
        let spawn_group = spawn_group_list.get_spawn_group(index);
        Box::into_raw(Box::new(spawn_group))
    }
}
