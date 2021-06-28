#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int partition(vector<int> &v, int low, int high) {
    int pivot{v[high]}, l{low}, h{high - 1};
    while (l <= h) {
        if (v[l] <= pivot) {
            l++;
            continue;
        }
        if (v[h] > pivot) {
            h--;
            continue;
        }
        if (v[l] > pivot && v[h] < pivot) swap(v[l], v[h]);
    }
    swap(v[l], v[high]);
    return l;
}

void quick_sort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pivot = partition(v, low, high);
        quick_sort(v, low, pivot - 1);
        quick_sort(v, pivot, high);
    }

}

void print(vector<int> &v) {
    cout << "[ ";
    for (auto &i:v) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

int findKthLargest(vector<int> &nums, int k) {
//    sort(std::begin(nums), std::end(nums));
    return nums[nums.size() - k];
}

int main() {
    vector<int> v{10, 16, 18, 4, 19, 14, 20, 9, 13, 11};
    print(v);
    quick_sort(v, 0, static_cast<int>(v.size() - 1));
    cout << findKthLargest(v, 5) << endl;
    print(v);
    return 0;
}
