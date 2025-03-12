#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edges = {{0, 1, 1}, {0, 3, 2}, {3, 4, 3}, {4, 2, 1}, {2, 5, 1}, {1, 2, 2}};
    int n = 6; 
    vector<vector<pair<int, int>>> adj(n);  

    // Construct adjacency list
    for(auto edge : edges) {
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];
        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
    }

    int src = 0; 
    int target = 5; 
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<int> parent(n, -1); // Fixed: Initialize parent with -1

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int top_node = pq.top().second;
        pq.pop();

        // Process all adjacent nodes
        for (auto node : adj[top_node]) {
            int neighbor = node.first;
            int edge_weight = node.second;

            if (dist[neighbor] > dist[top_node] + edge_weight) {
                dist[neighbor] = dist[top_node] + edge_weight;
                pq.push({dist[neighbor], neighbor});
                parent[neighbor] = top_node; // Store parent for path reconstruction
            }
        }
    }

    // If the target node is unreachable
    if (dist[target] == INT_MAX) {
        cout << "No shortest path available" << endl;
        return 0;
    }

    // Reconstruct the shortest path
    vector<int> ans;
    int temp = target;
    while (temp != -1) {
        ans.push_back(temp);
        temp = parent[temp];
    }
    
    reverse(ans.begin(), ans.end()); // Reverse to get correct order

    // Print the shortest path
   for(auto val : ans)
   {
       cout<<val<<" ";
   }
    return 0;
}
