#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;
/*
    Create a custom Matrix with DFS search
*/
template<int m_, int n_>
class matrix {
    using mat = vector<array<int, m_>>;
    mat m_matrix;
    int m_column{m_};
    int m_row{n_};

    vector<vector<bool>> seen;
    static pair<int, int> up;
    static pair<int, int> down;
    static pair<int, int> left;
    static pair<int, int> right;

    // Private methods
    void printSeen(vector<vector<bool>> &v) {
        cout << boolalpha << endl;
        for (auto &row:v) {
            cout << "|";
            for (auto col: row) {
                cout << " " << setw(3) << col << " ";
            }
            cout << setw(3) << "|" << endl;
        }
    }
    bool checked(int row_, int col_) {
        if (row_ < 0 || row_ > m_row - 1 || col_ < 0 || col_ > m_column - 1) return true;
        if (seen[row_][col_]) return true;
        return false;
    }
    void DFSFunc(int row_, int col_) {
        if (!checked(row_, col_)) {
            cout << m_matrix[row_][col_] << " ";
            seen[row_][col_] = true;
        }
        if (!checked(row_ + up.first, col_ + up.second)) DFSFunc(row_ + up.first, col_ + up.second);
        if (!checked(row_ + right.first, col_ + right.second)) DFSFunc(row_ + right.first, col_ + right.second);
        if (!checked(row_ + down.first, col_ + down.second)) DFSFunc(row_ + down.first, col_ + down.second);
        if (!checked(row_ + left.first, col_ + left.second)) DFSFunc(row_ + left.first, col_ + left.second);
    }

public:
    matrix(initializer_list<array<int, m_>> list)
            : m_matrix(list), seen(m_row, vector<bool>(m_column, false)) {}
    [[nodiscard]]
    pair<int, int> dim() { return {m_column, m_row}; };

    [[nodiscard]]
    int at(int row_, int col_) {
        return m_matrix[row_][col_];
    }

    friend ostream &operator<<(ostream &os, const matrix &m) {
        for (auto &row:m.m_matrix) {
            os << "|";
            for (auto &col: row) {
                os << " " << setw(3) << col << " ";
            }
            os << setw(3) << "|" << endl;
        }
        return os;
    }

    void DFS() {
        cout << "[ ";
        DFSFunc(0, 0);
        cout << "]" << endl;
    }
};

template<int m_, int n_>
pair<int, int> matrix<m_, n_>::up{-1, 0};
template<int m_, int n_>
pair<int, int> matrix<m_, n_>::down{1, 0};
template<int m_, int n_>
pair<int, int> matrix<m_, n_>::left{0, -1};
template<int m_, int n_>
pair<int, int> matrix<m_, n_>::right{0, 1};

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
    m.DFS();
    return 0;
}
