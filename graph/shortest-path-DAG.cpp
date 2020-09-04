#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v, int weight, map<pair<int, int>, int> &map)
{
    adj[u].push_back(v);
    map[{u, v}] = weight;
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

bool dfsRec(vector<int> adj[], int start, bool visited[], stack<int> &st)
{
    visited[start] = true;
    for (auto &&i : adj[start])
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited, st);
    }
    st.push(start);
}

void topologicalSort(vector<int> adj[], int v, stack<int> &st)
{
    bool visited[v + 1]{};

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited, st);
    }
}

vector<int> shortestPath(vector<int> adj[], int V, int source, map<pair<int, int>, int> &weight)
{
    vector<int> dist(V, INT32_MAX);
    dist[source] = 0;
    stack <int> topSort;
    topologicalSort(adj, V, topSort);


    while(!topSort.empty())
    {
        int u=topSort.top();
        topSort.pop();
        if (dist[u] != INT32_MAX)
        {
            for (auto &&v : adj[u])
            {
                if (dist[v] > dist[u] + weight[{u, v}])
                    dist[v] = dist[u] + weight[{u, v}];
                // cout << v << "->" << dist[v] << endl;
            }
        }
    }
    return dist;
}

int main()
{
    vector<int> adj[6];
    map<pair<int, int>, int> map;
    addEdge(adj, 0, 1, 2, map);
    addEdge(adj, 0, 4, 1, map);
    addEdge(adj, 1, 2, 3, map);
    addEdge(adj, 2, 3, 6, map);
    addEdge(adj, 4, 2, 2, map);
    addEdge(adj, 4, 5, 4, map);
    addEdge(adj, 5, 3, 1, map);

    for (auto &&i : map)
        cout << i.first.first << "," << i.first.second << " = " << i.second << endl;

    // displayGraph(adj, 6);

    vector<int> v = shortestPath(adj, 6, 0, map);

    for (auto &&i : v)
        cout << i << " ";

    return 0;
}