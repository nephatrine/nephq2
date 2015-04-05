cmake_minimum_required( VERSION 2.8 )

#
# Project
#

project( NephQ2 )
set( NEPHQ2_VERSION_MAJOR 1 )
set( NEPHQ2_VERSION_MINOR 0 )

if( DEFINED CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} )
else()
  set( CMAKE_BUILD_TYPE Release )
endif()

set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR} )
set( LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR} )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/external/" )

if( CMAKE_SIZEOF_VOID_P MATCHES 4 )
  set( ARCH_NAME "x86" )
elseif( CMAKE_SIZEOF_VOID_P MATCHES 8 )
  set( ARCH_NAME "x86-64" )
endif()
set( CMAKE_EXECUTABLE_SUFFIX "_${ARCH_NAME}" )
set( CMAKE_DEBUG_POSTFIX "_d" )

#
# Required Packages
#

if( NOT DEFINED ENV{GLEWDIR} )
  set( ENV{GLEWDIR} ${CMAKE_CURRENT_SOURCE_DIR}/external/GLEW/ )
endif()
if( NOT DEFINED ENV{SDL2DIR} )
  set( ENV{SDL2DIR} ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2/ )
endif()
if( NOT DEFINED ENV{ZLIBDIR} )
  set( ENV{ZLIBDIR} ${CMAKE_CURRENT_SOURCE_DIR}/external/Zlib/ )
endif()

include( CheckLibraryExists )
find_package( GLEW REQUIRED )
find_package( OpenGL REQUIRED )
find_package( SDL2 REQUIRED )
find_package( ZLIB REQUIRED )
include_directories( ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIRS} )

#
# Source Files
#

set( COMMON_HEADERS
       qcommon/crc.h
       qcommon/glob.h
       qcommon/qcommon.h
       qcommon/qfiles.h
       qcommon/shared/game.h
       qcommon/shared/q_shared.h
       qcommon/vid_modes.h
       qcommon/wildcard.h )
set( COMMON_SOURCES 
       qcommon/cmd.c
       qcommon/cmodel.c
       qcommon/common.c
       qcommon/crc.c
       qcommon/cvar.c
       qcommon/files.c
       qcommon/glob.c
       qcommon/hash.c
       qcommon/md4.c
       qcommon/net_chan.c
       qcommon/pmove.c
       qcommon/shared/m_flash.c
       qcommon/shared/q_shared.c
       qcommon/stable.c
       qcommon/wildcard.c
       qcommon/murmur3/murmur3.c )

set( CLIENT_HEADERS
       client/adivtab.h
       client/anorms.h
       client/cinematic.h
       client/client.h
       client/console.h
       client/input.h
       client/keys.h
       client/particles.h
       client/q2palette.h
       client/ref.h
       client/renderer/include/anorms.h
       client/renderer/include/anormtab.h
       client/renderer/include/qgl.h
       client/renderer/include/r_alias.h
       client/renderer/include/r_cin.h
       client/renderer/include/r_local.h
       client/renderer/include/r_model.h
       client/renderer/include/r_normals.h
       client/renderer/include/r_stereo.h
       client/renderer/include/r_vr_ovr.h
       client/renderer/include/r_vr_svr.h
       client/renderer/include/r_vr.h
       client/renderer/include/vlights.h
       client/renderer/include/warpsin.h
       client/screen.h
       client/sound/include/AL/al.h
       client/sound/include/AL/alc.h
       client/sound/include/AL/alconflict.h
       client/sound/include/AL/alext.h
       client/sound/include/AL/alunconflict.h
       client/sound/include/AL/efx-creative.h
       client/sound/include/AL/efx-presets.h
       client/sound/include/AL/efx.h
       client/sound/include/alConfigMob.h
       client/sound/include/alConfigMobDefs_inl.h
       client/sound/include/local.h
       client/sound/include/qal.h
       client/sound/include/sound.h
       client/sound/include/vorbis.h
       client/ui/include/ui_local.h
       client/vid.h
       client/vr/include/vr_ovr.h
       client/vr/include/vr_steamvr.h
       client/vr/include/vr_svr.h
       client/vr/include/vr.h )
