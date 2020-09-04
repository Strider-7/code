// You are given a string str. You need to remove the pair of duplicates.
// Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together

#include <bits/stdc++.h>

using namespace std;

string removePair(string s)
{
    stack<char> st;

    st.push(s[0]);

    for (int i = 1; i < s.length(); i++)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
            continue;
        }
        else
            st.push(s[i]);
    }

    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main()
{
    string str = "aaabbaaccd";
    cout << removePair(str);
    return 0;
}