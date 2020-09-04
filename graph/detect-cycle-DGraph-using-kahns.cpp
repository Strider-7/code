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

bool detectCycle(vector<int> adj[], int v)
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
    int count = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
        count++;
    }
    return (count != v);
}

int main()
{
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    // displayGraph(adj, 4);
    cout << detectCycle(adj, 4);

    return 0;
}