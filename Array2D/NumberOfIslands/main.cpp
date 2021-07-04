#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    vector<pair<int, int>> dir{{-1, 0},
                               {0,  1},
                               {1,  0},
                               {0,  -1}};
    queue<pair<int, int>> m_Q;
    int m_row{};
    int m_col{};
public:
    void BFS(vector<vector<char>> &grid) {
        while (!m_Q.empty()) {
            auto current = m_Q.front();
            for (auto &d: dir) {
                if (current.first + d.first < 0 || current.first + d.first >= m_row || current.second + d.second < 0 ||
                    current.second + d.second >= m_col)
                    continue;
                if (grid[current.first + d.first][current.second + d.second] == '1') {
                    m_Q.push({current.first + d.first, current.second + d.second});
                    grid[current.first + d.first][current.second + d.second] = '0';
                }
            }
            m_Q.pop();
        }

    }
    int numIslands(vector<vector<char>> &grid) {
        int m_count{0};
        if (grid.empty()) return 0;
        m_row = static_cast<int>(grid.size());
        m_col = static_cast<int>(grid[0].size());
        for (auto i{0}; i < m_row; i++) {
            for (auto j{0}; j < m_col; j++) {
                if (grid[i][j] == '1') {
                    m_count++;
                    grid[i][j] = '0';
                    m_Q.push({i, j});
                    BFS(grid);
                }
            }
        }
        return m_count;
    }
};

int main() {
    Solution s;
    vector<vector<char>> v1{{'1', '1', '1', '1', '0'},
                            {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '0', '0', '0'}};

    vector<vector<char>> v2{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};

    vector<vector<char>> v3{{'1', '1', '1'},
                            {'0', '1', '0'},
                            {'1', '1', '1'}};

    cout << "Number of islands A: " << s.numIslands(v1);
    cout << endl;
    cout << "Number of islands B: " << s.numIslands(v2);
    cout << endl;
    cout << "Number of islands C: " << s.numIslands(v3);
    return 0;
}
