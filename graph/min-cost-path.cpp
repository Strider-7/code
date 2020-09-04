#include <bits/stdc++.h>

using namespace std;

int shortest(vector<vector<int>> &grid, int n)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int dist[n][n], visit[n][n];
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = INT32_MAX;
            visit[i][j] = 0;
        }
    }
    pq.push(make_pair(grid[0][0], make_pair(0, 0)));
    dist[0][0] = grid[0][0];
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        visit[x][y] = 1;
        pq.pop();
        for (i = 0; i < 4; i++)
        {
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && dist[newx][newy] > dist[x][y] + grid[newx][newy] && visit[newx][newy] == 0)
            {
                dist[newx][newy] = dist[x][y] + grid[newx][newy];
                pq.push(make_pair(dist[newx][newy], make_pair(newx, newy)));
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid =
        {
            {31, 100, 65, 12, 18},
            {10, 13, 47, 157, 6},
            {100, 113, 174, 11, 33},
            {88, 124, 41, 20, 140},
            {99, 32, 111, 41, 20}
        };
    for (auto &&i : grid)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }
    cout<<shortest(grid,5);

    return 0;
}