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

void dfsRec(vector<int> adj[], int start, bool visited[])
{
    visited[start] = true;
    cout << start << " ";

    for (auto &&i : adj[start])
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited);
    }
}

void dfs(vector<int> adj[], int v, int start)
{
    bool visited[v + 1]{};
    dfsRec(adj, start, visited);
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    // addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    displayGraph(adj, 5);
    cout<<endl;

    dfs(adj, 5, 0);

    

    return 0;
}