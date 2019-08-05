#include <iostream>
#include <string>
#include <vector>

bool isSubstring(std::string const& src, std::string const& tst) {
    return src.find(tst) != std::string::npos;
}

bool isRotation(std::string const& src, std::string const& cmp) {
    if (src.size() == cmp.size()) {
        std::string s;
        s.reserve(src.size());
        s.append(src).append(src);
        return isSubstring(s, cmp);
    }
    return false;
}

int main() {
    std::vector<std::pair<std::string, std::string>> in = {
        {"erbottlewat", "waterbottle"},
        {"qwerty", "yqwert"},
        {"abc", "cba"}};
    std::vector<bool> out = {true, true, false};

    for (size_t i = 0; i < in.size(); ++i) {
        std::cout << (isRotation(in[i].first, in[i].second) == out[i]) << std::endl;
    }
    return 0;
}
