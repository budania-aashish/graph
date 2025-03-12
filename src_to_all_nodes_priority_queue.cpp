#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edges = {{0, 1, 1}, {0, 3, 2}, {3, 4, 3}, {4, 2, 1}, {2, 5, 1}, {1, 2, 2}};
    int n = 6; 
    vector<vector<pair<int, int>>> adj(n);  // Fixed: Used 'n' instead of hardcoded 6
    
    // Construct adjacency list
    for(auto edge : edges) {
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];
        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
    }

    int src = 3; 
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int top_node = top.second; 
        // Process all adjacent nodes
        for (auto node : adj[top_node]) {
            int neighbor = node.first;
            int edge_weight = node.second;

            if (dist[neighbor] > dist[top_node] + edge_weight) 
            {
                dist[neighbor] = dist[top_node] + edge_weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Output shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " distance: " << dist[i] << endl;
    }
    
    return 0;
}
