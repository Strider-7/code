#include <bits/stdc++.h>
using namespace std;

int minElement(int arr[], int left, int right)
{
    if (left + 1 == right)
        return 0;
    int res = INT32_MAX;
    for (int i = left + 1; i < right; i++)
        res = min(res, minElement(arr, left, i) + minElement(arr, i, right) + arr[left] * arr[i] * arr[right]);

    return res;
}

int mChain(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT32_MAX;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int arr[] = {2, 1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minElement(arr, 0, n - 1) << endl;
    cout << mChain(arr, n);

    return 0;
}