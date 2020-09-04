// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int maxDifference(int arr[], int n)
{
    int currDiff, maxDiff;
    currDiff = maxDiff = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            currDiff = arr[j] - arr[i];
            if (currDiff > maxDiff)
                maxDiff = currDiff;
        }
    }
    return maxDiff;
}

int maxDiff(int arr[], int n)
{
    int res = arr[1] - arr[0];
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    return res;
}

int main()
{
    int arr[7] = {2, 3, 10, 6, 4, 8, 1};
    cout << maxDifference(arr, 7) << endl;
    cout << maxDiff(arr, 7);

    return 0;
}