#
# ZLIB Locations
#

set( ZLIB_SEARCH_PATHS
       ${CMAKE_SOURCE_DIR}/../Zlib
       ~/Library/Frameworks
       /Library/Frameworks
       /usr
       /usr/local
       /opt
       /opt/csw
       /opt/local
       /sw )
set( ZLIB_SEARCH_PREFIXES
       lib
       lib64 )

#
# Precompiled Library Locations
#

if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
  if( CMAKE_SIZEOF_VOID_P MATCHES 4 )
    set( BUILD_ARCH "x86" )
  elseif( CMAKE_SIZEOF_VOID_P MATCHES 8 )
    set( BUILD_ARCH "x64" )
  endif()
  set( ZLIB_SEARCH_PREFIXES
         ${ZLIB_SEARCH_PREFIXES}
         contrib/vstudio/vc12/${BUILD_ARCH}/ZlibStatRelease
         contrib/vstudio/vc12/${BUILD_ARCH}/ZlibStatReleaseWithoutAsm )
  add_definitions( -DZLIB_WINAPI )
endif()

#
# Find Paths
#

find_path( ZLIB_INCLUDE_DIR
  NAMES zlib.h
  HINTS $ENV{ZLIBDIR}
  PATH_SUFFIXES include/ Include/ contrib/ /
  PATHS ${ZLIB_SEARCH_PATHS}
  DOC "Zlib Include Directory" )
find_path( MINIZIP_INCLUDE_DIR
  NAMES minizip/unzip.h
  HINTS $ENV{ZLIBDIR}
  PATH_SUFFIXES include/ Include/ contrib/ /
  PATHS ${ZLIB_SEARCH_PATHS}
  DOC "MiniZip Include Directory" )
find_library( ZLIB_LIBRARY
  NAMES z zlib zlibstat
  HINTS $ENV{ZLIBDIR}
  PATH_SUFFIXES ${ZLIB_SEARCH_PREFIXES}
  PATHS ${ZLIB_SEARCH_PATHS}
  DOC "Zlib Library" )
find_library( MINIZIP_LIBRARY
  NAMES minizip
  HINTS $ENV{ZLIBDIR}
  PATH_SUFFIXES ${ZLIB_SEARCH_PREFIXES}
  PATHS ${ZLIB_SEARCH_PATHS}
  DOC "MiniZip Library" )

#
# Did we find it?
#

if( ZLIB_INCLUDE_DIR AND ZLIB_LIBRARY )
  set( ZLIB_FOUND TRUE )
  set( ZLIB_INCLUDE_DIRS ${ZLIB_INCLUDE_DIR} )
  if( MINIZIP_INCLUDE_DIR )
    list( APPEND ZLIB_INCLUDE_DIRS ${MINIZIP_INCLUDE_DIR} )
  endif()
  set( ZLIB_LIBRARIES ${ZLIB_LIBRARY} )
  if( MINIZIP_LIBRARY )
    list( APPEND ZLIB_LIBRARIES ${MINIZIP_LIBRARY} )
  endif()
  if( NOT ZLIB_FIND_QUIETLY )
    message( STATUS "Found Zlib: ${ZLIB_LIBRARIES}" )
  endif()
else()
  if( ZLIB_FIND_REQUIRED )
    message( FATAL_ERROR "Zlib Not Found" )
  else()
    message( STATUS "Zlib Not Found" )
  endif()
endif()
