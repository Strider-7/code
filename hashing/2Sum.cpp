#include <bits/stdc++.h>
using namespace std;

pair<int, int> sum(int arr[], int n, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {
        if (s.count(k - arr[i]))
            return make_pair(arr[i], k - arr[i]);
    }
    return make_pair(0, 0);
}

int countPair(int arr[], int n, int k)
{
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    for (int i = 0; i < n; i++)
    {
        if (s.count(k - arr[i]))
        {
            cout << arr[i] << " " << k - arr[i] << endl;
            res++;
            s.erase(k - arr[i]);
            s.erase(arr[i]);
        }
    }
    return res;
}

bool sumExists(int arr[], int n, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    // for (auto &&i : s)
    // {
    //     cout << i << " ";
    // }

    for (int i = 0; i < n; i++)
    {

        if (s.count(k - arr[i]) && arr[i] != k / 2)
            return true;
    }
    return false;
}

int main()
{

    int arr1[] = {1, 11, 1, 12, 3, 9, 9, 3, 4, 8, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // pair<int, int> p = sum(arr1, n1, 7);
    // cout << p.first << " " << p.second;
    // cout << countPair(arr1, n1, 12);
    int arr[] = {2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumExists(arr, n, 10);

    return 0;
}