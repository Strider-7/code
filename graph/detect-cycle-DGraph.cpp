#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
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

bool dfsRec(vector<int> adj[], int start, bool visited[], bool recStack[])
{
    visited[start] = true;
    recStack[start] = true;

    for (auto &&i : adj[start])
    {
        if (visited[i] == false && dfsRec(adj, i, visited, recStack))
            return true;

        else if (recStack[i] == true)
            return true;
    }
    recStack[start] = false;
    return false;
}

bool dfs(vector<int> adj[], int v, int start)
{
    bool visited[v + 1]{};
    bool recStack[v + 1]{};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, start, visited, recStack) == true)
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
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    // displayGraph(adj, 4);

    cout << dfs(adj, 4, 0) << endl;

    return 0;
}