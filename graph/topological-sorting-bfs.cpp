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

void storeIndegree(vector<int> adj[], int v, int indegree[])
{
    for (int i = 0; i < v; i++)
    {
        for (auto j : adj[i])
            indegree[j]++;
    }
}

void topologicalSort(vector<int> adj[], int v)
{
    int indegree[v + 1]{};
    
    storeIndegree(adj, v, indegree);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto i : adj[u])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    displayGraph(adj, 5);
    topologicalSort(adj, 5);

    return 0;
}