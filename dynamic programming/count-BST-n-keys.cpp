// an application of nth catalan number

#include <bits/stdc++.h>
using namespace std;

int countBST(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (n == 2)
        return 2;

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += countBST(i - 1) * countBST(n - i);
    return res;
}

int countBST2(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    }
    return dp[n];
}

int main()
{
    cout << countBST(6) << endl;
    cout << countBST2(6) << endl;
    return 0;
}