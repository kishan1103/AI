#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &x : graph[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; ++i)
        cout << "Distance to " << i << ": " << dist[i] << "\n";
}

int main()
{
    cout<<"Djikstra Output\n";
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);
    graph[0] = {{1, 2}, {2, 4}};
    graph[1] = {{2, 1}, {3, 7}};
    graph[2] = {{3, 3}};
    graph[3] = {{4, 1}};
    graph[4] = {};

    dijkstra(graph, 0);
    return 0;
}