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

void topologicalSort(vector<int> adj[], int v)
{
    bool visited[v + 1]{};
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited, st);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    displayGraph(adj, 5);
    topologicalSort(adj, 5);

    return 0;
}