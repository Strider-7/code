#include <bits/stdc++.h>
using namespace std;

char leftmostNonRepeatingChar(string s)
{
    int count[256]{};

    for (int i = 0; i < s.length(); i++)
        count[s[i]]++;

    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] == 1)
            return s[i];
    }

    return '\0';
}

char leftnonrepeatingChar(string s)
{
    bool visited[256]{};
    char res = '\0';
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!visited[s[i]])
            res = s[i];
        visited[s[i]] = true;
    }
    return res;
}

int main()
{
    string s = "abeea";
    cout << leftnonrepeatingChar(s) << endl;
    cout << leftmostNonRepeatingChar(s);

    return 0;
}