// each element in sorted array at inde i is in the original array in range {i-k,i+k};
#include <bits/stdc++.h>

using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int maxItems(int arr[], int n, int k) {
    int res=0;
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        if (k<arr[i])
            break;
        k-=arr[i];
        res++;
    }
    return res;

}

int maxItems2(int arr[], int n, int k) {
    int res=0;
    priority_queue <int, vector <int>, greater <int>> pq(arr, arr+n);
    while (!pq.empty())
    {
        if (k<pq.top())
            break;
        k-=pq.top();
        res++;
        pq.pop();
    }
    return res;



}

int main()
{
    int arr[] ={ 20, 10, 5, 30, 111, 100 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<maxItems(arr, n, 35)<<endl;
    cout<<maxItems2(arr, n, 35)<<endl;

    return 0;
}