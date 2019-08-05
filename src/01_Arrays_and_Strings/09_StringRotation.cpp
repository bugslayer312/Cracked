// Assume you have a method isSubst ring which checks if one word is a substring
// of another. Given two strings, 51 and 52, write code to check if 52 is a
// rotation of 51 using only one call to isSubstring (e.g., "waterbottle"
// is a rotation of "erbottlewat").

#include "09_StringRotation.h"

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
