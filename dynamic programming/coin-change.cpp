#include <bits/stdc++.h>

using namespace std;

// wrong probably

// void totalWays(vector<int> &v, int sum, int &res, int i = 0)
// {
//     if (sum == 0)
//     {
//         res++;
//         return;
//     }
//     if (i == v.size() || sum < 0)
//         return;
//     totalWays(v, sum - v[i], res, i);
//     totalWays(v, sum - v[i], res, i + 1);
// }
// // Same as above
// int total(vector<int> &v, int sum, int i = 0)
// {
//     if (sum == 0)
//         return 1;
//     if (i == v.size() || sum < 0)
//         return 0;
//     return total(v, sum - v[i], i) + total(v, sum - v[i], i + 1);
// }

int getCount(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int res = getCount(arr, n - 1, sum);
    if (arr[n - 1] <= sum)
        res += getCount(arr, n, sum - arr[n - 1]);
    return res;
}

int totalCount(int coins[], int n, int sum)
{
    int dp[sum + 1][n + 1];
    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 1;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coins[j - 1] <= i)
                dp[i][j] += dp[i - coins[j - 1]][j];
        }
    }

    return dp[sum][n]; 
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

    vector<int> v = {1, 3, 2};
    // int res = 0;
    // totalWays(v, 6, res);
    // cout << res << endl;
    // cout << total(v, 6) << endl;
    int arr[] = {3,5,10};

    cout << getCount(arr, 3, 20) << endl;
    // cout << totalCount(arr, 3, 9) << endl;

    return 0;
}