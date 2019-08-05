#include <gtest/gtest.h>

#include "08_ZeroMatrix.h"

TEST(ZeroMatrixSuite, Case1) {
    Matrix m = {{1, 0, 3}, {4, 5, 6}};
    Matrix mz = {{0, 0, 0}, {4, 0, 6}};
    ZeroMatrix(m);
    EXPECT_EQ(m, mz);
}

TEST(ZeroMatrixSuite, Case2) {
    Matrix m = {{0, 2, 3}, {0, 5, 6}, {7, 8, 9}, {10, 11, 0}};
    Matrix mz = {{0, 0, 0}, {0, 0, 0}, {0, 8, 0}, {0, 0, 0}};
    ZeroMatrix(m);
    EXPECT_EQ(m, mz);
}

TEST(ZeroMatrixSuite, Case3) {
    Matrix m = {{1,2,3,4}, {5,6,0,8}, {9,0,11,12}, {13,14,15,16}};
    Matrix mz = {{1,0,0,4}, {0,0,0,0}, {0,0,0,0}, {13,0,0,16}};
    ZeroMatrix(m);
    EXPECT_EQ(m, mz);
}
