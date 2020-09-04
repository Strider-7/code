#include <bits/stdc++.h>

using namespace std;

int nCrModp(int n, int r)
{ // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    long long p = pow(10, 9) + 7;
    int C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] % p + C[j - 1] % p) % p;
    }
    return C[r];
}