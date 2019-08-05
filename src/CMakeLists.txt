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

add_subdirectory(01_Arrays_and_Strings)
add_subdirectory(02_Linked_Lists)

add_subdirectory(03_Stacks_and_Queues/01_Three_in_One)
add_subdirectory(03_Stacks_and_Queues/02_Stack_Min)
add_subdirectory(03_Stacks_and_Queues/03_Stack_of_Plates)
add_subdirectory(03_Stacks_and_Queues/04_Queue_via_Stacks)
add_subdirectory(03_Stacks_and_Queues/05_Sort_Stack)
add_subdirectory(03_Stacks_and_Queues/06_Animal_Shelter)

add_subdirectory(04_Trees_and_Graphs/01_Route_Between_Nodes)
add_subdirectory(04_Trees_and_Graphs/02_Minimal_Tree)
add_subdirectory(04_Trees_and_Graphs/03_List_of_Depths)
add_subdirectory(04_Trees_and_Graphs/04_Check_Balanced)
add_subdirectory(04_Trees_and_Graphs/05_Validate_BST)
add_subdirectory(04_Trees_and_Graphs/06_Successor)
add_subdirectory(04_Trees_and_Graphs/07_Build_Order)
add_subdirectory(04_Trees_and_Graphs/08_First_Common_Ancestor)
add_subdirectory(04_Trees_and_Graphs/09_BST_Sequences)
add_subdirectory(04_Trees_and_Graphs/10_Check_Subtree)
add_subdirectory(04_Trees_and_Graphs/11_Random_Node)
add_subdirectory(04_Trees_and_Graphs/12_Paths_with_Sum)

add_subdirectory(05_Bit_Manipulation/01_Insertion)
add_subdirectory(05_Bit_Manipulation/02_Binary_to_String)
add_subdirectory(05_Bit_Manipulation/03_Flip_Bit_to_Win)
add_subdirectory(05_Bit_Manipulation/04_Next_Number)
add_subdirectory(05_Bit_Manipulation/05_Conversion)

add_subdirectory(Tests)
