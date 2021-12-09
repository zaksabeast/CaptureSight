# CaptureSight

CaptureSight is a Nintendo Switch homebrew to view Pokemon data while playing Pokemon games.

### Features:

#### Sword & Shield
- View Pokemon species, attacks, IVs, etc. for
  - Wild Pokemon
  - In-Trade Pokemon
  - Raid Pokemon
  - Party Pokemon
- View all active dens
  - The number of advances until a Shiny Pokemon
  - Species of a den
  - Shiny type of a den (star or square)
- Since CaptureSight can show the next shiny frame, no external tools are needed for Raid RNG
- Find the raid seed that created a Pokemon
  - Join a trade or raid with a person who doesn't have custom firmware and use CaptureSight to get their raid seed
  - With raid and trade views, anyone without custom firmware only needs to know someone with custom firmware to do Raid RNG
- View the main RNG states for RNG purposes
- View your TID and SID

#### Brilliant Diamond & Shining Pearl
- View Pokemon species, attacks, IVs, etc. for
  - Wild Pokemon
  - Party Pokemon
  - Underground Pokemon
- View the main RNG states for RNG purposes
- View egg seed and group seeds for RNG purposes
- View your TID and SID

## How do I use CaptureSight?

1. Setup WerWolv's Tesla - https://gbatemp.net/threads/tesla-the-nintendo-switch-overlay-menu.557362/
1. Download the latest `capturesight.ovl`
1. Copy `capturesight.ovl` to be inside the `/switch/.overlays` directory on your switch's SD card
1. Start Pokemon Sword or Shield, or Brilliant Diamond or Shining Pearl
1. Press the key combo to open Tesla Menu (L + Dpad Down + R joystick as of this writing)
1. Open CaptureSight with Tesla

## Building

1. Install [devkitA64](https://devkitpro.org/wiki/Getting_Started), [libnx](https://github.com/switchbrew/libnx), and [rust](https://www.rust-lang.org/tools/install)
2. Run `make`

## Credits

Thanks to the following for helping make this app:

- Switchbrew for their research and [libnx](https://github.com/switchbrew/libnx) which makes it possible to create homebrew
- ReSwitched for their research, [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere), and [libstratosphere](https://github.com/Atmosphere-NX/libstratosphere) which is invaluable for switch homebrew
- Kaphotics, SciresM, Matt, and all contributors of [PKHeX](https://github.com/kwsch/PKHeX/) and [pkNX](https://github.com/kwsch/pkNX) for the all the great resources this app uses
- WerWolv for [libtesla](https://github.com/WerWolv/libtesla) and EdiZon's `isServiceRunning` code
- All translators and the translations they provided
- Leanny, Admiral Fish, wwwwwwzx, Kaphotics, and Vladcik for looking into raid RNG
- Leanny and Kaphotics for the PKHeX Raid Plugin, which CaptureSight borrows raid logic from
- All Pokemon researchers and contributors
- XorTroll and aarch64-switch-rs for the [aarch64-none-elf.json](https://github.com/aarch64-switch-rs/cargo-nx/blob/ac7c14b72595040a8e14ef86e2645a0a25703e90/default_specs/aarch64-none-elf.json) file
