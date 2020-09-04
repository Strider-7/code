// each element in sorted array at inde i is in the original array in range {i-k,i+k};
#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

void kLargestElements(int arr[], int n, int k) {
    priority_queue <int, vector <int>, greater <int>> pq(arr, arr+k);
    // for (int i = 0; i < k; i++)
    //     pq.push(arr[i]);
    for (int i = k; i < n; i++)
    {
        if (arr[i]>pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }



}


int main()
{
    int arr[] ={ 3,2,5,6,4 };

    int n = sizeof(arr) / sizeof(arr[0]);

    kLargestElements(arr,n,2);



    return 0;
}