set( CLIENT_UI_SOURCES
       client/ui/ui_backend.c
       client/ui/ui_game_credits.c
       client/ui/ui_game_saveload.c
       client/ui/ui_game.c
       client/ui/ui_main.c
       client/ui/ui_mp_addressbook.c
       client/ui/ui_mp_dmoptions.c
       client/ui/ui_mp_download.c
       client/ui/ui_mp_joinserver.c
       client/ui/ui_mp_playersetup.c
       client/ui/ui_mp_startserver.c
       client/ui/ui_multiplayer.c
       client/ui/ui_options_controls.c
       client/ui/ui_options_effects.c
       client/ui/ui_options_interface.c
       client/ui/ui_options_keys.c
       client/ui/ui_options_screen.c
       client/ui/ui_options_sound.c
       client/ui/ui_options_vr_advanced.c
       client/ui/ui_options_vr_ovr.c
       client/ui/ui_options_vr_svr.c
       client/ui/ui_options_vr.c
       client/ui/ui_options.c
       client/ui/ui_quit.c
       client/ui/ui_subsystem.c
       client/ui/ui_video_advanced.c
       client/ui/ui_video.c )
set( CLIENT_SOUND_SOURCES
       client/sound/ogg.c
       client/sound/openal.c
       client/sound/qal.c
       client/sound/sound.c
       client/sound/wave.c )
set( CLIENT_RENDERER_SOURCES
       client/renderer/r_alias_md2.c
       client/renderer/r_alias_misc.c
       client/renderer/r_alias.c
       client/renderer/r_antialias.c
       client/renderer/r_backend.c
       client/renderer/r_beam.c
       client/renderer/r_draw.c
       client/renderer/r_entity.c
       client/renderer/r_fbo.c
       client/renderer/r_fog.c
       client/renderer/r_fragment.c
       client/renderer/r_glstate.c
       client/renderer/r_image.c
       client/renderer/r_light.c
       client/renderer/r_main.c
       client/renderer/r_misc.c
       client/renderer/r_model.c
       client/renderer/r_particle.c
       client/renderer/r_postprocess.c
       client/renderer/r_shaderobjects.c
       client/renderer/r_sky.c
       client/renderer/r_sprite.c
       client/renderer/r_stereo.c
       client/renderer/r_surface.c
       client/renderer/r_vao.c
       client/renderer/r_vbo.c
       client/renderer/r_vlights.c
       client/renderer/r_vr_ovr.c
       client/renderer/r_vr_svr.c
       client/renderer/r_vr.c
       client/renderer/r_warp.c )
set( CLIENT_VR_SOURCES
       client/vr/vr_main.c
       client/vr/vr_ovr.c
       client/vr/vr_steamvr.cpp
       client/vr/vr_svr.c )
set( CLIENT_BASE_SOURCES
       client/cl_cin.c
       client/cl_cinematic.c
       client/cl_console.c
       client/cl_download.c
       client/cl_effects.c
       client/cl_ents.c
       client/cl_event.c
       client/cl_input.c
       client/cl_inv.c
       client/cl_keys.c
       client/cl_lights.c
       client/cl_main.c
       client/cl_parse.c
       client/cl_particle.c
       client/cl_pred.c
       client/cl_screen.c
       client/cl_string.c
       client/cl_tempent.c
       client/cl_utils.c
       client/cl_view.c )

set( SERVER_HEADERS
       server/server.h )
set( SERVER_SOURCES 
       server/sv_ccmds.c
       server/sv_ents.c
       server/sv_game.c
       server/sv_init.c
       server/sv_main.c
       server/sv_send.c
       server/sv_user.c
       server/sv_world.c )

set( BACKEND_HEADERS
       backends/sdl2/in_sdlcont.h
       backends/sdl2/sdl2quake.h )
set( BACKEND_SOURCES
       backends/sdl2/gl_sdl2.c
       backends/sdl2/in_sdl2.c
       backends/sdl2/in_sdlcont.c
       backends/sdl2/snd_sdl2.c
       backends/sdl2/sys_sdl2.c
       backends/sdl2/vid_sdl2.c )
if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
  set( BACKEND_SOURCES
         ${BACKEND_SOURCES}
         backends/unix/net_udp.c
         backends/unix/qsh_unix.c )
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
  set( BACKEND_HEADERS
         ${BACKEND_HEADERS}
         backends/win32/conproc.h )
  set( BACKEND_SOURCES
         ${BACKEND_SOURCES}
         backends/win32/conproc.c
         backends/win32/net_wins.c
         backends/win32/q_shwin.c )
endif()
if( MSVC )
  set( BACKEND_HEADERS
         ${BACKEND_HEADERS}
         backends/win32/resource.h )
  set( BACKEND_SOURCES
         ${BACKEND_SOURCES}
         backends/win32/q2.rc )
endif()

#
# Option: Dynamically Load LibOVR
#

option( OVR_DYNAMIC       "Dynamically Load LibOVR" OFF )
if( NOT OVR_DYNAMIC )
  if( NOT DEFINED ENV{OVRDIR} )
    set( ENV{OVRDIR} ${CMAKE_CURRENT_SOURCE_DIR}/external/OculusSDK/LibOVR/ )
  endif()
  find_package( OVR )
  if( OVR_FOUND )
    include_directories( ${OVR_INCLUDE_DIRS} )
  else()
    set( OVR_DYNAMIC ON )
  endif()
