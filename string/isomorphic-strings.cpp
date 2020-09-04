#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    char map_s[128] = {0};
    char map_t[128] = {0};
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (map_s[s[i]] != map_t[t[i]])
            return false;
        map_s[s[i]] = i + 1;
        map_t[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    string s1 = "add", s2 = "egg";

    cout << isIsomorphic(s1, s2);

    return 0;
}