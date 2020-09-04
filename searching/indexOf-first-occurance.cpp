#include <bits/stdc++.h>
using namespace std;

int indexOfFirstOccurance(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (x > arr[mid])
        return indexOfFirstOccurance(arr, mid + 1, high, x);
    else if (x < arr[mid])
        return indexOfFirstOccurance(arr, low, mid - 1, x);

    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;

        else
            return indexOfFirstOccurance(arr, low, mid - 1, x);
    }
}

int firstOccurance(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            if (mid == 0 || arr[mid] != arr[mid - 1])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5,10,10,15,20,20,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << indexOfFirstOccurance(arr, 0, n - 1, 20) << endl;
    
    cout << firstOccurance(arr, n, 20) << endl;

    return 0;
}