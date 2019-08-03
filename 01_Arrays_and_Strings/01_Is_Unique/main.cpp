#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

// IsUnique

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
    std::sort(s.begin(), s.end());
    for (size_t i=0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> in = {"qweqrty", "uirewoer", "awsedril"};
    std::vector<bool> out = {false, false, true};
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (IsUnique(in[i]) == out[i]) << std::endl;
    }
    std::cout << "----\n";
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (IsUnique2(in[i]) == out[i]) << std::endl;
    }
    std::cout << "----\n";
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (IsUnique3(in[i]) == out[i]) << std::endl;
    }
    return 0;
}
