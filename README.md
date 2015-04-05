###NephQ2

This is my fork of [Quake II VR](https://github.com/q2vr/Quake2VR/), an Oculus Rift-enabled Quake II engine based on the [KMQuake II](http://www.markshan.com/knightmare/) engine and inspired by [RiftQuake](https://github.com/phoboslab/Quakespasm-Rift).

####Features

- Gamepad Support
- Oculus Rift Support (0.4.4-beta)
- OpenAL HRTF Support
- SteamVR Support

####Play Requirements

- [Quake II (Game Assets)](http://store.steampowered.com/app/2320/)
- [Oculus Rift DK2](https://www.oculus.com/dk2/)

####Build Requirements

You'll need to download the [Oculus Rift SDK](https://developer.oculus.com/downloads/#version=pc-0.4.4-beta) and extract it into the **external/OculusSDK** directory inside your working directory.

If you want SteamVR HMD support, you'll need to download the [Steamworks SDK](https://partner.steamgames.com/) and extract it into the **external/Steamworks** directory inside your working directory.

On Linux, you'll need to ensure the following packages are also installed:

- libglew-dev
- libsdl2-dev

On Windows, precompiled binaries for these libraries built with MSVC 2013 (VS12) will be included.

If you are on a different platform, you may need to download and build these libraries yourself:

- [GLEW](http://glew.sourceforge.net/)
- [SDL2](https://www.libsdl.org/download-2.0.php)

####Acknowledgements

- [id Software](http://www.idsoftware.com/) for creating the original Quake II and releasing the source to the community.
- [Oculus VR](https://www.oculus.com/) for creating the Oculus Rift and reviving interest in virtual reality.
- [Knightmare](http://www.markshan.com/knightmare/) for his work on the KMQuake II engine.
- [Luke Groeninger](https://github.com/dghost) for his work on Quake2VR.
