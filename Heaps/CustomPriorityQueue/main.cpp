#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
    Create a custom a priority max heap
    Parent = std::floor(idx -1)/2)
    Left = (idx * 2) + 1
    right = (idx * 2) + 2
*/
class max_heap {
    vector<int> m_heap;

    int leftItem(int idx) {
        int i = (idx * 2) + 1;
        return (i > m_heap.size() - 1) ? -1 : i;
    }
    int rightItem(int idx) {
        int i = (idx * 2) + 2;
        return (i > m_heap.size() - 1) ? -1 : i;
    }
    static int parent(int idx) {
        return static_cast<int>(std::floor(idx) / 2);
    }
    void sort() {
        int parentIdx = max_heap::parent(m_heap.size() - 1);
        int lastItemIdx = static_cast<int>(m_heap.size() - 1);

        while (m_heap[parentIdx] < m_heap[lastItemIdx]) {

            int temp = m_heap[parentIdx];
            m_heap[parentIdx] = m_heap[lastItemIdx];
            m_heap[lastItemIdx] = temp;
            lastItemIdx = parentIdx;
            parentIdx = max_heap::parent(std::floor(parentIdx));
        }
    }

    void downSift() {
        int itemIdx = 0, leftIdx{-1}, rightIdx{-1}, childIdx{0};
        while (true) {
            leftIdx = leftItem(itemIdx);
            rightIdx = rightItem(itemIdx);
            if (leftIdx > -1 && rightIdx > -1) {
                childIdx = m_heap[leftIdx] < m_heap[rightIdx] ? rightIdx : leftIdx;
                if (m_heap[childIdx] > m_heap[itemIdx]) {
                    std::swap(m_heap[childIdx], m_heap[itemIdx]);
                    itemIdx = childIdx;
                    continue;
                }
            }
            if (leftIdx == -1 && rightIdx > -1) {
                if (m_heap[rightIdx] > m_heap[itemIdx]) {
                    std::swap(m_heap[rightIdx], m_heap[itemIdx]);
                    itemIdx = rightIdx;
                    continue;
                } else { break; }
            }
            if (rightIdx == -1 && leftIdx > -1) {
                if (m_heap[leftIdx] > m_heap[itemIdx]) {
                    std::swap(m_heap[leftIdx], m_heap[itemIdx]);
                    itemIdx = leftIdx;
                    continue;
                } else { break; }
            }
            if (leftIdx == -1 && rightIdx == -1) break;
        }
    }

public:
    max_heap(initializer_list<int> &&heap_) {
        for (auto &i: heap_) {
            insert(i);
        }
    }
    void insert(int value_) {
        m_heap.push_back(value_);
        if (m_heap.size() > 1) sort();
    }

    int remove() {
        auto backVal = m_heap[m_heap.size() - 1];
        m_heap.pop_back();
        auto val = m_heap[0];
        m_heap[0] = backVal;
        downSift();
        return val;
    }


    friend ostream &operator<<(ostream &os, const max_heap &heap) {
        os << "[ ";
        for (auto &i: heap.m_heap)
            os << i << " ";
        os << "]" << endl;
        return os;
    }
};

int main() {
    max_heap h{50, 45, 25, 40, 35, 10, 15, 20};
    cout << h;
    h.remove();
    cout << h;
    h.remove();
    cout << h;
    h.remove();
    cout << h;
    h.insert(100);
    cout << h;
    return 0;
}
