#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsRec(vector<int> adj[], int start, bool visited[], bool health[])
{
    visited[start] = true;
    health[start] = true;

    for (auto &&i : adj[start])
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited, health);
    }
}

void findInfected(vector<int> adj[], int N, vector<int> &infected, vector<int> &find)
{
    bool health[N]{};
    bool visited[N + 1]{};

    for (auto &&i : infected)
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited, health);
    }

    for (auto &&i : find)
    {
        health[i] == true ? cout << "P" << endl : cout << "NP" << endl;
    }
}

int main()
{

    int M, N, K, L;
    cin >> N;
    vector<int> adj[N];
    cin >> M;
    vector<int> infected;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        infected.push_back(x);
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    cin >> L;
    vector<int> find;
    for (int i = 0; i < L; i++)
    {
        int x;
        cin >> x;
        find.push_back(x);
    }

    findInfected(adj, N, infected, find);

    return 0;
}