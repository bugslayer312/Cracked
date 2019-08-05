// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include "07_RotateMatrix.h"

#include <algorithm>

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
