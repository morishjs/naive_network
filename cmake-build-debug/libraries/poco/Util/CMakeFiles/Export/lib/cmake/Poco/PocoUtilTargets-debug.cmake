#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::Util" for configuration "Debug"
set_property(TARGET Poco::Util APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::Util PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libPocoUtild.60.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libPocoUtild.60.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::Util )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::Util "${_IMPORT_PREFIX}/lib/libPocoUtild.60.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
