// C++ program to find out maximum value from a
// given sequence of coins
#include <bits/stdc++.h>
using namespace std;

int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);

    // For both of your choices, the opponent
    // gives you total sum minus maximum of
    // his value
    return max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
               (sum - oSRec(arr, i, j - 1, sum - arr[j])));
}

// Returns optimal value possible that a player can
// collect from an array of coins of size n. Note
// than n must be even
int optimalStrategyOfGame(int *arr, int n)
{
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);
    return oSRec(arr, 0, n - 1, sum);
}

// Driver program to test above function
int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 4, 5, 6, 8, 3};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3, n));

    return 0;
}
