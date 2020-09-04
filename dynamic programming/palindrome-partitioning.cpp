#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1);
}

int minPartitions(string str)
{
    if (isPalindrome(str))
        return 0;
    int i = 0, j = str.length();

    int res = INT32_MAX;
    for (int k = i + 1; k < j; k++)
        res = min(res, 1 + minPartitions(str.substr(i, k - i)) + minPartitions(str.substr(k, j - k)));

    return res;
}

int palPartition(string &str)
{
    int n = str.length();
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT32_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    // diagonal traversal
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[0][n - 1];
}

int main()
{
    string str = "abbabbc";
    cout << minPartitions(str) << endl;
    cout << endl;
    cout << palPartition(str) << endl;
    return 0;
}