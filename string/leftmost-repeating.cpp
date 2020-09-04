#include <bits/stdc++.h>
using namespace std;

char firstRepeatingChar(string s) /*wrong */
{
    int count[256]{};

    for (auto &&i : s)
        count[i]++;

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 1)
            return (char)i;
    }

    return '\0';
}

char leftmostRepeatingChar(string s)
{
    int res = INT32_MAX, firstIndex[256];
    fill(firstIndex, firstIndex + 256, -1);

    for (int i = 0; i < s.length(); i++)
    {
        int fi = firstIndex[s[i]];
        if (fi == -1)
            firstIndex[s[i]] = i;
        else
            res = min(res, fi);
    }

    return (res == INT32_MIN) ? '\0' : s[res];
}

char leftrepeatingChar(string s)
{
    bool visited[256]{};
    char res = '\0';
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (visited[s[i]])
            res = s[i];
        visited[s[i]] = true;
    }
    return res;
}

int main()
{
    string s = "geeksforgeeks";
    cout << firstRepeatingChar(s) << endl;
    cout << leftmostRepeatingChar(s) << endl;
    cout << leftrepeatingChar(s) << endl;
    return 0;
}