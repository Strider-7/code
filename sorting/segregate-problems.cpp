#include <bits/stdc++.h>
using namespace std;

void sortPosNeg(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < 0);
        do
        {
            j--;
        } while (arr[j] >= 0);

        if (i >= j)
            return;

        swap(arr[i], arr[j]);
    }
}

void sortOddEven(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] % 2 == 1);
        do
        {
            j--;
        } while (arr[j] % 2 == 0);

        if (i >= j)
            return;

        swap(arr[i], arr[j]);
    }
}

void sortBinary(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] == 0);
        do
        {
            j--;
        } while (arr[j] == 1);

        if (i >= j)
            return;

        swap(arr[i], arr[j]);
    }
}

void sortEvenAndOdd(int arr[], int n)
{
    int temp[n], i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] % 2 == 1)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] % 2 == 0)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> sortArrayByParity(vector<int> &A)
{
    auto is_even = [](auto e) { return e % 2 == 0; };
    partition(A.begin(), A.end(), is_even);
    return A;
}

int main()
{
    int arr[] = {3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortOddEven(arr, n);
    display(arr, n);

    // int arr1[] = {-5, 2, 4, 8, -6, -9, 10};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // sortPosNeg(arr1, n1);
    // display(arr1, n1);

    // int arr2[] = {0, 0, 1, 1, 0, 1, 1, 0, 0, 0};
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // sortBinary(arr2, n2);
    // display(arr2, n2);

    return 0;
}