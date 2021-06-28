#include <iostream>
#include <set>
using namespace std;


//int lengthOfLongestSubstring(string s) // Sliding window
//{
//    if (s.empty()) return 0;
//    set<char> hash;
//    auto p1 = std::begin(s);
//    hash.insert(*p1);
//    auto p2 = std::begin(s) + 1;
//    int ws{1};
//    while (p2 != std::end(s))
//    {
//        if (hash.count(*p2))
//        {
//            if (*p1 == *p2)
//            {
//                p1++;
//                p2++;
//            } else
//            {
//                hash.erase(*p1);
//                p1++;
//            }
//        } else
//        {
//            hash.insert(*p2);
//            p2++;
//            ws = ws > hash.size() ? ws : static_cast<int>(hash.size());
//        }
//    }
//    return ws;
//};

int lengthOfLongestSubstring(string s) // Sliding window
{
    if (s.empty()) return 0;
    set<char> hash;
    auto p1 = std::begin(s);
    hash.insert(*p1);
    auto p2 = std::begin(s) + 1;
    int ws{1};
    while (p2 != std::end(s))
    {
        if (distance(p1, std::end(s)) < ws) break;
        if (hash.count(*p2))
        {
            if (*p1 == *p2)
            {
                p1++;
                p2++;
            } else
            {
                hash.erase(*p1);
                p1++;
            }
        } else
        {
            hash.insert(*p2);
            p2++;
            ws = ws > hash.size() ? ws : static_cast<int>(hash.size());
        }
    }
    return ws;
};
int main()
{
    cout << lengthOfLongestSubstring("abcabcbb");
    cout << endl;
    cout << lengthOfLongestSubstring("pwwkew");
    cout << endl;
    cout << lengthOfLongestSubstring("dvdf");
    cout << endl;
    cout << lengthOfLongestSubstring("qrsvbspk"
    );
    return 0;
}
