#include "Utilities.h"

#include <iostream>

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
