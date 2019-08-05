#include <gtest/gtest.h>

#include "02_ReturnTthToLast.h"

class ReturnKthToLastSuite : public testing::Test {
protected:
    void SetUp() override {
        l = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    }

    NodePtr l;
};

TEST_F(ReturnKthToLastSuite, Ver1Case1) {
    auto res = ReturnKthToLast(l, 5);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 10);
}

TEST_F(ReturnKthToLastSuite, Ver2Case1) {
    auto res = ReturnKthToLast2(l, 5);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 10);
}

TEST_F(ReturnKthToLastSuite, Ver3Case1) {
    auto res = ReturnKthToLast3(l, 5);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 10);
}

TEST_F(ReturnKthToLastSuite, Ver1Case2) {
    auto res = ReturnKthToLast(l, 9);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 4);
}

TEST_F(ReturnKthToLastSuite, Ver2Case2) {
    auto res = ReturnKthToLast2(l, 9);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 4);
}

TEST_F(ReturnKthToLastSuite, Ver3Case2) {
    auto res = ReturnKthToLast3(l, 9);
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->Data, 4);
}

TEST_F(ReturnKthToLastSuite, Ver1Case3) {
    auto res = ReturnKthToLast(l, 10);
    ASSERT_EQ(res, nullptr) << "must be null (not found)";
}

TEST_F(ReturnKthToLastSuite, Ver2Case3) {
    auto res = ReturnKthToLast2(l, 10);
    ASSERT_EQ(res, nullptr) << "must be null (not found)";
}

TEST_F(ReturnKthToLastSuite, Ver3Case3) {
    auto res = ReturnKthToLast3(l, 10);
    ASSERT_EQ(res, nullptr) << "must be null (not found)";
}

/*
int main() {
    NodePtr l = ListNode::Create({4, 1, 0, 5, 10, 2, 1, 1, 0});
    auto res = ReturnKthToLast(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    std::cout << "----\n";
    res = ReturnKthToLast2(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast2(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast2(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    std::cout << "----\n";
    res = ReturnKthToLast3(l, 5);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast3(l, 9);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    res = ReturnKthToLast3(l, 10);
    std::cout << (res.second ? std::to_string(res.first) : "Not found") << std::endl;
    return 0;
}
*/
