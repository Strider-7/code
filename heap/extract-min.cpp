#include <bits/stdc++.h>

using namespace std;

int left(int i) {
    return (2*i+1);
}
int right(int i) {
    return 2*i+2;
}

void minHeapify(int arr[], int n, int i) {

    int lChild=left(i);
    int rChild=right(i);
    int smallest=i;
    if (lChild<n && arr[lChild]<arr[smallest])
        smallest=lChild;

    if (rChild<n && arr[rChild]<arr[smallest])
        smallest=rChild;

    if (smallest!=i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int n) {
    int x=arr[0];
    arr[0]=arr[n-1];
    minHeapify(arr, n, 0);
    return x;
}

int main()
{
    int arr[] ={ 5, 1, 3, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    minHeapify(arr, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"\n"<<extractMin(arr,n);
    cout<<"\n"<<extractMin(arr,n);
    cout<<"\n"<<extractMin(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;
}