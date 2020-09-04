#include <bits/stdc++.h>
using namespace std;

void allSubSets(int arr[], int n, string curr = "", int index = 0)
{
    if (index == n)
    {
        cout << curr << " ";
        return;
    }
    allSubSets(arr, n, curr, index + 1);
    curr += to_string(arr[index]);
    allSubSets(arr, n, curr, index + 1);
}

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    allSubSets(arr1, n1);

    return 0;
}