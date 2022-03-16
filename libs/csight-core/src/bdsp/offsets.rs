use crate::dmntcht;
use crate::titles::SupportedGame;

pub fn get_player_prefs_provider_instance() -> u64 {
    if dmntcht::get_title_id().unwrap_or_default() == SupportedGame::BrilliantDiamond {
        0x4c90330
    } else {
        0x4ea7408
    }
}

pub fn get_field_manager() -> u64 {
    if dmntcht::get_title_id().unwrap_or_default() == SupportedGame::BrilliantDiamond {
        0x4c5a638
    } else {
        0x4e71710
    }
}

pub fn get_main_rng() -> u64 {
    0x4fd43d0
}

pub fn get_union_room_manager() -> u64 {
    if dmntcht::get_title_id().unwrap_or_default() == SupportedGame::BrilliantDiamond {
        0x4c67750
    } else {
        0x4e7e828
    }
}

