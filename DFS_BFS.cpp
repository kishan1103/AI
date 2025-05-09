#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<char, vector<char>> graph;

// Recursive DFS with proper found/not found handling
void dfs(char node, char target, int depth, int max_depth, unordered_set<char>& visited, bool& found) {
    cout << node << " ";
    if (node == target) {
        found = true;
        return;
    }
    if (depth >= max_depth) return;

    visited.insert(node);
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, target, depth + 1, max_depth, visited, found);
            if (found) return;
        }
    }
}

// BFS with proper found/not found handling
void bfs(char start, char target, int max_depth) {
    queue<pair<char, int>> q; // (node, depth)
    unordered_set<char> visited;
    bool found = false;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, depth] = q.front();
        q.pop();
        cout << current << " ";

        if (current == target) {
            found = true;
            break;
        }
        if (depth >= max_depth) continue;

        for (char neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, depth + 1});
            }
        }
    }

    if (found) cout << "\nFound!";
    else cout << "\nNot found within depth limit!";
}

int main() {
    int edge_count;
    char u, v, start, target;
    int max_depth;

    // Input graph
    cout << "Enter number of edges: ";
    cin >> edge_count;
    cout << "Enter edges (e.g., A B):\n";
    for (int i = 0; i < edge_count; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    // Input search parameters
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter target node: ";
    cin >> target;
    cout << "Enter max depth: ";
    cin >> max_depth;

    // DFS Search
    cout << "\nDFS Traversal: ";
    unordered_set<char> dfs_visited;
    bool dfs_found = false;
    dfs(start, target, 0, max_depth, dfs_visited, dfs_found);
    if (dfs_found) cout << "\nFound!";
    else cout << "\nNot found within depth limit!";

    // BFS Search
    cout << "\n\nBFS Traversal: ";
    bfs(start, target, max_depth);

    return 0;
}