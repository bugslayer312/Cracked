cmake_minimum_required(VERSION 3.10.0)

add_executable(01ArraysAndStringsTests
    01_IsUniqueTest.cpp
    02_CheckPermutationTest.cpp
    04_PalindromePermutationTest.cpp
    05_OneWayTest.cpp
    06_StringCompressionTest.cpp
    07_RotateMatrixTest.cpp
    08_ZeroMatrixTest.cpp
    09_StringRotationTest.cpp
)

target_link_libraries(01ArraysAndStringsTests PUBLIC
	GTest::GTest
        GTest::Main
        01ArraysAndStrings
)

gtest_add_tests(TARGET 01ArraysAndStringsTests
                TEST_LIST 01ArraysAndStrings-GTest)

# target_include_directories(Tests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/01_Arrays_and_Strings")

#add_test(
#        NAME Tests
#       COMMAND --help
#)

