#include <bits/stdc++.h>

using namespace std;
// not best soln probably wrong
int maxPoints(vector<int> &v, int start, int end, bool turn = true)
{
    cout << v[start] << " " << v[end] << " " << turn << endl;
    if (start > end)
        return 0;
    if (turn)
        return max(v[start] + maxPoints(v, start + 1, end, !turn), v[end] + maxPoints(v, start, end - 1, !turn));
    else
        return v[start] > v[start] ? maxPoints(v, start + 1, end, !turn) : maxPoints(v, start, end - 1, !turn);
}

// opponent playing as smart as us

int maxPoints2(vector<int> &arr, int i, int j)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);

    return max(arr[i] + min(maxPoints2(arr, i + 2, j), maxPoints2(arr, i + 1, j - 1)),
               arr[j] + min(maxPoints2(arr, i, j - 2), maxPoints2(arr, i + 1, j - 1)));
}

int maxPoints3(vector<int> &arr)
{
    int n = arr.size();
    int dp[n + 1][n + 1];

    // recursion base case
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = max(arr[i], arr[i] + 1);

    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                           arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
        }
    }

    // solution at dp[0][n-1];
    return dp[0][n - 1];
}

int main()
{
    vector<int> v = {10, 20, 4, 5, 6, 8, 3};
    cout << maxPoints(v, 0, v.size() - 1) << endl;
    // cout << maxPoints2(v, 0, v.size() - 1) << endl;
    // cout << maxPoints3(v) << endl;

    return 0;
}