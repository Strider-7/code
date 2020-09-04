#include <bits/stdc++.h>

using namespace std;

int countWays(int n, int x)
{
    if (n < 1)
        return 0;

    if (x == 0)
        return 1;

    if (x < 0)
        return 0;
    return (countWays(n - 1, x) + countWays(n, x - n));
}

int countWays(int n)
{
    long long dp[n + 1]{}, p = pow(10, 9) + 7;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = i; j <= n; j++)
            dp[j] += dp[j - i] % p;

    return dp[n] % p;
}

// similar to coin change
int getCount(int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n < 1)
        return 0;
    if (sum < 0)
        return 0;
    return getCount(n - 1, sum) + getCount(n, sum - n);
}

int totalCount(int n, int sum)
{
    int dp[sum + 1][n];
    for (int i = 0; i <= sum; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i][i-j];
        }
    }

    return dp[sum][n-1];
}
// best by reducing search space
int change(int amount, vector<int> &coins)
{
    int ways[5005] = {};
    ways[0] = 1;
    for (auto coin : coins)
    {
        for (int amt = coin; amt <= amount; amt++)
            ways[amt] += ways[amt - coin];
    }
    return ways[amount];
}

int main()
{
    int n = 7;
    cout << countWays(n - 1, n) << endl;
    cout << getCount(n - 1, n) << endl;
    cout << totalCount(n - 1, n) << endl;
    return 0;
}