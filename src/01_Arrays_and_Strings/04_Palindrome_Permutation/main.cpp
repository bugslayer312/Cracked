#include <iostream>
#include <unordered_map>
#include <vector>

bool isPalPerm(std::string const& s) {
    std::unordered_map<char, bool> flags;
    for (char c : s) {
        if (std::isalpha(c)) {
            flags[std::tolower(c)] ^= true;
        }
    }
    int hasOdd = false;
    for (auto p : flags) {
        if (p.second) {
            if (hasOdd) {
                return false;
            }
            hasOdd = true;
        }
    }
    return true;
}

bool isPalPerm2(std::string const& s) {
    std::uint32_t flags = 0;
    for (char c : s) {
        if (std::isalpha(c)) {
            int pos = 'z' - std::tolower(c);
            flags ^= 0x00000001 << pos;
        }
    }
    int hasOdd = false;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (flags & (0x00000001 << (c - 'a'))) {
            if (hasOdd) {
                return false;
            }
            hasOdd = true;
        }
    }
    return (flags & (flags - 1)) == 0;
}

int main() {
    std::vector<std::string> in = {"qweqrty ewqryt", "Tact Coa", "awsedril", "abc ba caba"};
    std::vector<bool> out = {true, true, false, true};
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (isPalPerm(in[i]) == out[i]) << std::endl;
    }
    std::cout << "-----\n";
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (isPalPerm2(in[i]) == out[i]) << std::endl;
    }
    return 0;
}
