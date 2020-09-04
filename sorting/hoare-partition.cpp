#include <bits/stdc++.h>
using namespace std;

int hoare(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {8, 3, 4, 2, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << hoare(arr, 0, n);

    return 0;
}