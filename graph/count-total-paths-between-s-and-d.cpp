#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfsRec(vector<int> adj[], int s, int d, int &res)
{
    if (s == d)
    {
        res++;
        return;
    }
    for (auto &&i : adj[s])
        dfsRec(adj, i, d, res);
}
int countPaths(vector<int> adj[], int V, int s, int d)
{
    int res = 0;

    dfsRec(adj, s, d, res);

    return res;
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 2);

    cout<<countPaths(adj,5,0,4);


    return 0;
}