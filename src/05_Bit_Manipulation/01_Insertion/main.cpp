#include "Utilities.h"

#include <iostream>

/*
struct to_binary {
    uint m_num;
    to_binary(uint num) : m_num(num) {}
};

typedef unsigned int uint;

std::ostream& operator<<(std::ostream& os, to_binary const& tb) {
    os << "0b";
    bool found1 = false;
    uint n = 1u << std::numeric_limits<uint>::digits-1;
    while (n) {
        if (n & tb.m_num) {
            found1 = true;
            os << '1';
        } else {
            if (found1) {
                os << '0';
            }
        }
        n >>= 1;
    }
    if (!found1) {
        os << '0';
    }
    return os;
} */

uint InsertBits(uint dest, uint src, uint start, uint end) {
    uint mask = ~(((1 << (end - start + 1u))-1u) << start);
    // std::cout << to_binary(mask) << std::endl;
    return (dest & mask) | (src << start);
}

int main() {
    uint n = 0b10000000000;
    uint m = 0b10011;
    uint i = 2;
    uint j = 6;
    std::cout << to_binary(InsertBits(n, m, i, j)) << std::endl;
    return 0;
}
