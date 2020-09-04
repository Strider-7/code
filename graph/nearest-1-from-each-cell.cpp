#include <bits/stdc++.h>

using namespace std;

int distance(vector<vector<int>> &mat, int i, int j, int N, int M, vector<vector<int>> &res)
{
    if (i < 0 || i >= N || j < 0 || j >= M || mat[i][j] == 5)
        return INT32_MAX;
    if (mat[i][j] == 0)
        return 0;
    int x = mat[i][j];
    mat[i][j] == 5;
    int a = distance(mat, i, j - 1, N, M, res);
    int b = distance(mat, i, j + 1, N, M, res);
    int c = distance(mat, i - 1, j, N, M, res);
    int d = distance(mat, i + 1, j, N, M, res);

    res[i][j] = (x == 1) ? 0 : 1 + min({a, b, c, d});

    return res[i][j];
}

vector<vector<int>> nearest(vector<vector<int>> &mat, int N, int M)
{

    vector<vector<int>> res(N, vector<int>(M, 0));

    distance(mat, 0, 0, N, M, res);

    return res;
}

int main()
{
    vector<vector<int>> v = {{1, 0}, {0, 1}};
    v = nearest(v, 2, 2);
    for (auto &&i : v)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }
}