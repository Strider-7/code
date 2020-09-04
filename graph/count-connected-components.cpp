// also known as number of islands in graph

#include <bits/stdc++.h> 

using namespace std;

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

int bfsDisconnectedGraphs(vector <int> adj[], int v) {
    bool visited[v+1]{};
    int res=0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i]==false)
        {
            BFS(adj, v, i, visited);
            res++;
        }
    }
    return res;

}

int main() {
    vector  <int> adj[4];


    cout<<endl<<bfsDisconnectedGraphs(adj, 4);


    return 0;
}