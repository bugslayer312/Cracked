#include <gtest/gtest.h>

#include "09_StringRotation.h"

TEST(StringRotation, Case1) {
    EXPECT_TRUE(isRotation("erbottlewat", "waterbottle"));
}

TEST(StringRotation, Case2) {
    EXPECT_TRUE(isRotation("qwerty", "yqwert"));
}

TEST(StringRotation, Case3) {
    EXPECT_FALSE(isRotation("abc", "cba"));
}

TEST(StringRotation, Case4Empty) {
    EXPECT_TRUE(isRotation("", ""));
}
