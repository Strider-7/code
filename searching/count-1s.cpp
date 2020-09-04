#include <bits/stdc++.h>
using namespace std;
int count1(int arr[], int n)
{
    // int res = 0;
    int low = 0, high = n, mid = 0;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == 0)
        {
            high = mid - 1;
            if (arr[high] == 1)
                return high + 1;
        }
        else
        {
            low = mid + 1;
            if (arr[low] != 1)
                return low;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {1,1,1,0,0,0,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << count1(arr, n);
    return 0;
}