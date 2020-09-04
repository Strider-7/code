#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low,int high){
    while (low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    
}

void leftRotateK(int arr[], int n, int k)
{
    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];

    for (int i = k; i < n; i++)
        arr[i - k] = arr[i];

    for (int i = 0; i < k; i++)
        arr[n - k + i] = temp[i];
}

void leftRotateKTimes(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // leftRotateK(arr, 5, 4);
    leftRotateKTimes(arr,5,4);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}