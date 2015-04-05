#
# GLEW Locations
#

set( GLEW_SEARCH_PATHS
       ${CMAKE_SOURCE_DIR}/../GLEW
       ~/Library/Frameworks
       /Library/Frameworks
       /usr
       /usr/local
       /opt
       /opt/csw
       /opt/local
       /sw )
set( GLEW_SEARCH_PREFIXES
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
  set( GLEW_SEARCH_PREFIXES
         ${GLEW_SEARCH_PREFIXES}
         lib/Release/${BUILD_ARCH} )
endif()

#
# Find Paths
#

find_path( GLEW_INCLUDE_DIR
  NAMES GL/glew.h
  HINTS $ENV{GLEWDIR}
  PATH_SUFFIXES include/ Include/
  PATHS ${GLEW_SEARCH_PATHS}
  DOC "GLEW Include Directory" )
find_library( GLEW_LIBRARY
  NAMES glew GLEW glew32 glew32s
  HINTS $ENV{GLEWDIR}
  PATH_SUFFIXES ${GLEW_SEARCH_PREFIXES}
  PATHS ${GLEW_SEARCH_PATHS}
  DOC "GLEW Library" )

#
# Did we find it?
#

if( GLEW_INCLUDE_DIR AND GLEW_LIBRARY )
  set( GLEW_FOUND TRUE )
  set( GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR} )
  set( GLEW_LIBRARIES ${GLEW_LIBRARY} )
  if( NOT GLEW_FIND_QUIETLY )
    message( STATUS "Found GLEW: ${GLEW_LIBRARIES}" )
  endif()
else()
  if( GLEW_FIND_REQUIRED )
    message( FATAL_ERROR "GLEW Not Found" )
  else()
    message( STATUS "GLEW Not Found" )
  endif()
endif()
