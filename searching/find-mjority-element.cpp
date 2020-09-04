#include <bits/stdc++.h>
using namespace std;

int majority(int arr[], int n)
{
    int res = 0, count = 1; 
    for (int i = 1; i < n; i++)
    {
        if (i == res)
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            res = i;
        }
    }
    return arr[res];
}

int main()
{
    int arr[] = {3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << majority(arr, n);
    return 0;
}