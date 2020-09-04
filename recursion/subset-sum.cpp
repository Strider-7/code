#include <bits/stdc++.h>
using namespace std;

int subsets(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;

    return subsets(arr, n - 1, sum) + subsets(arr, n - 1, sum - arr[n-1]);
}

int main()
{
    int arr[5] = {10, 5, 2, 3, 6};
    cout << "subsets with sum = 15: " << subsets(arr, 5, 15) << endl;

    return 0;
}