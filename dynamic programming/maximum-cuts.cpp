#include <bits/stdc++.h>

using namespace std;

int maxCuts(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max({maxCuts(n - a, a, b, c), maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)});

    return res == -1 ? res : 1 + res;
}

// dp approach

int maximumCuts(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);
        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);
        if (dp[i] != -1)
            dp[i]++;  
    }
    return dp[n];
}

int main()
{
    cout << maxCuts(5, 1, 2, 3) << endl;
    cout << maximumCuts(5, 1, 2, 3) << endl;
    return 0;
}