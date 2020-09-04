// Given a sorted array of positive integers (elements may be repeated) and a number x.
//  The task is to find the leftmost index of x in the given array.

#include <bits/stdc++.h>
using namespace std;

int leftIndex(int N, int arr[], int X)
{

    int low = 0, high = N;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((arr[mid] == X && arr[mid - 1] != X)||(arr[mid]==X && mid==0))
            return mid;
        if (arr[mid] >= X)
            high = mid - 1;
        if (arr[mid] < X)
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 10, 144, 144, 177, 177};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << leftIndex(n, arr, 10) << endl;

    return 0;
}