#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::Zip" for configuration "Debug"
set_property(TARGET Poco::Zip APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::Zip PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libPocoZipd.60.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libPocoZipd.60.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::Zip )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::Zip "${_IMPORT_PREFIX}/lib/libPocoZipd.60.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
