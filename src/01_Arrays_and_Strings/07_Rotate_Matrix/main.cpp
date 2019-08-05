#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> Matrix;

void RotateMatrix(Matrix& m, bool isClockWise) {
    size_t n = m.size();
    for (size_t layer = n; layer > 1; layer -= 2) {
        size_t offset = (n - layer)/2;
        size_t left = offset, top = offset;
        size_t right = layer - 1 + offset, bottom = right;
        for (size_t j = 0; j < layer-1; ++j) {
            std::vector<std::pair<size_t, size_t>> idxs = {
                {top, left+j}, {bottom-j, left}, {bottom, right-j}, {top+j, right}
            };
            if (!isClockWise)  {
                std::reverse(idxs.begin(), idxs.end());
            }
            int temp = m[idxs[0].first][idxs[0].second];
            m[idxs[0].first][idxs[0].second] = m[idxs[1].first][idxs[1].second];
            m[idxs[1].first][idxs[1].second] = m[idxs[2].first][idxs[2].second];
            m[idxs[2].first][idxs[2].second] = m[idxs[3].first][idxs[3].second];
            m[idxs[3].first][idxs[3].second] = temp;
        }
    }
}

int main() {
    std::vector<Matrix> in = {{{1, 2}, {3, 4}},
                           {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                          {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}}};
    std::vector<Matrix> out1 = {{{3, 1}, {4, 2}},
                           {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}},
                          {{13,9,5,1}, {14,10,6,2}, {15,11,7,3}, {16,12,8,4}}};
    std::vector<Matrix> out2 = {{{2, 4}, {1, 3}},
                           {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}},
                          {{4,8,12,16}, {3,7,11,15}, {2,6,10,14}, {1,5,9,13}}};
    for (size_t i = 0; i < in.size(); ++i) {
        Matrix m1(in[i]);
        Matrix m2(in[i]);
        RotateMatrix(m1, true);
        RotateMatrix(m2, false);
        std::cout << (m1 == out1[i]) << " | " << (m2 == out2[i]) << std::endl;
    }
    return 0;
}
