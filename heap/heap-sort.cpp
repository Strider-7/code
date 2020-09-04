#include <bits/stdc++.h>

using namespace std;

int left(int i) {
    return (2*i+1);
}
int right(int i) {
    return 2*i+2;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

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

void buildHeap(int arr[], int n) {
    for (int i = (n-2)/2; i >= 0; i--)
        maxHeapify(arr, n, i);

}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    display(arr, n);
    for (int i = n - 1; i>= 1; i--)
    {
        swap(arr[0], arr[i]); /*swap first node with last node and then max_heapify until i ==1*/
        maxHeapify(arr, i, 0);  /*i=heap_size*/
    }

}

int main()
{
    int arr[] ={ 5, 4, 6, 13, 8, 15, 1, 3, 10, 9, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    display(arr, n);







    return 0;
}