#include <bits/stdc++.h>
using namespace std;

void dfsrec(vector<vector<int>> &adj, vector<bool> &visited, int x, vector<int> &res)
{
    visited[x] = true;

    res.push_back(x);

    // for only reachable nodes OR connected graph

    for (auto i : adj[x])
    {
        if (visited[i]==false)
            dfsrec(adj, visited, i, res);
    }

    // for all nodes OR disconnected graph

    // for (int i = 0; i < adj.size(); i++)
    // {
    //     if (visited[i] == false)
    //     {
    //         // If vertex i has not been visited,
    //         // perform DFS from it
    //         dfsrec(adj, visited, i, res);
    //     }
    // }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsrec(adj, visited, 1, res);
    return res;
}

void addEgde(vector<vector<int>> &adj, int x, int y)
{
    // for directed graph only
    adj[x].push_back(y);
    
    // for undirected graph
    // adj[y].push_back(x); 
}

int main()
{
    int v = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {4, 2}};
    vector<vector<int>> adj(v);

    for (auto &e : edges)
    {
        addEgde(adj, e[0], e[1]);
    }

    vector<int> ans = dfs(adj);
    cout << "DFS traversal starting from node 1: ";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}