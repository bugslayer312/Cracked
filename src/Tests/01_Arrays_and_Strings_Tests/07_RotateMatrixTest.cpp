#include <gtest/gtest.h>

#include "07_RotateMatrix.h"

Matrix CreateDefaultMatrix(size_t sz) {
    Matrix result;
    if (sz) {
        result.resize(sz);
        int c = 0;
        for (size_t i = 0; i < sz; ++i) {
            result[i].resize(sz);
            for (size_t j = 0; j < sz; ++j) {
                result[i][j] = ++c;
            }
        }
    }
    return result;
}

TEST(RotateMatrixSuite, Case1Dim0) {
    Matrix m = CreateDefaultMatrix(0);
    Matrix m1(m);
    for (int i = 0; i < 4; ++i) {
        RotateMatrix(m1, true);
        ASSERT_EQ(m1, m);
    }
}

TEST(RotateMatrixSuite, Case2Dim1) {
    Matrix m = CreateDefaultMatrix(1);
    Matrix m1(m);
    for (int i = 0; i < 4; ++i) {
        RotateMatrix(m1, true);
        ASSERT_EQ(m1, m);
    }
}

TEST(RotateMatrixSuite, Case3Dim2) {
    Matrix m = CreateDefaultMatrix(2);
    Matrix mcopy(m);
    Matrix mcv = {{3, 1}, {4, 2}};
    Matrix mccv = {{2, 4}, {1, 3}};
    RotateMatrix(m, true);
    EXPECT_EQ(m, mcv);
    RotateMatrix(m, false);
    EXPECT_EQ(m, mcopy);
    RotateMatrix(m, false);
    EXPECT_EQ(m, mccv);
}

TEST(RotateMatrixSuite, Case3RotateMultiple) {
    for (size_t dim = 2; dim <= 10; ++dim) {
        Matrix m = CreateDefaultMatrix(dim);
        Matrix mcopy(m);
        for (int i=1; i <= 12; ++i) {
            RotateMatrix(m, true);
            if (i % 4) {
                EXPECT_NE(m, mcopy);
            }
            else {
                EXPECT_EQ(m, mcopy);
            }
        }
        for (int i=1; i <= 12; ++i) {
            RotateMatrix(m, false);
            if (i % 4) {
                EXPECT_NE(m, mcopy);
            }
            else {
                EXPECT_EQ(m, mcopy);
            }
        }
    }
}

TEST(RotateMatrixSuite, Case3Dim3) {
    Matrix m = CreateDefaultMatrix(3);
    Matrix mcv = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    Matrix mccv = {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}};
    Matrix m2rot = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    RotateMatrix(m, true);
    EXPECT_EQ(m, mcv);
    RotateMatrix(m, true);
    EXPECT_EQ(m, m2rot);
    m = CreateDefaultMatrix(3);
    RotateMatrix(m, false);
    EXPECT_EQ(m, mccv);
}