endif()
if( OVR_DYNAMIC )
  add_definitions(-DOCULUS_DYNAMIC)
  set( CLIENT_VR_SOURCES
         ${CLIENT_VR_SOURCES}
         client/vr/oculus_dynamic/oculus_dynamic.c )
  set( CLIENT_HEADERS
         ${CLIENT_HEADERS}
         client/vr/oculus_dynamic/oculus_dynamic.h
         client/vr/oculus_dynamic/ovr_dynamic_funcs.h )  
endif()

#
# Option: OpenAL Support
#

option( SUPPORT_OPENAL    "Build OpenAL Support" ON )
if( SUPPORT_OPENAL )
  add_definitions( -DUSE_OPENAL )
endif()

#
# Option: SteamVR Support
#

option( SUPPORT_STEAMVR   "Build SteamVR Support" ON )
if( SUPPORT_STEAMVR )
  if( NOT DEFINED ENV{SteamworksDIR} )
    set( ENV{SteamworksDIR} ${CMAKE_CURRENT_SOURCE_DIR}/external/Steamworks/ )
  endif()
  find_package( Steamworks )
  # Sorry mingw, but the steamworks headers are very dumb and assume WIN32 == MSVC.
  if( STEAMWORKS_FOUND AND NOT MINGW )
    if( CMAKE_COMPILER_IS_GNUCC )
      add_definitions( -DCOMPILER_GCC )
    endif()
    include_directories( ${STEAMWORKS_INCLUDE_DIRS} )
  else()
    set( SUPPORT_STEAMVR OFF )
  endif()
endif()
if( NOT SUPPORT_STEAMVR )
  add_definitions( -DNO_STEAM )
endif()

#
# Group Source Code
#

set( CLIENT_SOURCES
       ${CLIENT_BASE_SOURCES}
       ${CLIENT_RENDERER_SOURCES}
       ${CLIENT_SOUND_SOURCES}
       ${CLIENT_UI_SOURCES}
       ${CLIENT_VR_SOURCES} )
set( CLIENT_BASE
       ${COMMON_SOURCES}
       ${SERVER_SOURCES}
       ${CLIENT_SOURCES}
       ${COMMON_HEADERS}
       ${SERVER_HEADERS}
       ${CLIENT_HEADERS} )
set( BACKEND
       ${BACKEND_SOURCES}
       ${BACKEND_HEADERS} )

source_group( "Common" FILES ${COMMON_SOURCES} )
source_group( "Common\\Headers" FILES ${COMMON_HEADERS} )
source_group( "Client" FILES ${CLIENT_BASE_SOURCES} )
source_group( "Client\\Renderer" FILES ${CLIENT_RENDERER_SOURCES} )
source_group( "Client\\Sound" FILES ${CLIENT_SOUND_SOURCES} )
source_group( "Client\\UI" FILES ${CLIENT_UI_SOURCES} )
source_group( "Client\\VR" FILES ${CLIENT_VR_SOURCES} )
source_group( "Client\\Headers" FILES ${CLIENT_HEADERS} )
source_group( "Server" FILES ${SERVER_SOURCES} )
source_group( "Server\\Headers" FILES ${SERVER_HEADERS} )
source_group( "Backend" FILES ${BACKEND_SOURCES} )
source_group( "Backend\\Headers" FILES ${BACKEND_HEADERS} )

#
# Build Engine
#

add_executable( Engine ${CLIENT_BASE} ${BACKEND} )
target_link_libraries( Engine
                         ${SDL2_LIBRARIES}
                         ${OPENGL_gl_LIBRARY}
                         ${OPENGL_glu_LIBRARY}
                         ${GLEW_LIBRARIES}
                         ${ZLIB_LIBRARIES} )
if( NOT OVR_DYNAMIC )
  message( STATUS "Building with Oculus Rift support..." )
  target_link_libraries( Engine ${OVR_LIBRARIES} )
endif()
if( SUPPORT_STEAMVR )
  message( STATUS "Building with SteamVR support..." )
  target_link_libraries( Engine ${STEAMWORKS_LIBRARIES} )
endif()
if( HAS_VISIBILITY_HIDDEN )
  target_compile_options( Engine PRIVATE -fvisibility=hidden )
endif()
if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
  add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()
if( MSVC )
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:\"LIBCMT\" /NODEFAULTLIB:\"MSVCRT\"" )
  else()
    set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:\"LIBCMT\" /NODEFAULTLIB:\"LIBC\"" )
  endif()
endif()

#
# Build Game Module
#

add_subdirectory( game )
