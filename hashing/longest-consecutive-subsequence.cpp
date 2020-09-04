#include <bits/stdc++.h>
using namespace std;

int length(int arr[], int n)
{

    int res = 0, curr = 1;

    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i + 1] - arr[i] == 1)
            curr++;
        else
        {
            res = max(res, curr);
            curr = 1;
        }
    }

    res = max(res, curr);

    return res;
}

int maxLengthSubsequence(int arr[], int n)
{
    int res = 0;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        if (mp.find(arr[i] - 1) != mp.end())
            continue;

        while (mp.find(arr[i] + curr) != mp.end())
        {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{

    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << length(arr, n) << endl;
    cout << maxLengthSubsequence(arr, n);

    return 0;
}