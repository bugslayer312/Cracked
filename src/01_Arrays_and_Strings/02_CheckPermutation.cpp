// Given two strings, write a method to decide if one is a permutation of the
// other.

#include "02_CheckPermutation.h"

#include <unordered_map>

bool isPermutation(std::string const& s1, std::string const& s2) {
    std::unordered_map<char, int> map;
    if (s1.size() != s2.size()) {
        return false;
    }
    for (size_t i=0; i < s1.size(); ++i) {
        map[s1[i]] += 1;
    }
    for (size_t i=0; i < s2.size(); ++i) {
        int& cnt = map[s2[i]];
        if (cnt) {
            cnt -= 1;
        }
        else {
            return false;
        }
    }
    return true;
}
