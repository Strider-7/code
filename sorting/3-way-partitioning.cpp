#include <bits/stdc++.h>
using namespace std;

vector<int> threeWayPartition(vector<int> arr, int a, int b)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] < a)
        {
            swap(arr[low], arr[mid]);
            ++low, ++mid;
        }
        else if (arr[mid] > b)
        {
            swap(arr[mid], arr[high]);
            --high;
        }
        else
            ++mid;
    }
    return arr;
}

int main()
{
    vector<int> v = {1, 80, 85, 99, 15, 18, 58, 75, 42, 66};
    v = threeWayPartition(v, 30, 60);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}