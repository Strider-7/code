#include <bits/stdc++.h>

using namespace std;

bool findPartition2(int arr[], int n, int &total, int curr = 0)
{

    if (n == 0)
        return false;
    if (curr == total / 2)
        return true;

    return findPartition2(arr, n - 1, total, curr) ||
           findPartition2(arr, n - 1, total, curr + arr[n - 1]);
}

bool findPartition(int arr[], int n)
{

    int total = accumulate(arr, arr + n, 0);
    if (total % 2 == 1)
        return false;
    return findPartition2(arr, n, total);
}

bool findPartition(int arr[], int n) {
       
    int total=accumulate(arr,arr+n,0);
    if(total%2==1)
        return false;
    int sum=total/2;
    bool dp[sum+1][n + 1];
    for (int i = 0; i <= sum; i++)
        dp[i][0] = false;

    for (int j = 1; j <=n; j++)
        dp[0][j] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[sum][n];
}

int main()
{

    int arr[] = {1, 2, 3, 5, 4, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPartition(arr, n);
}