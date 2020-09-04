#include <bits/stdc++.h>
using namespace std;

string concatenatedString2(string s1, string s2)
{
    unordered_set<char> set1, set2;
    for (int i = 0; i < s2.length(); i++)
        set2.insert(s2[i]);

    for (int i = 0; i < s1.length(); i++)
        set1.insert(s1[i]);

    string res = "";
    for (int i = 0; i < s1.length(); i++)
    {
        if (set2.find(s1[i]) == set2.end())
            res += s1[i];
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (set1.find(s2[i]) == set1.end())
            res += s2[i];
    }
    return res.empty() ? "-1" : res;
}



int main()
{
    string s1 = "abbc", s2 = "cadd";
    cout << concatenatedString2(s1, s2);

    return 0;
}