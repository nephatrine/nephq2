#
# LibOVR Locations
#

set( OVR_SEARCH_PATHS
       ${CMAKE_SOURCE_DIR}/../LibOVR
       ${CMAKE_SOURCE_DIR}/../OculusSDK/LibOVR
       ~/Library/Frameworks
       /Library/Frameworks
       /usr
       /usr/local
       /opt
       /opt/csw
       /opt/local
       /sw )
set( OVR_SEARCH_PREFIXES
       lib
       lib64 )

#
# Precompiled Library Locations
#

if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
  if( CMAKE_SYSTEM_PROCESSOR MATCHES "i.86" )
    set( BUILD_ARCH "i386" )
  elseif( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
    set( BUILD_ARCH "x86_64" )
  endif()
  set( OVR_SEARCH_PREFIXES
         ${OVR_SEARCH_PREFIXES}
         Lib/Linux/Release/${BUILD_ARCH} )
endif()

#
# Find Paths
#

find_path( OVR_INCLUDE_DIR
  NAMES OVR.h
  HINTS $ENV{OVRDIR}
  PATH_SUFFIXES include/ Include/
  PATHS ${OVR_SEARCH_PATHS}
  DOC "LibOVR Include Directory" )
find_path( OVR_CAPI_INCLUDE_DIR
  NAMES OVR_CAPI.h
  HINTS $ENV{OVRDIR}
  PATH_SUFFIXES src/ Src/
  PATHS ${OVR_SEARCH_PATHS}
  DOC "LibOVR CAPI Include Directory" )
find_library( OVR_LIBRARY
  NAMES ovr
  HINTS $ENV{OVRDIR}
  PATH_SUFFIXES ${OVR_SEARCH_PREFIXES}
  PATHS ${OVR_SEARCH_PATHS}
  DOC "LibOVR Library" )

#
# Did we find it?
#

if( OVR_INCLUDE_DIR AND OVR_LIBRARY )
  set( OVR_FOUND TRUE )
  set( OVR_INCLUDE_DIRS ${OVR_INCLUDE_DIR} )
  if( OVR_CAPI_INCLUDE_DIR )
    list( APPEND OVR_INCLUDE_DIRS ${OVR_CAPI_INCLUDE_DIR} )
  endif()
  set( OVR_LIBRARIES ${OVR_LIBRARY} )
  if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    find_library( RT_LIBRARY NAMES rt )
    find_library( X11_LIBRARY NAMES X11 )
    find_library( XRANDR_LIBRARY NAMES Xrandr )
    find_package( Threads )
    list( APPEND OVR_LIBRARIES ${X11_LIBRARY} )
    list( APPEND OVR_LIBRARIES ${XRANDR_LIBRARY} )
    list( APPEND OVR_LIBRARIES ${RT_LIBRARY} )
    list( APPEND OVR_LIBRARIES ${CMAKE_THREAD_LIBS_INIT} )
  endif()
  if( NOT OVR_FIND_QUIETLY )
    message( STATUS "Found LibOVR: ${OVR_LIBRARIES}" )
  endif()
else()
  if( OVR_FIND_REQUIRED )
    message( FATAL_ERROR "LibOVR Not Found" )
  else()
    message( STATUS "LibOVR Not Found" )
  endif()
endif()
