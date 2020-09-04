// each element in sorted array at inde i is in the original array in range {i-k,i+k};
#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

void sortKSortedArray(int arr[], int n, int k) {
    priority_queue <int, vector <int>, greater <int>> pq;
    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);
    int index=0;
    for (int i = k+1; i <n; i++)
    {
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        arr[index++]=pq.top();
        pq.pop();
    }

}

int main()
{
    int arr[] ={ 9, 8, 7, 19, 18 };

    int n = sizeof(arr) / sizeof(arr[0]);

    sortKSortedArray(arr, n, 2);



    display(arr, n);







    return 0;
}