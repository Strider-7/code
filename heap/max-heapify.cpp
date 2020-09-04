#include <bits/stdc++.h>

using namespace std;

int left(int i) {
    return (2*i+1);
}
int right(int i) {
    return 2*i+2;
}

void maxHeapify(int arr[], int n, int i) {

    int lChild=left(i);
    int rChild=right(i);
    int greatest=i;
    if (lChild<n && arr[lChild]>arr[greatest])
        greatest=lChild;

    if (rChild<n && arr[rChild]>arr[greatest])
        greatest=rChild;

    if (greatest!=i)
    {
        swap(arr[i], arr[greatest]);
        maxHeapify(arr, n, greatest);
    }
}

int main()
{
    int arr[] ={ 18,11,17,10,15,16 };

    int n = sizeof(arr) / sizeof(arr[0]);

    maxHeapify(arr,n,1);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    




    return 0;
}