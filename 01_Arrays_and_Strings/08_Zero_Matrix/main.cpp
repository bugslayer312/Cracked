#include <iostream>
#include <vector>
#include <unordered_set>

typedef std::vector<std::vector<int>> Matrix;
static const size_t InvalidIdx = std::numeric_limits<size_t>::max();

void ZeroMatrix(Matrix& m) {
    std::unordered_set<size_t> zeroColumns;
    std::vector<size_t> nonZeroRows;
    /*nonZeroRows.reserve(m.size());
    for (size_t i=0; i < m_size(); ++i) {

    } */
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

int main() {
    std::vector<Matrix> in = {{{1, 0, 3}, {4, 5, 6}},
                              {{0, 2, 3}, {0, 5, 6}, {7, 8, 9}, {10, 11, 0}},
                              {{1,2,3,4}, {5,6,0,8}, {9,0,11,12}, {13,14,15,16}}};
    std::vector<Matrix> out = {{{0, 0, 0}, {4, 0, 6}},
                               {{0, 0, 0}, {0, 0, 0}, {0, 8, 0}, {0, 0, 0}},
                               {{1,0,0,4}, {0,0,0,0}, {0,0,0,0}, {13,0,0,16}}};
    for (size_t i = 0; i < in.size(); ++i) {
        Matrix m(in[i]);
        ZeroMatrix(m);
        std::cout << (m == out[i]) << std::endl;
    }
    return 0;
}
