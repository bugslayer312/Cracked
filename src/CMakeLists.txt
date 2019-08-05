cmake_minimum_required(VERSION 3.10.0)
project(Cracking VERSION 0.1 LANGUAGES CXX)


set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
if (NOT BUILD_TYPE)
    set(BUILD_TYPE "Default")
endif()

set(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/../output/${BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT}/lib")

set(CMAKE_CXX_FLAGS "--std=c++14 ${CMAKE_CXX_FLAGS}")

include_directories(include)

enable_testing()
include(CTest)
find_package(GTest REQUIRED)

add_subdirectory(Utilities)

#with tests
add_subdirectory(01_Arrays_and_Strings)
add_subdirectory(02_Linked_Lists)
add_subdirectory(Tests)

#without tests
add_subdirectory(03_Stacks_and_Queues)
add_subdirectory(04_Trees_and_Graphs)
add_subdirectory(05_Bit_Manipulation)
