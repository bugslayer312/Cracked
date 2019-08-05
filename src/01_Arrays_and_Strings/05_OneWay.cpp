// There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to
// check if they are one edit (or zero edits) away.

#include "05_OneWay.h"

#include <string>

bool isNoMoreThan1LetterEdit(std::string const& s1, std::string const& s2) {
    int sizeDiff = static_cast<int>(s1.size()) - s2.size();
    if (abs(sizeDiff) > 1) {
        return false;
    }
    size_t posDif = std::string::npos;
    size_t minSize = std::min(s1.size(), s2.size());
    for (size_t i = 0; i < minSize; ++i) {
        if (s1[i] != s2[i]) {
            posDif = i;
            break;
        }
    }
    if (posDif != std::string::npos) {
        size_t stepsFromBack = minSize - posDif - 1;
        for (size_t i=0; i < stepsFromBack; ++i) {
            if (s1[s1.size()-i-1] != s2[s2.size()-i-1]) {
                return false;
            }
        }
    }
    return true;
}
