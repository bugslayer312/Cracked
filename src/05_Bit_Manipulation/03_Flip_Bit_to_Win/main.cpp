#include <iostream>

typedef unsigned int uint;

uint HipotLongestSequence(uint num) {
    if (!num) {
        return 1;
    }
    uint resultLength = 0;
    uint prevLength = 0;
    uint curLength = 0;
    bool zeroFound = false;
    while (num) {
        if (num & 1u) {
            ++curLength;
        }
        else {
            if (zeroFound) {
                uint totalLength = curLength + prevLength + 1;
                if (totalLength > resultLength) {
                    resultLength = totalLength;
                }
            }
            else {
                zeroFound = true;
            }
            prevLength = curLength;
            curLength = 0;
        }
        num >>= 1;
    }
    if (zeroFound) {
        uint totalLength = curLength + prevLength + 1;
        if (totalLength > resultLength) {
            resultLength = totalLength;
        }
    }
    else {
        resultLength = curLength;
    }
    return resultLength;
}

int main() {

    uint num = 0b1111101111110111110111101111110;

    std::cout << HipotLongestSequence(num) << std::endl;
    return 0;
}
