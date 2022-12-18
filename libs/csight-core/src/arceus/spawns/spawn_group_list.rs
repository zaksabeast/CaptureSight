use super::spawn_group::SpawnGroup;
use crate::{arceus::offsets::Offset, dmntcht::DmntReader};
use core::cmp;

const MAX_SPAWN_GROUP_COUNT: usize = 512;

pub struct SpawnGroupList {
    reader: DmntReader,
}

impl SpawnGroupList {
    const COUNT_OFFSET: u64 = 0x18;
    const LIST_OFFSET: u64 = 0x70;

    pub fn new(reader: DmntReader) -> Self {
        Self { reader }
    }

    pub fn get_spawn_group_count(&self) -> usize {
        let spawn_list_byte_size = self.reader.read_offset::<u32>(Self::COUNT_OFFSET) as usize;
        let read_spawn_group_count = spawn_list_byte_size / SpawnGroup::DATA_SIZE;
        cmp::min(read_spawn_group_count, MAX_SPAWN_GROUP_COUNT)
    }

    pub fn get_active_spawn_group_count(&self) -> usize {
        let count = self.get_spawn_group_count();

        for index in 0..count {
            if !self.get_spawn_group(index).get_is_active() {
                return index;
            }
        }

        count
    }

    pub fn get_spawn_group(&self, index: usize) -> SpawnGroup {
        if self.get_spawn_group_count() <= index {
            return SpawnGroup::default();
        }

        let offset = index * SpawnGroup::DATA_SIZE;
        self.reader.read_offset(Self::LIST_OFFSET + (offset as u64))
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
    pub extern "C" fn arceus_read_active_spawn_group_count() -> usize {
        let spawn_group_list = read_spawn_group_list();
        spawn_group_list.get_active_spawn_group_count()
    }

    #[no_mangle]
    pub unsafe extern "C" fn arceus_read_spawn_group(index: usize) -> *mut SpawnGroup {
        let spawn_group_list = read_spawn_group_list();
        let spawn_group = spawn_group_list.get_spawn_group(index);
        crate::utils::boxed!(spawn_group)
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use crate::dmntcht::configure_mock_dmnt_read;
    use core::convert::TryFrom;
    use no_std_io::Writer;

    struct MockSpawnGroupListData {
        data: [u8; 0x8f0],
    }

    impl MockSpawnGroupListData {
        fn new() -> Self {
            Self { data: [0; 0x8f0] }
        }

        fn write_spawn_group_count(&mut self, count: u32) {
            let size = u32::try_from(SpawnGroup::DATA_SIZE).unwrap();
            let base_offset = usize::try_from(SpawnGroupList::COUNT_OFFSET).unwrap();
            self.write_le(base_offset, &(count * size)).unwrap();
        }

        fn write_spawn_group(&mut self, index: usize, spawn_group: &SpawnGroup) {
            let base_offset = usize::try_from(SpawnGroupList::LIST_OFFSET).unwrap();
            self.write_le(base_offset + (index * SpawnGroup::DATA_SIZE), spawn_group)
                .unwrap();
        }

        fn configure_mock_dmnt_read(&self) {
            configure_mock_dmnt_read(self.data.to_vec())
        }
    }

    impl Writer for MockSpawnGroupListData {
        fn get_mut_slice(&mut self) -> &mut [u8] {
            &mut self.data
        }
    }

    fn new_mock_spawn_group_list() -> SpawnGroupList {
        SpawnGroupList::new(DmntReader::new_from_main_nso(0u64))
    }

    mod get_spawn_group_count {
        use super::*;

        #[test]
        fn should_return_read_count() {
            let mut mock_data = MockSpawnGroupListData::new();
            // Dumped from memory
            mock_data.write(0x18, &0x88130u32).unwrap();
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();
            let count = spawn_group_list.get_spawn_group_count();

            assert_eq!(count, 512)
        }

        #[test]
        fn should_return_510_if_read_count_is_higher_than_510() {
            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(10000);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();
            let count = spawn_group_list.get_spawn_group_count();

            assert_eq!(count, MAX_SPAWN_GROUP_COUNT)
        }
    }

    mod get_active_spawn_group_count {
        use super::*;
        use crate::arceus::spawns::{spawn::Spawn, spawn_pair::SpawnPair};

        #[test]
        fn should_read_active_count_if_all_groups_are_active() {
            let mut mock_spawn = Spawn::default();
            mock_spawn.set_is_active(true);

            let mut mock_spawn_pair = SpawnPair::default();
            mock_spawn_pair.set_spawner_1(&mock_spawn);

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_spawn_pair(&mock_spawn_pair);

            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(1);
            mock_data.write_spawn_group(0, &mock_spawn_group);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();

            assert_eq!(spawn_group_list.get_active_spawn_group_count(), 1)
        }

        #[test]
        fn should_read_active_count_if_not_all_groups_are_active() {
            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(2);

            // -----------------------------
            // First spawn group (active)
            // -----------------------------
            let mut mock_spawn = Spawn::default();
            mock_spawn.set_is_active(true);

            let mut mock_spawn_pair = SpawnPair::default();
            mock_spawn_pair.set_spawner_1(&mock_spawn);

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_spawn_pair(&mock_spawn_pair);

            mock_data.write_spawn_group(0, &mock_spawn_group);

            // -----------------------------
            // Second spawn group (inactive)
            // -----------------------------
            let mut mock_spawn = Spawn::default();
            mock_spawn.set_is_active(false);

            let mut mock_spawn_pair = SpawnPair::default();
            mock_spawn_pair.set_spawner_1(&mock_spawn);

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_spawn_pair(&mock_spawn_pair);

            mock_data.write_spawn_group(1, &mock_spawn_group);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();
            assert_eq!(spawn_group_list.get_active_spawn_group_count(), 2)
        }

        #[test]
        fn should_return_0_if_count_is_0() {
            let mut mock_spawn = Spawn::default();
            mock_spawn.set_is_active(true);

            let mut mock_spawn_pair = SpawnPair::default();
            mock_spawn_pair.set_spawner_1(&mock_spawn);

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_spawn_pair(&mock_spawn_pair);

            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(0);
            mock_data.write_spawn_group(0, &mock_spawn_group);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();

            assert_eq!(spawn_group_list.get_active_spawn_group_count(), 0)
        }
    }

    mod get_spawn_group {
        use super::*;

        #[test]
        fn should_read_spawn_group_at_index() {
            let seed0 = 0xaaaabbbbccccdddd;

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_seed(seed0);

            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(1);
            mock_data.write_spawn_group(0, &mock_spawn_group);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();
            let spawn_group = spawn_group_list.get_spawn_group(0);

            assert_eq!(spawn_group.get_seed(), seed0)
        }

        #[test]
        fn should_return_default_spawn_group_if_index_is_higher_than_available_count() {
            let seed0 = 0xaaaabbbbccccdddd;

            let mut mock_spawn_group = SpawnGroup::default();
            mock_spawn_group.set_seed(seed0);

            let mut mock_data = MockSpawnGroupListData::new();
            mock_data.write_spawn_group_count(0);
            mock_data.write_spawn_group(0, &mock_spawn_group);
            mock_data.configure_mock_dmnt_read();

            let spawn_group_list = new_mock_spawn_group_list();
            let spawn_group = spawn_group_list.get_spawn_group(0);

            assert_eq!(spawn_group, SpawnGroup::default())
        }
    }
}
