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

int lomuto(int arr[], int l, int h)
{
    int pivot = arr[h], i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);

    return i + 1;
}

void quickLomuto(int arr[], int l, int h)
{
    if (l < h)
    {
        int partition = lomuto(arr, l, h);
        quickLomuto(arr, l, partition - 1);
        quickLomuto(arr, partition + 1, h);
    }
}

void quickHoare(int arr[], int l, int h)
{
    if (l < h)
    {
        int partition = hoare(arr, l, h);
        quickHoare(arr, l, partition);
        quickHoare(arr, partition + 1, h);
    }
}

int main()
{
    int arr[] = {8, 3, 4, 2, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // quickLomuto(arr, 0, n - 1);
    quickHoare(arr, 0, n);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}