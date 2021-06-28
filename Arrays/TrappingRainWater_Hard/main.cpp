#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   Given n non-negative integers representing an elevation map where the width
   of each bar is 1, compute how much water it can trap after raining.
   Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
   Output: 6
*/

//int trap(vector<int> &height)
//{
//    int count{};
//    auto p = std::begin(height);
//    while (p != std::end(height))
//    {
//        auto maxR = max_element(p, std::end(height));
//        auto maxL = max_element(std::begin(height), p);
//        int val = min(*maxL, *maxR) - *p;
//        if (val >= 0) count += val;
//        p++;
//    }
//
//    return count;
//};

int trap(vector<int> &height) // Optimised
{
    if (height.size() < 2) return 0;
    int maxL{};
    int maxR{};
    int count{};
    auto pA = std::begin(height);
    auto pB = std::end(height) - 1;
    while (pA <= pB)
    {
//        cout << *pA << " : " << *pB << endl;
        if (*pA <= *pB)
        {
            if (*pA >= maxL)
            {
                maxL = *pA;
                pA++;
            } else
            {
                count += maxL - *pA;
                pA++;
            }
        } else
        {
            if (*pB >= maxR)
            {
                maxR = *pB;
                pB--;
            } else
            {
                count += maxR - *pB;
                pB--;
            }
        }
    }

    return count;
};

int main()
{
    vector<int> h1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(h1) << endl;
    cout << endl;
    vector<int> h2{4, 2, 0, 3, 2, 5};
    cout << trap(h2) << endl;
    cout << endl;
    vector<int> h3{4, 2, 3};
    cout << trap(h3) << endl;
    cout << endl;
    vector<int> h4{1, 2};
    cout << trap(h4) << endl;
    return 0;
};

