#include <bits/stdc++.h>
using namespace std;

int maxSumOfSubArray(int arr[], int n)
{
    int prevSum = arr[0], maxSum = arr[0];

    for (int i = 0; i < n; i++)
    {
        int currSum = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(currSum, maxSum);
            // cout << maxSum << endl;
        }
    }

    return maxSum;
}

int maxSum(int arr[], int n)
{
    int prevMax = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    { 
        prevMax = max(arr[i] + prevMax, arr[i]);
        res = max(prevMax, res);
    }
    return res;
}

int main()
{
    int arr[6] = {-11, 8, 30, -5, 20, -17};
    cout << maxSumOfSubArray(arr, 6) << endl;
    cout << maxSum(arr, 6) << endl;

    return 0;
}