#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int i = 0)
{
    int x = maxSum(arr, n, i + 1);
    return max({arr[i] + maxSum(arr, n, i + 1), maxSum(arr, n, i + 1), arr[i]});
}

int maxSum2(int arr[], int n)
{
    int prevMax = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        prevMax = max({arr[i] + prevMax, arr[i], prevMax});
        res = max(prevMax, res);
    }
    return res;
}

int main(){
    int arr[]={1,2,-3,4};
    cout<<maxSum2(arr,4);
    return 0;
}