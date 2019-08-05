#pragma once

#include <ostream>
#include <limits>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, static_cast<double>(clock() - blockTime) / CLOCKS_PER_SEC))

typedef std::vector<std::vector<int>> Matrix;

typedef unsigned int uint;

struct to_binary {
    uint m_num;
    explicit to_binary(uint num) : m_num(num) {}
};

std::ostream& operator<<(std::ostream& os, to_binary const& tb);
