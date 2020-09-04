#include <bits/stdc++.h>

using namespace std;

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return (2*i+1);
}
int right(int i) {
    return 2*i+2;
}

void decreaseKey(int arr[], int n, int i, int x) {
    arr[i]=x;
    while (i!=0 && arr[parent(i)]>arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i=parent(i);
    }

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

int deleteKey(int arr[], int n, int i) {
    decreaseKey(arr, n, i, INT32_MIN);
    return extractMin(arr, n);

}

int main()
{
    int arr[] ={ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    deleteKey(arr, n, 2);
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    deleteKey(arr, n, 5);

    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;





    return 0;
}