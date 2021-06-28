#include <iostream>
#include <stack>
using namespace std;

/*
    Given a string s of '(' , ')' and lowercase English characters.
    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
    so that the resulting parentheses string is valid and return any valid string.

    Formally, a parentheses string is valid if and only if:
    * It is the empty string, contains only lowercase characters, or
    * It can be written as AB (A concatenated with B), where A and B are valid strings, or
    * It can be written as (A), where A is a valid string.
*/

string minRemoveToMakeValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (st.empty()) {
                s[i] = '*';
            } else {
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        s[st.top()] = '*';
        st.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;

};
int main()
{
    cout << minRemoveToMakeValid("lee(t(c)o)de))") << endl;
    cout << minRemoveToMakeValid("a)b(c)d)") << endl;
    cout << minRemoveToMakeValid("())()(((") << endl;
    cout << minRemoveToMakeValid("(a(b(c)d)") << endl;
    return 0;
}
