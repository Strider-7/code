#include <bits/stdc++.h> 

using namespace std;

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayGraph(vector <int> adj[], int v) {
    for (int i = 0; i < v; i++)
    {
        for (auto &&j : adj[i])
            cout<<j<<" ";
        cout<<endl;

    }
}

void BFS(vector <int> adj[], int v, int start, bool visited[]) {

    queue <int> q;
    q.push(start);
    visited[start]=true;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for (auto &&i : adj[u])
        {
            if (visited[i]==false)
            {
                visited[i]=true;
                q.push(i);
            }

        }


    }

}

void bfsDisconnectedGraphs(vector <int> adj[], int v) {
    bool visited[v+1]{};
    for (int i = 0; i < v; i++)
    {
        if (visited[i]==false)
            BFS(adj, v, i, visited);
    }

}