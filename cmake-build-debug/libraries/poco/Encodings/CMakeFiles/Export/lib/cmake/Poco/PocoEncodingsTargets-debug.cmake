#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::Encodings" for configuration "Debug"
set_property(TARGET Poco::Encodings APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::Encodings PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libPocoEncodingsd.60.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libPocoEncodingsd.60.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::Encodings )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::Encodings "${_IMPORT_PREFIX}/lib/libPocoEncodingsd.60.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
