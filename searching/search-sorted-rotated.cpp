#include <bits/stdc++.h>
using namespace std;

int searchRec(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;

    if (arr[mid] > arr[low])
    {
        if (key >= arr[low] && key < arr[mid])
            return searchRec(arr, low, mid-1, key);

        else
            return searchRec(arr, mid + 1, high, key);
    }
    else
    {
        if (key > arr[mid] && key <= arr[high])
            return searchRec(arr, mid + 1, high, key);

        else
            return searchRec(arr, low, mid-1, key); 
    }
    return -1;
}

int main()
{

    int arr[] = {3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << searchRec(arr, 0, n - 1, 1);
    return 0;
}