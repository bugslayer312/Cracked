// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include "01_IsUnique.h"

#include <unordered_set>
#include <algorithm>

bool IsUnique(std::string const& s) {
    std::unordered_set<char> cache;
    for (char c : s) {
        if (cache.find(c) != cache.end()) {
            return false;
        }
        cache.insert(c);
    }
    return true;
}

bool IsUnique2(std::string const& s) {
    std::uint32_t cache[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (char c : s) {
        std::uint8_t pos = static_cast<std::uint8_t>(c);
        if (cache[pos/32] & (0x00000001 << (pos % 32))) {
            return false;
        }
        cache[pos/32] |= (0x00000001 << (pos % 32));
    }
    return true;
}

bool IsUnique3(std::string s) {
    if (s.empty()) {
        return true;
    }
    std::sort(s.begin(), s.end());
    for (size_t i=0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) {
            return false;
        }
    }
    return true;
}
