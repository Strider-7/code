#include <bits/stdc++.h>

using namespace std;

int MSIS(int arr[], int n)
{
    int msis[n];
    msis[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        msis[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                msis[i] = max(msis[i], arr[i] + msis[j]);
    }

    return *max_element(msis, msis + n);
}

int main()
{
    int arr[] = {3, 20, 4, 6, 7, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << MSIS(arr, n);

    return 0;
}