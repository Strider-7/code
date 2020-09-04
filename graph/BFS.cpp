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

void BFS(vector <int> adj[], int v, int start) {
    bool visited[v+1]{};
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

int main() {
    vector  <int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    displayGraph(adj, 5);

    BFS(adj, 5, 0);

    return 0;
}