cmake_minimum_required(VERSION 3.15)

if(POLICY CMP0065)
  # do not export symbols from executables
  # affects compiler checks in project(), so must be set before it
  cmake_policy(SET CMP0065 NEW)
endif()

project(tdjson VERSION 0.1.0 LANGUAGES CXX C)

if(NOT DEFINED CMAKE_MODULE_PATH)
  set(CMAKE_MODULE_PATH "")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" "${CMAKE_MODULE_PATH}")

if(POLICY CMP0054)
  # do not expand quoted arguments
  cmake_policy(SET CMP0054 NEW)
endif()

if(POLICY CMP0074)
  # use environment variables to find libraries
  cmake_policy(SET CMP0074 NEW)
endif()

include(PreventInSourceBuild)
prevent_in_source_build()

find_package(Td REQUIRED)

if (CMAKE_VERSION VERSION_LESS 3.18)
    set(DEV_MODULE Development)
else()
    set(DEV_MODULE Development.Module)
endif()

find_package(Python COMPONENTS Interpreter ${DEV_MODULE} REQUIRED OPTIONAL_COMPONENTS Development.SABIModule)
find_package(nanobind CONFIG REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

nanobind_add_module(tdjson_ext STABLE_ABI FREE_THREADED NOMINSIZE LTO tdjson/tdjson.cpp)
nanobind_add_stub(
  tdjson_ext_stub
  MODULE tdjson_ext
  OUTPUT tdjson_ext.pyi
  MARKER_FILE py.typed
  PYTHON_PATH $<TARGET_FILE_DIR:tdjson_ext>
  DEPENDS tdjson_ext
)

target_link_libraries(tdjson_ext PRIVATE Td::TdJson)

# install(TARGETS tdjson_ext LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/tdjson)
install(TARGETS tdjson_ext LIBRARY DESTINATION tdjson)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/tdjson_ext.pyi
    ${CMAKE_CURRENT_BINARY_DIR}/py.typed
    DESTINATION tdjson
)
