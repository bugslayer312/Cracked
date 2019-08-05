#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void print(std::unordered_map<char, int> const& map) {
    for (auto& p : map) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}

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

int main() {
    std::vector<std::pair<std::string, std::string>> in = {{"qweqrty", "rewqty"},
                                                           {"uirewoer", "iuwerroe"},
                                                           {"abcsdfsdfsf", "afdscfsdbsf"},
                                                           {"aab", "aaab"}};
    std::vector<bool> out = {false, true, true, false};
    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (isPermutation(in[i].first, in[i].second) == out[i]) << std::endl;
    }
    return 0;
}
