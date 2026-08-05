# ForeverExampleCustomModule
This is an example custom module for TwinkieForever, using the external C++ API.
See [CreatingModules.md](https://github.com/TwinkieTweaks/TwinkieForever/blob/master/CreatingModules.md) for more information.

# ModLoader
If your DLL uses the Twinkie C++ module API, and you plan on releasing your DLL via ModLoader, then you must add Twinkie as a dependancy in your `description.yaml` file.

# IMPORTANT
Twinkie is a **32-bit (x86) only** application. Your DLLs have to be built in x86 arch. \
The Twinkie C++ module API only works with [v2.0.1](https://github.com/TwinkieTweaks/TwinkieForever/releases/tag/v2.0.1) and later. Any other release will not work.
