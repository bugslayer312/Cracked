#include "Utilities.h"
#include <iostream>

const uint InvalidPos = static_cast<uint>(-1);

uint GetNextWithSameNumberOfOnes(uint num) {
    uint bitLastOneBeforeZero = InvalidPos;
    for (uint copyOfNum = num, curBit = 0; copyOfNum; copyOfNum >>= 1, ++curBit) {
        if (copyOfNum & 1u) {
            bool leftIsZero = !((1u << (curBit+1u)) & num);
            if (leftIsZero) {
                bitLastOneBeforeZero = curBit;
                break;
            }
        }
    }
    if (bitLastOneBeforeZero == InvalidPos || bitLastOneBeforeZero == 31) {
        return num;
    }

    num &= ~(1u << bitLastOneBeforeZero);
    num |= 1u << (bitLastOneBeforeZero + 1u);
    return num;
}

uint GetPrevWithSameNumberOfOnes(uint num) {
    uint bitLastOne = InvalidPos;
    for (uint copyOfNum = num, curBit = 0; copyOfNum; copyOfNum >>= 1, ++curBit) {
        if (curBit && copyOfNum & 1u) {
            bool const rightIsZero = !((1u << (curBit-1u)) & num);
            if (rightIsZero) {
                bitLastOne = curBit;
                break;
            }
        }
    }
    if (bitLastOne != InvalidPos) {
        num &= ~(1u << bitLastOne);
        num |= 1u << (bitLastOne - 1u);
    }
    return num;
}

int main(){
    uint num = 0b10111;
    std::cout << to_binary(num) << std::endl;
    std::cout << to_binary(GetPrevWithSameNumberOfOnes(num)) << std::endl;
    std::cout << to_binary(GetNextWithSameNumberOfOnes(num)) << std::endl;
}
