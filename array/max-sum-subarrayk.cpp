#include <bits/stdc++.h>
using namespace std;

int maxSumOfSubArray(int arr[], int n, int k)
{
    int currSum = 0, maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }
    maxSum = currSum;

    for (int i = k; i < n; i++)
    {
        currSum = currSum + arr[i] - arr[i - k];
        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}

int main()
{
    int arr[6] = {1, 8, 30, -5, 20, 7};
    cout << maxSumOfSubArray(arr, 6, 3);

    return 0;
}