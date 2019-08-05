#include "Utilities.h"

#include <iosfwd>
#include <limits>

std::ostream& operator<<(std::ostream& os, to_binary const& tb) {
    os << "0b";
    bool found1 = false;
    uint n = 1u << std::numeric_limits<uint>::digits-1;
    while (n) {
        if (n & tb.m_num) {
            found1 = true;
            os << '1';
        } else {
            if (found1) {
                os << '0';
            }
        }
        n >>= 1;
    }
    if (!found1) {
        os << '0';
    }
    return os;
}
