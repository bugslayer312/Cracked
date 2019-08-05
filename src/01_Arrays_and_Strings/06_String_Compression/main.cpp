#include <iostream>
#include <string>
#include <sstream>
#include <vector>

size_t CalcCompressedSize(std::string const& s) {
    size_t result = 0;
    if (s.empty()) {
        return result;
    }
    char cur = s[0];
    int count = 0;
    for (char c : s) {
        if (c == cur) {
            ++count;
        }
        else {
            result += 1 + std::to_string(count).size();
            cur = c;
            count = 1;
        }
    }
    return result + 1 + std::to_string(count).size();
}

std::string Compress(std::string const& s) {
    size_t compSize = CalcCompressedSize(s);
    if (s.size() <= compSize) {
        return s;
    }

    std::string result;
    result.reserve(compSize);
    char cur = s[0];
    int count = 0;
    for (char c : s) {
        if (c == cur) {
            ++count;
        }
        else {
            result.append(std::string(1, cur)).append(std::to_string(count));
            cur = c;
            count = 1;
        }
    }
    result.append(std::string(1, cur)).append(std::to_string(count));
    return result;
}

int main() {
    std::vector<std::string> in = {"aabcccccaaa", "abcdd", "aaaaaaaaa", "abbccc"};
    std::vector<std::string> out = {"a2b1c5a3", "abcdd", "a9", "abbccc"};
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (Compress(in[i]) == out[i]) << std::endl;
    }
    return 0;
}
