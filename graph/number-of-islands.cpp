#include <bits/stdc++.h>

using namespace std;

void mark_current_island(vector<int> matrix[], int x, int y, int r, int c)
{
    if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != 1)
        return;
    matrix[x][y] = 2;

    mark_current_island(matrix, x + 1, y, r, c);     //DOWN
    mark_current_island(matrix, x, y + 1, r, c);     //RIGHT
    mark_current_island(matrix, x - 1, y, r, c);     //TOP
    mark_current_island(matrix, x, y - 1, r, c);     //LEFT
    mark_current_island(matrix, x - 1, y - 1, r, c); //TOP-LEFT
    mark_current_island(matrix, x - 1, y + 1, r, c); //TOP-RIGHT
    mark_current_island(matrix, x + 1, y - 1, r, c); //BOTTOM-LEFT
    mark_current_island(matrix, x + 1, y + 1, r, c); //BOTTOM-RIGHT
}

int findIslands(vector<int> grid[], int N, int M)
{

    int no_of_islands = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == 1)
            {
                mark_current_island(grid, i, j, N, M);
                no_of_islands += 1;
            }
        }
    }
    return no_of_islands;
}

int main()
{
    vector<int> mat[] = {{1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1},
                         {1, 0, 0, 1, 1},
                         {0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 1}};
    cout << findIslands(mat, 5, 5);
    return 0;
}