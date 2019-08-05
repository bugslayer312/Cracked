// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include "06_StringCompression.h"

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
