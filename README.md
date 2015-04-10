###NephQ2

This is my fork of [Quake II VR](https://github.com/q2vr/Quake2VR/), a VR-enabled Quake II engine based on the [KMQuake II](http://www.markshan.com/knightmare/) engine.

####Features

- Gamepad Support
- Oculus Rift Support (0.4.4-beta)
- OpenAL HRTF Support
- SteamVR Support

####Issues

- Linux binaries build, but segfault on initialization. Could be because I'm testing on a Linux VM without any HMD attached or maybe I just screwed up somewhere. GDB hangs the entire VM so I can't debug.
- Linker errors trying to build with MinGW on Windows. I probably need to build all the deps with MinGW instead of linking the MSVC ones, but that's too much work. Use VS Express Edition if you're on Windows.

####Play Requirements

##### Getting Quake II

[![Retail Game](https://img.shields.io/badge/Quake%20II-Full%20Game-blue.svg)](http://store.steampowered.com/app/2320/)
[![Q2 Demo](https://img.shields.io/badge/Quake%20II-3.14%20Demo-brightgreen.svg)](http://store.steampowered.com/app/2320/)
[![Q2 Patch](https://img.shields.io/badge/Quake%20II-3.20%20Patch-brightgreen.svg)](http://store.steampowered.com/app/2320/)

I suggest purchasing the retail version of Quake II from Steam to support id Software and get the full game assets. If you cannot, you can get a limited version that does not include the majority of the single-player campaign for free. Do this by installing the free demo and then installing the official 3.20 patch on top of it. The stock 3.20 binaries no longer run on most modern systems so if you intend to play the vanilla game, the [unofficial Quake II 3.24 patch](http://www.markshan.com/knightmare/downloads/quake2-3.24-win32.zip) will allow you to do so on Windows.

There are also "starter packs" that will handle installing the demo, patch, and working binaries for you automatically available for [Windows (32-Bit)](http://q2s.tastyspleen.net/) (installs [Q2Pro](http://skuller.net/q2pro/) engine), [Mac OSX](http://quake2world.net/files/Quake%20II%20%28Quake2World.net%29.dmg), and [Linux (64-Bit)](http://quake2world.net/files/quake2-quake2world.net-x86_64.tar.gz).

##### Installing NephQ2

[![Data Files](https://img.shields.io/badge/NephQ2-Data%20Files-brightgreen.svg)](https://drive.google.com/folderview?id=0B-r9NuHyXlh3fm1WREI1QkI5NWxXVXlxaXA0Tnpkb0dCNFQ3cTFqZ0tyX0FCd2VLS2JLVkk&usp=sharing)
[![Binaries](https://img.shields.io/badge/NephQ2-Windows%20(x86)-brightgreen.svg)](https://ci.appveyor.com/project/Nephatrine/nephq2/branch/master/artifacts)

Place the NephQ2 data files into your Quake II **baseq2** directory. You'll have to either build the binaries yourself or use the compiled 32-bit Windows binaries from AppVeyor. These have not been tested in most cases and do not support SteamVR. Place the binaries into your Quake II directory.

####Build Requirements

[![Build Status](https://ci.appveyor.com/api/projects/status/ga1l0v8hk0t5i6bj/branch/master?svg=true)](https://ci.appveyor.com/project/Nephatrine/nephq2/branch/master)

You'll need to download the [Oculus Rift SDK](https://developer.oculus.com/downloads/#version=pc-0.4.4-beta) and extract it into the **external/OculusSDK** directory inside your working directory. If you are on Linux, you will need to build the library with the Makefile included.

If you want SteamVR HMD support, you'll need to download the [Steamworks SDK](https://partner.steamgames.com/) and extract it into the **external/Steamworks** directory inside your working directory.

On Linux, you'll need to ensure the following packages are also installed:

- libglew-dev
- libminizip-dev
- libsdl2-dev

On Windows, precompiled binaries for these libraries built with MSVC 2013 (VS12) will be included.

If you are on a different platform, you may need to download and build these libraries yourself:

- [GLEW](http://glew.sourceforge.net/)
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [Zlib](http://www.zlib.net/)

####Acknowledgements

- [id Software](http://www.idsoftware.com/) for creating the original Quake II and releasing the source to the community.
- [Oculus VR](https://www.oculus.com/) for creating the Oculus Rift and reviving interest in virtual reality.
- [Knightmare](http://www.markshan.com/knightmare/) for his work on the KMQuake II engine.
- [Luke Groeninger](https://github.com/dghost) for his work on Quake II VR.
