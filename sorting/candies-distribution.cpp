#include <bits/stdc++.h>
using namespace std;

int minDiff(int arr[], int n, int m)
{
    if (m > n)
        return -1;
    int res = 0;
    sort(arr, arr + n);
    res = arr[m - 1] - arr[0];
    for (int i = 1; i < n - m + 1; i++)
    {
        res = min(res, arr[i + m - 1] - arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {7,3,2,4,9,12,56};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDiff(arr, n, 3);
    return 0;
}
