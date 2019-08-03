#include <iostream>
#include <memory>
#include <exception>
#include <vector>

class MemAllocator {
public:
    struct AllocInfo {
        int* Start = nullptr;
        int Size = 0;

        int* GetEnd() {
            return Start + Size;
        }
    };

    MemAllocator(int totalSize, int chunkCount) :
        m_totalSize(totalSize), m_mem(new int[totalSize]) {

        int chunkSize = totalSize / chunkCount;
        m_allocInfo.reserve(chunkSize);
        for (int i=0; i < chunkCount; ++i) {
            m_allocInfo.push_back({m_mem.get() + chunkSize*i, chunkSize});
        }
    }

    int CalcFreeMemBefore(int chunkIdx) {
        if (!chunkIdx) {
            return 0;
        }
        int* End = chunkIdx < m_allocInfo.size() ? m_allocInfo[chunkIdx].Start : m_mem.get() + m_totalSize;
        int* Start = m_allocInfo[chunkIdx-1].GetEnd();
        return End - Start;
    }

    bool ReallocToUp(int chunkIdx) {
        return false;
    }

    bool ReallocMem(int chunkIdx) {
        return false;
    }

private:
    std::unique_ptr<int[]> m_mem;
    int m_totalSize;
    std::vector<AllocInfo> m_allocInfo;
};

class MultipleStack {

};

int main() {
    return 0;
}
