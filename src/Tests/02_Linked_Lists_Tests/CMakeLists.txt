cmake_minimum_required(VERSION 3.10.0)

add_executable(02LinkedListsTests
    01_RemoveDupsTest.cpp
    02_ReturnKthToLastTest.cpp
    03_DeleteMiddleNodeTest.cpp
    04_PartitionTest.cpp
    05_SumListsTest.cpp
    06_PalindromeTest.cpp
    07_IntersectionTest.cpp
    08_LoopDetectionTest.cpp
)

target_link_libraries(02LinkedListsTests PUBLIC
    GTest::GTest
    GTest::Main
    02LinkedLists
)

gtest_add_tests(TARGET 02LinkedListsTests
	TEST_LIST 02LinkedLists-GTest)
