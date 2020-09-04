

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr
int minNumber(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (mid == 0)  
        return arr[mid];
    if (arr[mid - 1] > arr[mid])
        return arr[mid];
    if (arr[mid + 1] < arr[mid])
        return arr[mid + 1];
    if (arr[mid] < arr[high])
        return minNumber(arr, low, mid);
    else
        return minNumber(arr, mid, high);
}

int main()
{
    int arr[] = {60, 10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minNumber(arr, 0, n-1);
    return 0;
}