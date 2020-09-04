#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string p)
{
    int n = s.length(), m = p.length();
    int count[256]{};
    for (int i = 0; i < m; i++)
        count[p[i]]++;

    int left = 0, Pcount = 0;
    string res = "";
    for (int right = 0; right < n; right++)
    {
        if (count[s[right]] > 0)
        {
            count[s[right]]--;
            Pcount++;
        }
        if (Pcount == m)
            res = s.substr(left, right);
    }
}

int main()
{
    string s1 = "a1b23cde100";

    return 0;
}