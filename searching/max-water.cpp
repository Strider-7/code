// Given an integer array representing the heights of N buildings,
// the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum.
// Note: The total water trapped between two buildings is gap between them
//  (number of buildings removed) multiplied by height of the smaller building.

#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
    int curr = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            curr = (j - i - 1) * min(arr[i], arr[j]);
            res = max(res, curr);
        }
    }
    return res;
}

int maxWater2(int arr[], int n)
{
    int i = 0, j = n - 1, curr = 0, res = 0;
    while (i < j)
    {
        curr = (j - i - 1) * min(arr[i], arr[j]);
        res = max(res, curr);
        if (arr[i] < arr[j])
            i++;
        else
            j--;
    }
    return res;
}

int main()
{
    int arr[] = {2, 1, 3, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxWater(arr, n) << endl;
    cout << maxWater2(arr, n) << endl;
    return 0;
}