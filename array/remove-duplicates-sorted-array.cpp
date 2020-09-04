#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int size = 1;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[size - 1])
        {
            arr[size] = arr[j];
            size++;
        }
    }
    
    return size;
}

int main()
{
    int arr[6] = {1, 1, 2, 3, 3, 3};
    cout << removeDuplicates(arr, 6);

    return 0;
}