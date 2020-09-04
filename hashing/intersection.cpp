#include <bits/stdc++.h>
using namespace std;

vector<int> printIntersection(int arr1[], int arr2[], int N, int M)
{
    vector<int> res;
    int last = INT32_MIN;
    unordered_set<int> s;
    for (int i = 0; i < N; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < M; i++)
    {
        if (s.find(arr2[i]) != s.end())
        {
            res.push_back(arr2[i]);
            s.erase(arr2[i]);
        }
    }

    return res;
}

vector<int> intersection(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> res;
    int i = 0, j = 0, last = INT32_MIN;
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j] && arr1[i] != last)
        {
            last = arr1[i];
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
            j++;

        else
            i++;
    }

    return res;
}

int main()
{

    int arr1[] = {1, 2, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 2, 4, 6, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> v = printIntersection(arr1, arr2, n1, n2);
    // vector<int> v = intersection(arr1, arr2, n1, n2);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}