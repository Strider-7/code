#include <bits/stdc++.h>
using namespace std;
void printTriplets(int A[], int n)
{
    for (int j = 1; j < n - 1; j++)
    {
        // start with left and right index of j
        int i = j - 1, k = j + 1;

        // Find all i and k such that (i, j, k) forms a triplet of AP
        while (i >= 0 && k < n)
        {
            // if (A[i], A[j], A[k]) forms a triplet
            if (A[i] + A[k] == 2 * A[j])
            {
                // print the triplet
                printf("%d %d %d\n", A[i], A[j], A[k]);

                // Since the array is sorted and elements are distinct
                k++, i--;
            }
            // else if (A[i] + A[k]) is less than 2*A[j] then
            // try next k. Else, try previous i.
            else if (A[i] + A[k] < 2 * A[j])
            {
                k++;
            }
            else
            {
                i--;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 8, 9, 11, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTriplets(arr, n);

    return 0;
}