#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> res;
    int i = 0, j = 0, last = 0;
    while (i < n && j < m)
    {

        if (arr1[i] == last)
        {
            i++;
            continue;
        }
        if (arr2[j] == last)
        {
            j++;
            continue;
        }
        if (arr1[i] < arr2[j])
        {
            last = arr1[i];
            res.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            last = arr1[i];
            res.push_back(arr1[i]);
            j++;
            i++;
        }
        else
        {
            last = arr2[j];
            res.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n)
    {
        if (arr1[i] != last)
        {
            last = arr1[i];
            res.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (arr2[j] != last)
        {
            last = arr2[j];
            res.push_back(arr2[j]);
        }
        j++;
    }

    return res;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {1, 2, 5, 7, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> v = findUnion(arr, arr1, n, n1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}