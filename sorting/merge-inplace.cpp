#include <bits/stdc++.h>
using namespace std;

void merge(int X[], int Y[], int m, int n)
{
	// consider each element X[i] of array X and ignore the element
	// if it is already in correct order else swap it with next smaller
	// element which happens to be first element of Y
	for (int i = 0; i < m;  i++)
	{
		// compare current element of X[] with first element of Y[]
		if (X[i] > Y[0])
		{
			swap(X[i], Y[0]);
			int first = Y[0];

			// move Y[0] to its correct position to maintain sorted
			// order of Y[]. Note: Y[1..n-1] is already sorted
			int k;
			for (k = 1; k < n && Y[k] < first; k++) {
				Y[k - 1] = Y[k];
			}

			Y[k - 1] = first;
		}
	}
}

int main()
{

    int arr[] = {1, 5, 9, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {2, 3, 8, 13};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    merge(arr, arr1, n, n1);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto &&i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}