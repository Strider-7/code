#include <bits/stdc++.h>

using namespace std;
int fun1 = 0, fun2 = 0;
int minJumps(int arr[], int n, int start = 0)
{
    fun1++;
    if (start == n - 1)
        return 0;

    int res = INT32_MAX;
    for (int i = 1; i <= arr[start]; i++)
        if (start + i < n)
            res = min(res, 1 + minJumps(arr, n, start + i));
    return res;
}

// better i think
int minJumps2(int arr[], int n)
{
    fun2++;
    if (n == 1)
        return 0;

    int res = INT32_MAX;
    for (int i = 0; i <= n - 2; i++)
        if (arr[i] + i >= n - 1)
        {
            int curr = minJumps2(arr, i + 1);
            if (curr != INT32_MAX)
                res = min(res, 1 + curr);
        }

    return res;
}

// bottom-up dp
int minJumps3(int arr[], int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT32_MAX;
        for (int j = 0; j < i; j++)
            if (j + arr[j] >= i)
            {
                if (dp[j] != INT32_MAX)
                    dp[i] = min(dp[i], 1 + dp[j]);
            }
    }
    return dp[n - 1];
}

int main()
{
    int arr[] = {3, 4, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << minJumps(arr, n) << " " << fun1 << endl;
    // cout << minJumps2(arr, n) << " " << fun2 << endl;
    cout << minJumps3(arr, n);
}