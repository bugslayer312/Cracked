#pragma once

#include <ostream>
#include <limits>

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, static_cast<double>(clock() - blockTime) / CLOCKS_PER_SEC))

typedef unsigned int uint;

struct to_binary {
    uint m_num;
    explicit to_binary(uint num) : m_num(num) {}
};

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
