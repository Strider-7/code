#include <bits/stdc++.h>

using namespace std;

bool pathExists(vector<vector<int>> &M, int N, int i, int j, vector<vector<int>> &visited)
{
    cout << i << " " << j << endl;
    if (i >= N || j >= N || i < 0 || j < 0 || M[i][j] == 0 || visited[i][j]==1)
        return false;
    if (M[i][j] == 2)
        return true;
    visited[i][j]=1;
    return pathExists(M, N, i, j - 1, visited) || pathExists(M, N, i, j + 1, visited) ||
           pathExists(M, N, i + 1, j, visited) || pathExists(M, N, i - 1, j, visited);
}

bool is_possible(vector<vector<int>> &M, int N)
{
    vector<vector<int>> visited(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (M[i][j] == 1)
            {
                return pathExists(M, N, i, j, visited);
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 3, 0},
                               {3, 0, 3, 3},
                               {3, 3, 0, 3},
                               {0, 3, 3, 2}};
    cout << is_possible(mat, 4);

    return 0;
}