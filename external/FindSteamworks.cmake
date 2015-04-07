#
# LibOVR Locations
#

set( STEAMWORKS_SEARCH_PATHS
       ${CMAKE_SOURCE_DIR}/../Steam
       ${CMAKE_SOURCE_DIR}/../Steamworks
       ~/Library/Frameworks
       /Library/Frameworks
       /usr
       /usr/local
       /opt
       /opt/csw
       /opt/local
       /sw )
set( STEAMWORKS_SEARCH_PREFIXES
       lib
       lib64 )

#
# Precompiled Library Locations
#

if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
  if( CMAKE_SYSTEM_PROCESSOR MATCHES "i.86" )
    set( BUILD_ARCH "linux32" )
  elseif( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
    set( BUILD_ARCH "linux64" )
  endif()
  set( STEAMWORKS_SEARCH_PREFIXES
         ${STEAMWORKS_SEARCH_PREFIXES}
         redistributable_bin/${BUILD_ARCH} )
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
  if( CMAKE_SIZEOF_VOID_P MATCHES 4 )
    set( BUILD_ARCH "" )
  elseif( CMAKE_SIZEOF_VOID_P MATCHES 8 )
    set( BUILD_ARCH "win64" )
  endif()
  set( STEAMWORKS_SEARCH_PREFIXES
         ${STEAMWORKS_SEARCH_PREFIXES}
         redistributable_bin/${BUILD_ARCH} )
endif()
       
#
# Find Paths
#

find_path( STEAMWORKS_INCLUDE_DIR
  NAMES steam/steam_api.h
  HINTS $ENV{SteamworksDIR}
  PATH_SUFFIXES public/ include/ Include/
  PATHS ${STEAMWORKS_SEARCH_PATHS}
  DOC "Steamworks Include Directory" )
find_library( STEAMWORKS_LIBRARY
  NAMES steam_api steam_api64
  HINTS $ENV{SteamworksDIR}
  PATH_SUFFIXES ${STEAMWORKS_SEARCH_PREFIXES}
  PATHS ${STEAMWORKS_SEARCH_PATHS}
  DOC "Steamworks Library" )

#
# Did we find it?
#

if( STEAMWORKS_INCLUDE_DIR AND STEAMWORKS_LIBRARY )
  set( STEAMWORKS_FOUND TRUE )
  set( STEAMWORKS_INCLUDE_DIRS ${STEAMWORKS_INCLUDE_DIR} )
  set( STEAMWORKS_LIBRARIES ${STEAMWORKS_LIBRARY} )
  if( NOT STEAMWORKS_FIND_QUIETLY )
    message( STATUS "Found SteamWorks: ${STEAMWORKS_LIBRARIES}" )
  endif()
else()
  if( STEAMWORKS_FIND_REQUIRED )
    message( FATAL_ERROR "SteamWorks Not Found" )
  else()
    message( STATUS "SteamWorks Not Found" )
  endif()
endif()
