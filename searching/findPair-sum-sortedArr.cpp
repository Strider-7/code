#include <bits/stdc++.h>
using namespace std;

pair<int, int> findPair(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    pair<int, int> p;
    while (low < high)
    {
        if (k == arr[low] + arr[high])
        {
            p.first = arr[low];
            p.second = arr[high];
            return p;
        }
        if (arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return p;
}

int countPair(int arr[], int n, int k)
{
    int low = 0, high = n - 1, count = 0;
    while (low < high)
    {
        if (k == arr[low] + arr[high])
            count++;

        if (arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return count;
}

int main()
{

    int arr[] = {1, 2, 4, 5, 19, 20, 22, 23, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countPair(arr, n, 24) << endl;

    return 0;
}