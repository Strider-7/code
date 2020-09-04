#include <bits/stdc++.h>

using namespace std;

int ed(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (s1[m - 1] == s2[n - 1])
        return ed(s1, s2, m - 1, n - 1);
    else
        return 1 + min({ed(s1, s2, m - 1, n), ed(s1, s2, m, n - 1), ed(s1, s2, m - 1, n - 1)});
}

int editDistance(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int i = 0; i <= n; i++)
        dp[0][i] = i;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[m][n];
}

int main()
{

    string s1 = "saturday", s2 = "sunday";
    cout << ed(s1, s2, s1.size(), s2.size()) << endl;
    cout << editDistance(s1, s2);

    return 0;
}