#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto &&j : adj[i])
            cout << j << " ";
        cout << endl;
    }
}

bool dfsRec(vector<int> adj[], int start, bool visited[], int parent)
{
    visited[start] = true;

    for (auto &&i : adj[start])
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, start))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}

bool dfs(vector<int> adj[], int v, int start)
{
    bool visited[v + 1]{};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, start, visited, -1) == true)
                return true;
        }
    }
    return false;
}

bool bfs(vector<int> adj[], int v, int start)
{
    bool visited[v + 1]{};
    vector<int> parent(v, -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &&i : adj[u])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                parent[i] = u;
            }
            else if (parent[i] != u)
                return true;
        }
    }

    return false;
}

int main()
{
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // displayGraph(adj, 4);

    cout << dfs(adj, 4, 0)<<endl;
    cout<<bfs(adj,4,0);

    return 0;
}