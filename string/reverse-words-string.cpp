#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string res = "";
    res.reserve(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        string curr = "";
        while (s[i] != ' ' && i < s.length())
        {
            curr += s[i];
            i++;
        }
        cout << curr << endl;
        res.insert(0, curr + " ");
    }
    return res;
}

string reverse2(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string curr = "";
        while (s[i] != ' ' && i < s.length())
        {
            curr += s[i];
            i++;
        }
        st.push(curr);
    }
    s = "";
    while (!st.empty())
    {
        s += st.top() + " ";
        st.pop();
    }
    return s;
}

string reverse3(string s)
{

    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s = "this is almost worth it";
    cout << reverseWords(s) << endl;
    cout << reverse2(s) << endl;
    cout << reverse3(s) << endl;
    return 0;
}