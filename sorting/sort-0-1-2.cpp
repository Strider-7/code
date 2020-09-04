#include <bits/stdc++.h>
using namespace std;

// group 0,1,2 together

void sort(int arr[], int n)
{
    int l = 0, mid = 0, h = n - 1;
    while (mid <= h)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[l], arr[mid]);
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[h]);
            h--;
            break;

        default:
            break;
        }
    }
}



int main()
{

    int arr[] = {2, 1, 2, 0, 2, 0, 1, 2, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}