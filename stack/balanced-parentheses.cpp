#include <bits/stdc++.h>

using namespace std;

bool matching(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

bool balanced(string str)
{
    stack<int> s;
    for (auto &&i : str)
    {
        if (i == '(' || i == '{' || i == '[')
            s.push(i);
        else
        {
            if (s.empty())
                return false;
            if (!matching(s.top(), i))
                return false;
            s.pop();
        }
    }
    return s.empty();
}
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;
            if (c == ')' && st.top() != '(')
                return false;
            if (c == '}' && st.top() != '{')
                return false;
            if (c == ']' && st.top() != '[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string str = "{[]}";
    cout << balanced(str);
    return 0;
}