// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.

#include "08_ZeroMatrix.h"

#include <vector>
#include <unordered_set>
#include <limits>

static const size_t InvalidIdx = std::numeric_limits<size_t>::max();

void ZeroMatrix(Matrix& m) {
    std::unordered_set<size_t> zeroColumns;
    std::vector<size_t> nonZeroRows;
    for (size_t i=0; i < m.size(); ++i) {
        size_t firstZeroColumn = InvalidIdx;
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (m[i][j]) {
                if (firstZeroColumn != InvalidIdx) {
                    m[i][j] = 0;
                }
            } else {
                zeroColumns.insert(j);
                if (firstZeroColumn == InvalidIdx) {
                    firstZeroColumn = j;
                }
            }
        }

        if (firstZeroColumn == InvalidIdx) {
            nonZeroRows.push_back(i);
        }
        else {
            for (size_t j = 0; j < firstZeroColumn; ++j) {
                m[i][j] = 0;
            }
        }
    }
    for (size_t j : zeroColumns) {
        for (size_t i : nonZeroRows) {
            m[i][j] = 0;
        }
    }
}
