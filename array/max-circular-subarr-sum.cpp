#include <bits/stdc++.h>
using namespace std;

int maxCircularSum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int currSum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            currSum += arr[index];
            curr_max = max(curr_max, currSum);
        }
        res = max(res, curr_max);
    }
    return res;
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
    cout << res << endl;

    return res;
}

int maXSumCircular(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);
    int prevMin = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        prevMin = min(arr[i] + prevMin, arr[i]);
        res = min(prevMin, res);
    }
    cout << sum << " " << res << endl;
    return sum - res;
}

int maxSumCircularSubarray(int arr[], int n)
{
    return max(maxSum(arr, n), maXSumCircular(arr, n));
}

int maxSubarraySumCircular(vector<int> &A)
{
    int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
    for (int &a : A)
    {
        curMax = max(curMax + a, a);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + a, a);
        minSum = min(minSum, curMin);
        total += a;
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}

int main()
{
    int arr[6] = {-10, 20, 30, -31, 25, 25};
    cout << maxCircularSum(arr, 6) << endl;
    cout << maxSumCircularSubarray(arr, 6) << endl;
    vector<int> A(arr, arr + 6);
    cout << maxSubarraySumCircular(A) << endl;

    return 0;
}