#include <bits/stdc++.h>
using namespace std;

int intersection(int arr1[], int arr2[], int n1, int n2)
{
    int res = 0;
    unordered_set<int> s1;

    for (int i = 0; i < n1; i++)
        s1.insert(arr1[i]);
    for (int i = 0; i < n2; i++)
    {
        if (s1.count(arr2[i]))
        {
            res++;
            s1.erase(arr2[i]);
        }
    }

    return res;
}

int main()
{

    int arr1[] = {1, 2, 2, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 2, 4, 6, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << intersection(arr1, arr2, n1, n2);

    return 0;
}