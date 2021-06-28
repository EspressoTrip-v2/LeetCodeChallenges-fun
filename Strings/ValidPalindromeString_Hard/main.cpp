#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

/*
    Given a string s, return true if the s can be palindrome
    after deleting at most one character from it.

    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.
*/
bool validPalindrome(string s)
{
    if (s.length() <= 2) return true;
    bool flagA{true}, flagB{true}, skipped{false}, split{false};
    int p1A{0}, p2A{static_cast<int>(s.size() - 1)}, p1B{0}, p2B{0};
    while (p1A <= p2A && p1B <= p2B) {
        if (s[p1A] == s[p2A] && !split) {
            p1A++;
            p2A--;
            continue;
        } else if (s[p1A] != s[p2A] && s[p1A] == s[p2A - 1] && s[p1A + 1] != s[p2A] && !skipped && !split) {
            p2A--;
            skipped = true;
            continue;
        } else if (s[p1A] != s[p2A] && s[p1A] != s[p2A - 1] && s[p1A + 1] == s[p2A] && !skipped && !split) {
            p1A++;
            skipped = true;
            continue;
        } else if (s[p1A] != s[p2A] && s[p1A] == s[p2A - 1] && s[p1A + 1] == s[p2A] && !skipped && !split) {
            split = true;
            p2B = p2A;
            p2A--;
            p1B = p1A + 1;
            continue;
        } else if (split) {
            if (s[p1A] == s[p2A]) {
                p1A++;
                p2A--;
            } else {
                flagA = false;
                if (!flagB) break;
            }
            if (s[p1B] == s[p2B]) {
                p1B++;
                p2B--;
            } else {
                flagB = false;
                if (!flagA) break;
            }
        } else {
            flagA = false;
            flagB = false;
            break;
        }

    }
    return flagA || flagB;
}
int main()
{
    cout << boolalpha << endl;
    cout << validPalindrome("raceacar") << endl;
    cout << validPalindrome("abccdba") << endl;
    cout << validPalindrome("abcdefdba") << endl;
    cout << validPalindrome("") << endl;
    cout << validPalindrome("a") << endl;
    cout << validPalindrome("pidbliassaqozokmtgahluruufwbjdtayuhbxwoicviygilgzduudzgligyviciowxbhuyatdjbwfuurulhagtmkozoqassailbdip") << endl;
    cout << validPalindrome("ebcbbececabbacecbbcbe") << endl;
    return 0;
}
