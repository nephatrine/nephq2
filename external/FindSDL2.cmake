#
# SDL2 Locations
#

set( SDL2_SEARCH_PATHS
       ${CMAKE_SOURCE_DIR}/../SDL2
       ~/Library/Frameworks
       /Library/Frameworks
       /usr
       /usr/local
       /opt
       /opt/csw
       /opt/local
       /sw )
set( SDL2_SEARCH_PREFIXES
       lib
       lib64 )

#
# Precompiled Library Locations
#

if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
  if( CMAKE_SIZEOF_VOID_P MATCHES 4 )
    set( BUILD_ARCH "Win32" )
  elseif( CMAKE_SIZEOF_VOID_P MATCHES 8 )
    set( BUILD_ARCH "x64" )
  endif()
  set( SDL2_SEARCH_PREFIXES
         ${SDL2_SEARCH_PREFIXES}
         VisualC/SDL/${BUILD_ARCH}/Release
         VisualC/SDLmain/${BUILD_ARCH}/Release )
endif()

#
# Find Paths
#

find_path( SDL2_INCLUDE_DIR
  NAMES SDL.h
  HINTS $ENV{SDL2DIR}
  PATH_SUFFIXES include/SDL2 include
  PATHS ${SDL2_SEARCH_PATHS}
  DOC "SDL2 Include Directory" )
find_library( SDL2_LIBRARY
  NAMES SDL2
  HINTS $ENV{SDL2DIR}
  PATH_SUFFIXES ${SDL2_SEARCH_PREFIXES}
  PATHS ${SDL2_SEARCH_PATHS}
  DOC "SDL2 Library" )

#
# SDL2_MAIN
#

if( NOT SDL2_BUILDING_LIBRARY )
  if(NOT ${SDL2_INCLUDE_DIR} MATCHES ".framework")
    find_library( SDL2_MAIN_LIBRARY
      NAMES SDL2main
      HINTS $ENV{SDL2DIR}
      PATH_SUFFIXES ${SDL2_SEARCH_PREFIXES}
      PATHS ${SDL2_SEARCH_PATHS}
      DOC "SDL2main Library" )
  endif()
endif()

#
# Did we find it?
#

if( SDL2_INCLUDE_DIR AND SDL2_LIBRARY )
  set( SDL2_FOUND TRUE )
  set( SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR} )
  set( SDL2_LIBRARIES ${SDL2_LIBRARY} )
  if( SDL2_MAIN_LIBRARY )
    list( APPEND SDL2_LIBRARIES ${SDL2_MAIN_LIBRARY} )
  endif()
  if( NOT SDL2_FIND_QUIETLY )
    message( STATUS "Found SDL2: ${SDL2_LIBRARIES}" )
  endif()
else()
  if( SDL2_FIND_REQUIRED )
    message( FATAL_ERROR "SDL2 Not Found" )
  else()
    message( STATUS "SDL2 Not Found" )
  endif()
endif()
