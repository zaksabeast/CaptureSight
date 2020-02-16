# CaptureSight

CaptureSight is a Nintendo Switch homebrew to view Pokemon Sword and Shield data while playing Sword and Shield. CaptureSight comes as both an overlay and an applet.

### Features:

- View Pokemon species, attacks, IVs, etc. for
  - Wild Pokemon
  - In-Trade Pokemon
  - Raid Pokemon
  - Party Pokemon
  - Box Pokemon
- View all Active Dens
  - Current seed for Raid RNG
  - The number of advances until a Shiny Pokemon
  - Species of a den
  - Shiny type of a den (star or square)
  - Stars of a den
- Find the raid seed that created a Pokemon
  - Join a trade or raid with a person who doesn't have custom firmware and use CaptureSight to get their raid seed
  - View upcoming IVs for any den or Pokemon raid seed
- Since CaptureSight can show the next shiny frame, upcoming IVs, and seed that created a Pokemon, no external tools are needed for Raid RNG
  - With raid and trade views, anyone without custom firmware only needs to know someone with custom firmware to do Raid RNG
- The Applet has translations for multiple langues based on the Switch language setting
  - English
  - Chinese
  - French

## How do I use CaptureSight?

To use the applet:

1. Download the latest CaptureSight-Applet.zip
1. Unzip the archive to get CaptureSight.nro
1. Copy CaptureSight.nro to be inside the /switch directory on your switch's SD card
1. Start Pokemon Sword or Shield
1. Open the homebrew menu and launch CaptureSight

To use the overlay:

1. Setup WerWolv's Tesla - https://gbatemp.net/threads/tesla-the-nintendo-switch-overlay-menu.557362/
1. Download the latest CaptureSight-Overlay.zip
1. Unzip the archive to get CaptureSight.ovl
1. Copy CaptureSight.ovl to be inside the /switch/.overlays directory on your switch's SD card
1. Start Pokemon Sword or Shield
1. Press the key combo to open Tesla Menu (L + Dpad Down + R joystick as of this writing)
1. Open CaptureSight with Tesla

### Downloading CaptureSight:

Download CaptureSight from the github - https://github.com/zaksabeast/CaptureSight/releases/latest

Two downloads are available for CaptureSight:

- CaptureSight-Applet.zip - This is the applet
- CaptureSight-Overlay.zip - This is the overlay

## Building

All libraries [listed in Plutonium's readme](https://github.com/XorTroll/Plutonium#what-is-plutonium), devkitPro, and libnx will be needed to build this tool.

After installing those, run `make`.

Optional: To build the raid event flatbuffer header, install [flatc](https://google.github.io/flatbuffers/flatbuffers_guide_using_schema_compiler.html) and run `flatc --cpp -o libcsight/include/csight/ libcsight/resources/NestHoleDistributionEncounter8Archive.fbs`. Alternatively, use a docker image with `flatc`, such as [neomantra/flatbuffers](https://hub.docker.com/r/neomantra/flatbuffers).

## Credits

Thanks to the following for helping make this app:

- Switchbrew for their research and [libnx](https://github.com/switchbrew/libnx) which makes it possible to create homebrew
- ReSwitched for their research, [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere) and [libstratosphere](https://github.com/Atmosphere-NX/libstratosphere) which is invaluable for switch homebrew
- Kaphotics, SciresM, and all contributors of [PKHeX](https://github.com/kwsch/PKHeX/) and [pkNX](https://github.com/kwsch/pkNX) which have resource including Pokemon icons, i18n for Pokemon, and great documentation
- imneme for their [cpp xoroshiro gist](https://gist.github.com/imneme/f76f4bb7b7f67ff0850199ab7c077bf7) which is used in CaptureSight
- nlohmann for their [c++ JSON library](https://github.com/nlohmann/json)
- XorTroll for [Plutonium](https://github.com/XorTroll/Plutonium/tree/master/Plutonium)
- WerWolv for [libtesla](https://github.com/WerWolv/libtesla) and EdiZon's `isServiceRunning` code
- Flagbrew for [PKSM](https://github.com/FlagBrew/PKSM) which gave guidance for c++ Pokemon code organization
- RichardPaulAstley for French translations
- Leanny, Admiral Fish, wwwwwwzx, Kaphotics, and Vladcik for helping look into raid RNG
- Leanny and Kaphotics for the PKHeX Raid Plugin, which CaptureSight borrows raid logic from
- All Pokemon researchers and contributors
