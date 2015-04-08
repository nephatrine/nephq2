###NephQ2

[![Build status](https://ci.appveyor.com/api/projects/status/ga1l0v8hk0t5i6bj/branch/master?svg=true)](https://ci.appveyor.com/project/Nephatrine/nephq2/branch/master)

This is my fork of [Quake II VR](https://github.com/q2vr/Quake2VR/), an Oculus Rift-enabled Quake II engine based on the [KMQuake II](http://www.markshan.com/knightmare/) engine and inspired by [RiftQuake](https://github.com/phoboslab/Quakespasm-Rift).

####Features

- Gamepad Support
- Oculus Rift Support (0.4.4-beta)
- OpenAL HRTF Support
- SteamVR Support

####Issues

- Linux binaries build, but segfault on initialization. Could be because I'm testing on a Linux VM without any HMD attached or maybe I just screwed up somewhere. GDB hangs the entire VM so I can't debug.
- Linker errors trying to build with MinGW on Windows. I probably need to build all the deps with MinGW instead of linking the MSVC ones, but that's too much work. Use VS Express Edition if you're on Windows.

####Play Requirements

Requirements:
- [Quake II (Game Assets)](http://store.steampowered.com/app/2320/)
- [Oculus Rift DK2](https://www.oculus.com/dk2/)

You can download the required data files from [Google Drive](https://drive.google.com/folderview?id=0B-r9NuHyXlh3fm1WREI1QkI5NWxXVXlxaXA0Tnpkb0dCNFQ3cTFqZ0tyX0FCd2VLS2JLVkk&usp=sharing). These will need to be put into your Quake II directory along with NephQ2 binaries. I probably will not be putting up precompiled binaries as this is still a fast-moving project and hasn't really reached a milestone yet. You can, however, download the latest unsupported 32-bit Windows binaries from my [AppVeyor](https://ci.appveyor.com/project/Nephatrine/nephq2/branch/master/artifacts), though these have not been tested in most cases. The automated builds are also lacking SteamVR support.

####Build Requirements

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
