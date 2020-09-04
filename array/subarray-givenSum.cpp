// subarray of given sum=k present?
#include <bits/stdc++.h>
using namespace std;
bool subArrayWithGivenSum(int arr[], int n, int k) 
{
    unordered_set<int> s;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (s.find(prefixSum-k) != s.end())
        {
            return true;
        }
        if (prefixSum == k)
            return true;
        s.insert(prefixSum);
    }
    return false;
}

bool isSubSum(int arr[], int n, int k)
{
    int currSum = arr[0], s = 0;
    for (int e = 1; e < n; e++)
    {
        while (currSum > k && s < e - 1)
        {
            currSum -= arr[s];
            s++;
        }
        if (currSum == k)
            return true;
        if (e < n)
        {
            currSum += arr[e];
        }
    }
    return (currSum == k);
}

int main()
{
    int arr[6] = {1, 4, 20, 3, 10, 5};
    int arr2[6] = {1, 3, 4, 5, 10, 20};
    // int arr[] = {1, 5, 3, -6, 4, -1};
    // int n = sizeof(arr) / sizeof(arr[0]);
    cout << subArrayWithGivenSum(arr2, 6, 19);
    // cout<<isSubSum(arr,6,33);
    // cout<<isSubSum(arr,6,10);
    // cout << isSubSum(arr, n, 0);
    return 0;
}