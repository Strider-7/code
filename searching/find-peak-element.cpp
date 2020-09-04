#include <bits/stdc++.h>
using namespace std;

vector<int> findPeak(int arr[], int n)
{
    vector<int> res;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            res.push_back(arr[mid]);

        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int main()
{

    int arr[] = {10, 70, 40, 60, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = findPeak(arr, n);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}