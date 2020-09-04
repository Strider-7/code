#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> &arr, int i, int j)
{
    int sum = 0;
    for (int c = 0; c < 3; c++)
    {
        sum += arr[i][j + c];
        sum += arr[i + 2][j + c];
    }
    return sum + arr[i + 1][j + 1];
}

int maxSum(vector<vector<int>> &arr)
{
    int res = INT32_MAX;
    for (int i = 0; i < 4; i++)
    {
        int curr = 0;
        for (int j = 0; j < 4; j++)
        {
            curr = hourglassSum(arr, i, j);
        }
        res = max(res, curr);
    }
    return res;
}

int main()
{
    vector<vector<int>> arr(6, vector<int>(6));
    for (int arr_i = 0; arr_i < 6; arr_i++)
    {
        for (int arr_j = 0; arr_j < 6; arr_j++)
        {
            cin >> arr[arr_i][arr_j];
        }
    }
    cout << maxSum(arr);
    return 0;
}