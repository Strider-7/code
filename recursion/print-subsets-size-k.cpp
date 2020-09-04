#include <bits/stdc++.h>
using namespace std;

void display(vector<int> v)
{
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void allSubSets(int arr[], int n, int k, vector<int> curr={}, int index = 0)
{

    if (index == n)
    {
        if (curr.size() == k)
            display(curr);
        return;
    }

    allSubSets(arr, n, k, curr, index + 1);
    curr.push_back(arr[index]);
    allSubSets(arr, n, k, curr, index + 1);
}

int main()
{
    int arr1[] = {26, 9, 27, 22, 16};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    allSubSets(arr1, n1, 3);

    return 0;
}