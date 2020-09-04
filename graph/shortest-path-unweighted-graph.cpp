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

vector<int> shortestPath(vector<int> adj[], int v, int start)
{
    vector<int> dist(v,INT32_MAX);
    bool visited[v + 1]{};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[0] = 0;
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
                dist[i] = dist[u] + 1;
            }
        }
    } 

    return dist;
}

int main()
{
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    

    displayGraph(adj, 4);

    vector<int> v=shortestPath(adj,4,0);

    for (auto &&i : v)
        cout<<i<<" ";
    

    return 0;
}