#include <bits/stdc++.h>

using namespace std;

const int N = 5;

bool board[N][N]{};

bool isSafe(int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveRec(int col)
{
    if (col == N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;
            if (solveRec(col + 1) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solve()
{
    if (solveRec(0) == false)
        return false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main()
{
    cout << solve();

    return 0;
}