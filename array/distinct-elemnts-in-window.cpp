#include <bits/stdc++.h>
using namespace std;

void distinctsInSubArray(int arr[], int n, int k)
{
    int curr = 0;
    vector<int> res;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    curr = mp.size();
    res.push_back(curr);
    for (int i = k; i < n; i++)
    {
        mp[arr[i]]++;
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);
        curr = mp.size();
        res.push_back(curr);
    }
    for (auto &&i : res)
    {
        cout << i << " ";
    }
}

int maxDistinct(int arr[], int n, int k)
{
    int curr = 1;
    int res = 1;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    curr = mp.size();
    res = curr;
    for (int i = k; i < n; i++)
    {
        mp[arr[i]]++;
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);
        curr = mp.size();
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[7] = {1, 2, 1, 3, 4, 3, 3};
    distinctsInSubArray(arr, 7, 4);
    cout << endl;
    cout << maxDistinct(arr, 7, 4) << endl;

    return 0;
}