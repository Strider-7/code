// Given an array of positive integers, where elements are consecutive (sorted).
// Also, there is a single element which is repeating X (any variable) number of times.
//  Now, the task is to find the element which is repeated and number of times it is repeated.

#include <bits/stdc++.h>
using namespace std;

void countRepeated(int arr[], int n)
{
    int repeatCount = n - (arr[n - 1] - arr[0]);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((arr[mid] == arr[mid - 1]) || (arr[mid] == arr[mid + 1]))
        {
            cout << "repeated number: " << arr[mid] << " count: " << repeatCount;
            break;
        }
        if (arr[mid] - arr[low] == mid - low)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    int arr[] = {1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countRepeated(arr, n);
    return 0;
}