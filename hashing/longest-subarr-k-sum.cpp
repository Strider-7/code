#include <bits/stdc++.h>
using namespace std;

int longestSumSubarr(int arr[], int n, int k)
{
    unordered_multimap<int, int> mp;
    int prefixSum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == k)
            res = i + 1;
        if (mp.find(prefixSum) == mp.end())
            mp.insert({prefixSum, i});

        auto itr = mp.find(prefixSum - k);

        if (itr != mp.end())
        {
            res = max(res, i - itr->second);
            // cout << itr->second << " " << i << endl;
        }
    }
    for (auto &&i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }

    return res;
}

int main()
{

    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSumSubarr(arr, n, -10);

    return 0;
}