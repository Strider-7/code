#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, pair<int, int>> bfs(pair<int, int> initial, pair<int, int> final, int N)
{
    map<pair<int, int>, pair<int, int>> prev;
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> vis;
    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}};
    q.push(initial);
    prev[initial] = {0, 0};
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if (vis[p])
            continue;
        vis[p] = true;
        if (p.first == final.first && p.second == final.second)
            return prev;
        for (auto i : dir)
        {
            pair<int, int> t;
            t.first = p.first + i.first;
            t.second = p.second + i.second;
            if (t.first >= 1 && t.first <= N && t.second >= 1 && t.second <= N && !vis[t])
            {
                q.push(t);
                prev[t] = p;
            }
        }
    }
    return prev;
}
int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    pair<int, int> initial(knightPos[0], knightPos[1]);
    pair<int, int> final(targetPos[0], targetPos[1]);
    int res = -1;

    map<pair<int, int>, pair<int, int>> parent = bfs(initial, final, N);
    // for (auto &&i : parent)
    //     cout << i.first.first << " " << i.first.second << "->" << i.second.first << " " << i.second.second << endl;

    while (final.first != 0 || final.second != 0)
    {
        final = parent[final];
        res++;
    }

    return res;
}

int minStepToReachTarget2(int knightPos[], int targetPos[], int N)
{
    pair<int, int> initial(knightPos[0], knightPos[1]);
    pair<int, int> final(targetPos[0], targetPos[1]);

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}};

    queue<pair<int, int>> q;
    q.push(initial);
    dist[initial.first][initial.second] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        // if (vis[p.first][p.second] == 1)
        //     continue;
        vis[p.first][p.second] = 1;
        if (p.first == final.first && p.second == final.second)
            return dist[p.first][p.second];
        for (auto i : dir)
        {
            pair<int, int> t;
            t.first = p.first + i.first;
            t.second = p.second + i.second;
            if (t.first >= 1 && t.first <= N && t.second >= 1 && t.second <= N && vis[t.first][t.second] == 0)
            {
                q.push(t);
                dist[t.first][t.second] = dist[p.first][p.second] + 1;
            }
        }
    }

    return 0;
}

int minStepToReachTarget3(int knightPos[], int targetPos[], int N)
{
    if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1])
        return 0;

    int visited[N + 1][N + 1] = {0};
    visited[knightPos[0]][knightPos[1]] = 1;

    queue<pair<int, int>> q;
    q.push(pair<int, int>(knightPos[0], knightPos[1]));

    int rr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int cc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nextr = r + rr[i];
            int nextc = c + cc[i];

            if (nextr < 1 || nextc < 1 || nextr > N || nextc > N)
                continue;
            if (visited[nextr][nextc] != 0)
                continue;

            if (nextr == targetPos[0] && nextc == targetPos[1])
                return visited[r][c];

            visited[nextr][nextc] = visited[r][c] + 1;
            q.push(pair<int, int>(nextr, nextc));
        }
    }
    return 0;
}

int main()
{
    int k[] = {5, 7};
    int f[] = {15, 20};
    cout << minStepToReachTarget(k, f, 20) << endl;
    cout << minStepToReachTarget2(k, f, 20);
    return 0;
}