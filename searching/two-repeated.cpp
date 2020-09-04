#include <bits/stdc++.h>
using namespace std;

void twoRepeated(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
            cout << abs(arr[i]) << endl;
        arr[abs(arr[i])] *= -1;
    }
}

vector<int> findDuplicates(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
            res.push_back(abs(arr[i]));
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    return res;
}

int main()
{
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    twoRepeated(arr, n);
    vector<int> v(arr, arr + n);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> x;
    x = findDuplicates(v);
    for (auto &&i : x)
    {
        cout << i << " ";
    }

    return 0;
}