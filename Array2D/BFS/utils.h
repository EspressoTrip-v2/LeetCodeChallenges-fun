//
// Created by Juan on 7/3/2021.
//
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
#ifndef BFS_UTILS_H
#define BFS_UTILS_H

namespace Utils {
    void printSeen(const vector<vector<bool>> &v) {
        cout << boolalpha << endl;
        for (auto &m: v) {
            cout << "|";
            for (auto n:m) {
                cout << setw(7) << n << " ";
            }
            cout << " |" << endl;
        }
    }
    template<int n_>
    void printMatrix(vector<array<int, n_>> &v) {
        cout << boolalpha << endl;
        for (auto &m: v) {
            cout << "|";
            for (auto n:m) {
                cout << setw(3) << n << " ";
            }
            cout << " |" << endl;
        }
    }
}

#endif //BFS_UTILS_H
