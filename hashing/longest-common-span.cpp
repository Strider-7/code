// longest common span with equal sum
#include <bits/stdc++.h>
using namespace std;

int longestZeroSumSubarr(int arr[], int n)
{
    unordered_multimap<int, int> mp;
    int prefixSum = 0, res = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
            res = i + 1;
        if (mp.find(prefixSum) == mp.end())
            mp.insert({prefixSum, i});

        auto itr = mp.find(prefixSum);

        if (itr != mp.end())
        {
            res = max(res, i - itr->second);
        }
    }

    return res;
}

int longestCommonSpan(int arr1[], int arr2[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr1[i] - arr2[i];

    return longestZeroSumSubarr(temp, n);
}

int main()
{
    int arr1[] = {0, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 0, 0, 1, 0, 1};

    cout << longestCommonSpan(arr1, arr2, n);

    return 0;
}