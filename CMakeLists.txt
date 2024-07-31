cmake_minimum_required(VERSION 3.28)
project(loki_testbed)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_LINKER_TYPE LLD)

if (NOT loki_DIR)
  message(FATAL_ERROR "You have to set loki_DIR!")
endif ()

add_subdirectory(${loki_DIR} "${CMAKE_CURRENT_BINARY_DIR}/loki")

# create dll
add_library(loki_testbed MODULE)
target_sources(loki_testbed PRIVATE
  sources/ModuleEntry.cpp
  sources/CharacterControllerComponent.hpp
  sources/CharacterControllerComponent.cpp)
target_link_libraries(loki_testbed PRIVATE loki::loki)

# copy data
add_custom_target(copy_data ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_CURRENT_SOURCE_DIR}/data"
  "${CMAKE_CURRENT_BINARY_DIR}/loki/src/loki-runtime/data"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/data")
add_dependencies(loki_runtime copy_data)

# copy code
add_custom_target(copy_code ALL
  COMMAND ${CMAKE_COMMAND} -E copy
  "${CMAKE_CURRENT_BINARY_DIR}/libloki_testbed.dll" # fixme
  "${CMAKE_CURRENT_BINARY_DIR}/loki/src/loki-runtime/loki_testbed.dll")
add_dependencies(copy_code loki_testbed)
add_dependencies(loki_runtime copy_code)