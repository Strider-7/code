#include <bits/stdc++.h>
using namespace std;

int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto &&i : mp)
    {
        if (i.second > n / k)
            res++;
    }
    return res;
}

int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countOccurence(arr, n, 4);

    return 0;
}