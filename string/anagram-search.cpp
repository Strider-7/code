#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

bool anagramCheck(string s1, string s2, int i)
{
    int count[256]{};
    for (int j = 0; j < s2.length(); j++)
    {
        count[s1[i + j]]++;
        count[s2[j]]--;
    }
    for (int j = 0; j < 256; j++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

bool anagramSearch(string s, string p)
{
    int n = s.length(), m = p.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (anagramCheck(s, p, i))
            return true;
    }

    return false;
}

bool isPresent(string s, string p)
{
    int n = s.length(), m = p.length();
    int Scount[CHAR]{}, Pcount[CHAR]{};
    for (int i = 0; i < m; i++)
    {
        Scount[s[i]]++;
        Pcount[p[i]]++;
    }
    for (int i = m; i < n; i++)
    {
        if (equal(Scount, Scount + CHAR, Pcount))
            return true;

        Scount[s[i]]++;
        Scount[s[i - m]]--;
    }
    return equal(Scount, Scount + CHAR, Pcount);
}

int main()
{
    

    string s1 = "aaaaaaaaaa", s2 = "aaaaaaaaaaaaa";
    // cout << anagramSearch(s1, s2) << endl;

    cout << isPresent(s1, s2);
    return 0;
}