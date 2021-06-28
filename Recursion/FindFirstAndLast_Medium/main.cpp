#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
    If target is not found in the array, return [-1, -1].
    You must write an algorithm with O(log n) runtime complexity.
*/

int binary_search(vector<int> &v, int p1, int p2, int value) {
    double left{static_cast<double>(p1)}, right{static_cast<double>(p2)};
    while (left <= right) {
        auto mid = static_cast<int>(std::floor((left + right) / 2));
        if (v[mid] == value) return mid;
        if (v[mid] < value) {
            left = mid + 1;
        }
        if (v[mid] > value) {
            right = mid - 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};
    auto first = binary_search(nums, 0, nums.size() - 1, target);
    if (first == -1) return {-1, -1};
    int temp1{}, temp2{}, startPos{first}, endPos{first};
    while (startPos != -1) {
        temp1 = startPos;
        startPos = binary_search(nums, 0, startPos - 1, target);
    }
    startPos = temp1;

    while (endPos != -1) {
        temp2 = endPos;
        endPos = binary_search(nums, endPos + 1, nums.size() - 1, target);
    }
    endPos = temp2;
    return {startPos, endPos};
}

void print(vector<int> &v) {
    cout << "[ ";
    for (auto &i: v)
        cout << i << " ";
    cout << "]" << endl;
}

int main() {
    vector<int> v1{1, 2, 3, 5, 5, 5, 5, 9};
    vector<int> v2{2, 2, 2, 3, 4, 5, 6};
    auto r1 = searchRange(v1, 5);
    auto r2 = searchRange(v2, 2);
    print(r1);
    print(r2);
    return 0;
}
