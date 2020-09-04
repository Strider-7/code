#include <bits/stdc++.h>

using namespace std;

int LCS(string s1, string s2, int i = 0, int j = 0)
{
    if (i == s1.length() || j == s2.length())
        return 0;
    if (s1[i] == s2[j])
        return 1 + LCS(s1, s2, i + 1, j + 1);
    else
        return max(LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1));
}

// LCS using memorization

vector<vector<int>> memo(100, vector<int>(100, -1));

int LCS2(string s1, string s2, int i = 0, int j = 0)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i == s1.length() || j == s2.length())
        memo[i][j] = 0;
    else
    {
        if (s1[i] == s2[j])
            memo[i][j] = 1 + LCS2(s1, s2, i + 1, j + 1);
        else
            memo[i][j] = max(LCS2(s1, s2, i + 1, j), LCS2(s1, s2, i, j + 1));
    }
    return memo[i][j];
}

// LCS using DP bottom-up

int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{

    string s1 = "xabycz", s2 = "adeyjz";
    cout << lcs(s1, s2);

    return 0;
}