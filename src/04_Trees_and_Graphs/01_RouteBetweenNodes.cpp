#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>

typedef std::unordered_map<int, std::list<int>> GraphAdjList;

template<int N>
GraphAdjList AdjMatrixToList(int (&m)[N][N]) {
    GraphAdjList result;
    for (int i = 0; i < N; ++i) {
        std::list<int>& l = result[i] = std::list<int>();
        for (int j=0; j < N; ++j) {
            if (m[i][j]) {
                l.push_back(j);
            }
        }
    }
    return result;
}



int main() {
    //int a[2] = {1, 2};
    int m[7][7] = {{1,0,0,0,0,0,0},
                  {0,0,1,0,0,0,0},
                  {1,0,0,1,0,0,0},
                  {0,0,1,0,0,0,0},
                  {0,0,0,0,0,0,1},
                  {0,0,0,0,1,0,0},
                  {0,0,0,0,0,1,0}};

    GraphAdjList ml = AdjMatrixToList(m);

    return 0;
}
