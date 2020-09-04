#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n)
{
    unordered_map<int, int> mp;
    int prefixSum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
            res++;

        auto itr = mp.find(prefixSum - 0);

        if (itr != mp.end())
            res += itr->second;
        mp[prefixSum]++;
    }

    return res;
}

int main()
{
    int arr[] = {0, 0, 5, 5, 0, 0};
    int n = sizeof(arr) / sizeof(int);
    cout << subArraySum(arr, n);

    return 0;
}