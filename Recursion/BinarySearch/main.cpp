#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    Simple binary search
*/

int binary_search(vector<int> &v, int value) {
    double p1{0}, p2{static_cast<double>(v.size()) - 1};
    while (p1 <= p2) {
        auto mid = static_cast<int>(std::floor((p1 + p2) / 2));
        if (v[mid] == value) return v[mid];
        if (v[mid] < value) {
            p1 = mid + 1;
        }
        if (v[mid] > value) {
            p2 = mid - 1;
        }
    }
    return 0;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    cout << binary_search(v, 7) << endl;
    cout << binary_search(v, 1) << endl;
    cout << binary_search(v, 3) << endl;
    return 0;
}
