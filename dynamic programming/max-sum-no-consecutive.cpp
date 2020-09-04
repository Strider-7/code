#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int i = 0)
{
    if (i >= n)
        return 0;

    return max(maxSum(arr, n, i + 1), arr[i] + maxSum(arr, n, i + 2));
}

int maxSum2(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);
    return max(maxSum2(arr, n - 1), arr[n - 1] + maxSum2(arr, n - 2));
}

int maxSum3(int arr[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);

    return dp[n];
}
// space optimized
int maxSum4(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;
    for (int i = 3; i <= n; i++)
    {
        res = max(prev, arr[i - 1] + prev_prev);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main()
{
    int arr[] = {10, 15, 15, 20, 2, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    cout << maxSum2(arr, n) << endl;
    cout << maxSum3(arr, n) << endl;
    cout << maxSum4(arr, n) << endl;
    return 0;
}
