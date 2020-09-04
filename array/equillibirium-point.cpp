#include <bits/stdc++.h>
using namespace std;

bool equillibiriumExist(int arr[], int n)
{
    int prefixSum[n];
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && prefixSum[n - 1] - prefixSum[i] == 0)
        {
            cout << arr[i] << endl;
            return true;
        }
        if (i == n - 1 && prefixSum[n - 2] == 0)
        {
            cout << arr[i] << endl;
            return true;
        }
        else
        {
            if (prefixSum[i - 1] == prefixSum[n - 1] - prefixSum[i])
            {
                cout << arr[i] << endl;
                return true;
            }
        }
    }
    return false;
}

bool equillibirium(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);
    int lSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (lSum == sum - arr[i])
            return true;

        lSum += arr[i];
        sum -= arr[i];
    }
    return false;
}

int main()
{
    int arr[] = {1, 3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << equillibiriumExist(arr, n);
    cout << equillibirium(arr, n) << endl;
    return 0;
}