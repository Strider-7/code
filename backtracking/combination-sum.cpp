#include <bits/stdc++.h>

using namespace std;

void fun(vector<int> &A, int sum, vector<vector<int>> &result, vector<int> current, int pos)
{

    if (sum == 0)
    {
        result.push_back(current);
        return;
    }
    if (sum < 0 || pos >= A.size())
        return;

    current.push_back(A[pos]);
    fun(A, sum - A[pos], result, current, pos);
    current.pop_back();
    fun(A, sum, result, current, pos + 1);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    vector<vector<int>> result;
    vector<int> current, C;
    int i, j;
    for (i = 0; i < A.size(); i++)
    {
        j = i + 1;
        while (j < A.size() && A[i] == A[j])
        {
            j++;
        }
        C.push_back(A[i]);
        i = j - 1;
    }

    fun(C, B, result, current, 0);
    return result;
}