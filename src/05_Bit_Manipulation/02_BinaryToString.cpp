#include <iostream>
#include <limits>
#include <cmath>

std::string BinaryToString(float v){
    float const eps = std::numeric_limits<float>::epsilon();
    std::string result = "0.";
    float factor = 0.5f;
    do {
        if (factor <= v) {
            v -= factor;
            result.append("1");
        }
        else {
            result.append("0");
        }
        factor /= 2;
        if (result.length() > 32) {
            return "ERROR";
        }
    } while (v > eps);
    return result;
}

std::string BinaryToString2(float v){
    float const eps = std::numeric_limits<float>::epsilon();
    std::string result = "0.";
    while (std::abs(v) >= eps) {
        v *= 2;
        if (v >= 1) {
            result.append("1");
            v -= 1;
        }
        else {
            result.append("0");
        }
        if (result.length() > 32) {
            return "ERROR";
        }
    }
    return result;
}

int main() {
    float a = 0.72f;
    // std::cin >> a;
    std::cout << BinaryToString(a) << std::endl;
    std::cout << BinaryToString2(a) << std::endl;
    return 0;
}
