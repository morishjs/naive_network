#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::Net" for configuration "Debug"
set_property(TARGET Poco::Net APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::Net PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libPocoNetd.60.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libPocoNetd.60.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::Net )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::Net "${_IMPORT_PREFIX}/lib/libPocoNetd.60.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
