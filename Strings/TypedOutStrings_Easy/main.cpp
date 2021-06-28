#include <iostream>
#include <regex>
#include <algorithm>
using namespace std;
/*
    Given two strings s and t, return true if they are equal when
    both are typed into empty text editors. '#' means a backspace
    character.
*/

bool backspaceCompare(string s, string t)
{ // Brute force
    string sFix;
    int sHash{0};
    for (int i{static_cast<int>(s.length() - 1)}; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            sHash++;
            continue;
        }
        if (sHash > 0)
        {
            sHash--;
            continue;
        }
        sFix += s[i];
    }

    string tFix;
    int tHash{0};
    for (int i{static_cast<int>(t.size() - 1)}; i >= 0; i--)
    {
        if (t[i] == '#')
        {
            tHash++;
            continue;
        }
        if (tHash > 0)
        {
            tHash--;
            continue;
        }
        tFix += t[i];
    }
    return sFix == tFix;
}
int main()
{
    cout << boolalpha << endl;
    cout << backspaceCompare("b#c", "adf#c") << endl;
    cout << backspaceCompare("ab#c", "ad#c") << endl;
    cout << backspaceCompare("", "#") << endl;
    cout << backspaceCompare("a##c", "#a#c") << endl;

    return 0;
}
