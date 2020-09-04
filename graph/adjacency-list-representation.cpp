#include <bits/stdc++.h> 

using namespace std;

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main() {
    vector  <int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    for (int i = 0; i < 4; i++)
    {
        for (auto &&j : adj[i])
            cout<<j<<" ";
        cout<<endl;

    }


    return 0;
}