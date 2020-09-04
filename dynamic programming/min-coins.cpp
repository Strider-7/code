#include <bits/stdc++.h>

using namespace std;

int minCoins(int arr[], int n, int sum)
{
    if (sum == 0)
        return 0;
    if (sum < 0)
        return INT32_MAX;
    int res = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sum)
            res = min(res, 1 + minCoins(arr, n, sum - arr[i]));
    }
    return res;
}

// dp approach
int minimumCoins(int coins[], int n, int sum)
{
    int dp[sum + 1];
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        dp[i] = INT32_MAX;
        for (int j = 0; j < n; j++)
            if (coins[j] <= i)
            {
                int curr = dp[i - coins[j]];
                if (curr != INT32_MAX)
                    dp[i] = min(dp[i], 1 + curr);
            }
    }
    return dp[sum];
}
// optimization over all combinations instead of all permutations
int coinChange(vector<int> &coins, int amount)
{
    vector<int> A(amount + 1, amount + 1);
    A[0] = 0;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            A[i] = min(A[i], A[i - coin] + 1);
        }
    }
    return A[amount] > amount ? -1 : A[amount];
}

// optimal
void helper(vector<int> &coins, int start, int target, int cur, int &res)
{
    if (start < 0)
        return;
    if (target % coins[start] == 0)
    {
        res = min(res, cur + target / coins[start]);
        return;
    }
    for (int i = target / coins[start]; i >= 0; --i)
    {
        if (cur + i >= res - 1)
            break;
        helper(coins, start - 1, target - i * coins[start], cur + i, res);
    }
}

int coinChange2(vector<int> &coins, int amount)
{
    int res = INT_MAX, n = coins.size();
    sort(coins.begin(), coins.end());
    helper(coins, n - 1, amount, 0, res);
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    int arr[] = {4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << minCoins(arr, n, 100);
    cout << minimumCoins(arr, n, 3);
}