#include <bits/stdc++.h>
using namespace std;

bool zeroSumSubarr(int arr[], int n)
{
    unordered_set<int> s;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (s.find(prefixSum) != s.end())
        { 
            return true;
        }
        if (prefixSum == 0)
            return true;
        s.insert(prefixSum); 
    }
    return false;
}

int main()
{

    int arr[] = {1, 5, 3, -6, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << zeroSumSubarr(arr, n);

    return 0;
}