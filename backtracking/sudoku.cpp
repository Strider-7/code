#include <bits/stdc++.h>

using namespace std;

const int N = 4;

bool UsedInRow(vector<vector<int>> &grid, int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether 
an assigned entry in the specified column 
matches the given number. */
bool UsedInCol(vector<vector<int>> &grid, int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether 
an assigned entry within the specified 3x3 box 
matches the given number. */
bool UsedInBox(vector<vector<int>> &grid, int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether 
it will be legal to assign num to the given 
row, col location. */
bool isSafe(vector<vector<int>> &grid, int row,
            int col, int n)
{
    /* Check if 'num' is not already placed in 
	current row, current column and current 3x3 box */
    return !UsedInRow(grid, row, n) && !UsedInCol(grid, col, n) && !UsedInBox(grid, row - row % 3, col - col % 3, n) && grid[row][col] == 0;
}

bool solveRec(vector<vector<int>> &grid)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                break;
        }
    }
    if (i == N && j == N)
        return true;
    for (int n = 1; n <= N; n++)
    {
        if (isSafe(grid, i, j, n))
        {
            cout << "y";
            grid[i][j] = n;
            if (solveRec(grid))
                return true;
            grid[i][j] = 0;
        }
    }

    return false;
}

bool solve(vector<vector<int>> &grid)
{
    if (solveRec(grid))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 3, 0},
                                {0, 0, 2, 1},
                                {0, 1, 0, 2},
                                {2, 4, 0, 0}};
    cout << solve(grid);

    return 0;
}