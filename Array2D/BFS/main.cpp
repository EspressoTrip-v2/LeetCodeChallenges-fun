#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include "utils.h"

using namespace std;
template<int m_, int n_>
class matrix {
    using mat = vector<array<int, m_>>;
    mat m_matrix;
    int m_row{m_};
    int m_col{n_};
    vector<vector<bool>> m_seen;
    queue<pair<int, int>> m_pos;

    static const vector<pair<int, int>> directions;

    bool check(int row_, int col_) {
        if (row_ < 0 || row_ > m_row - 1 || col_ < 0 || col_ > m_col - 1) return false;
        if (!m_seen[row_][col_]) return true;
        return false;
    }
    void BFSFunc(int row_, int col_) {
        if (check(row_, col_)) {
            cout << m_matrix[row_][col_] << " ";
            m_seen[row_][col_] = true;
            for (auto &d: directions) {
                if (check(row_ + d.first, col_ + d.second))
                    m_pos.push({row_ + d.first, col_ + d.second});
            }
        }
    }
public:
    matrix(initializer_list<array<int, m_>> list) : m_matrix(list), m_seen(m_, vector<bool>(n_, false)) {}
    [[nodiscard]]
    int at(int row_, int col_) {
        return m_matrix[row_][col_];
    }
    void BFS() {
        cout << "[ ";
        m_pos.push({0, 0});
        while (!m_pos.empty()) {
            auto currentPos = m_pos.front();
            BFSFunc(currentPos.first, currentPos.second);
            m_pos.pop();
        }
        cout << "]" << endl;
    }
};

template<int m_, int n_>
const vector<pair<int, int>> matrix<m_, n_>::directions{{-1, 0},
                                                        {0,  1},
                                                        {1,  0},
                                                        {0,  -1}};
int main() {
    matrix<4, 4> m{
            {4, 10, 3, 6},
            {1, 5,  8, 9},
            {9, 25, 6, 2},
            {3, 2,  4, 5}};

    cout << "Position (1, 2) -> " << m.at(1, 2) << endl;
    cout << "Position (3, 3) -> " << m.at(3, 3) << endl;
    cout << "Position (0, 1) -> " << m.at(0, 1) << endl;
    cout << endl;
    m.BFS();
    return 0;

}
