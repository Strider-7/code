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

int main()
{
    int arr[] ={ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    decreaseKey(arr, n, 7, 0);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }





    return 0;
}