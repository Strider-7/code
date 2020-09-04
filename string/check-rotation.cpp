#include <bits/stdc++.h>

using namespace std;

bool checkRotation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < s1.length(); i++)
    {
        rotate(s1.begin(), s1.begin() + 1, s1.end());
        cout << s1 << endl;
        if (s1 == s2)
            return true;
    }
    return false;
}

bool patternSearch2(string s, string p)
{
    int n = s.length(), m = p.length(), low = 0;
    string curr = s.substr(0, m);
    if (curr == p)
        return true;
    for (int i = m; i < n; i++)
    {
        curr.erase(curr.begin());
        curr = curr + s[i];
        if (curr == p)
            return true;
    }
    return false;
}

bool checkRotate(string s1, string s2)
{
    return patternSearch2(s1 + s1, s2);
}

bool checkRotate2(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    auto found = (s1 + s1).find(s2);
    if (found != string::npos)
        return true;
    return false;
}

int main()
{
    string s = "dario", str = "rioda";
    cout << checkRotation(s, str) << endl;
    cout << checkRotate2(s, str) << endl;
    cout<<s.substr(0,2);

    return 0;
}