#include <bits/stdc++.h>

using namespace std;

bool pathExists(vector<vector<int>> &M, int N, int i, int j, vector<vector<int>> &visited)
{
    // cout << i << " " << j << endl;
    if (i >= N || j >= N || M[i][j] == 0 )
        return false;
    visited[i][j] = 1;
    if (i == N - 1 && j == N - 1)
        return true;

    return pathExists(M, N, i, j + 1, visited) || pathExists(M, N, i + 1, j, visited);
}

bool is_possible(vector<vector<int>> &grid, int N)
{
    vector<vector<int>> visited(N, vector<int>(N, 0));
    bool res = pathExists(grid, N, 0, 0, visited);
    for (auto &&i : visited)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 0, 0, 1},
                               {1, 1, 0, 0},
                               {1, 1, 1, 1}};
    cout << is_possible(mat, 4);

    return 0;
}