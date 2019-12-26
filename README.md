# CaptureSight

CaptureSight is a switch homebrew to view Sword and Shield data while playing the games.

Right now it's super barebones, and there are many improvments which can be made.

## Building

All libraries [listed in Plutonium's readme](https://github.com/XorTroll/Plutonium#what-is-plutonium), devkitPro, and libnx will be needed to build this tool.

After installing those, run `make`.

## Credits

Thanks to the following for helping make this app:

- Switchbrew for their research and [libnx](https://github.com/switchbrew/libnx) which makes it possible to create homebrew
- ReSwitched for their research, [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere) and [libstratosphere](https://github.com/Atmosphere-NX/libstratosphere) which was invaluable to make this homebrew possible
- XorTroll for [Plutonium](https://github.com/XorTroll/Plutonium/tree/master/Plutonium) which is used for the UI
- Kaphotics, SciresM, and all contributors of [PKHeX](https://github.com/kwsch/PKHeX/) which has great documentation of implementation for the PK8 format (among other things), Pokemon icons, and i18n resources
- Flagbrew for [PKSM](https://github.com/FlagBrew/PKSM) which gave guidance for c++ Pokemon code organization
- RichardPaulAstley for French translations
- Leanny, Admiral Fish, wwwwwwzx, Kaphotics, and Vladcik for helping look into raid RNG
- All Pokemon researchers and contributors
- nlohmann for the amazing c++ JSON library
- WerWolv for EdiZon's `isServiceRunning` code
