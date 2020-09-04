#include <iostream>
#include <string>

using namespace std;

int patternSearch(string s, string p)
{
    int n = s.length(), m = p.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (p[j] != s[i + j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

// o(n)-only when pattern has distinct characters
void patternSearch2(string s, string p)
{
    int n = s.length(), m = p.length();
    for (int i = 0; i <= n - m;)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            // cout << "hey \t" << i << endl;
            if (p[j] != s[i + j])
                break;
        }
        if (j == m)
            cout << i << endl;
        if (j == 0)
            i++;
        else
            i += j;
    }
}

void patternSearching(string s, string p)
{
    int n = s.length(), m = p.length(), low = 0;
    string curr = s.substr(0, m);
    if (curr == p)
        cout << 0 << endl;
    for (int i = m; i < n; i++)
    {
        curr.erase(curr.begin());
        curr = curr + s[i];
        // cout << curr << endl;
        if (curr == p)
            cout << i - m + 1 << endl;
    }
}

int main()
{
    string s = "abdybhdbf";

    patternSearch2(s, "bdy");
    // patternSearching(s, "bdy");

    return 0;
}