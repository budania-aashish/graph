#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0) return 0;
        if(n == 1) return 0;
        
        // Each state is (node, mask) where mask represents the set of visited nodes
        queue<tuple<int, int, int>> q; // {node, mask, steps}
        // Use a 2D visited table: visited[node][mask] indicates whether we visited this state
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        int allVisited = (1 << n) - 1;
        
        // Start BFS from every node with its initial mask
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }
        
        // BFS loop
        while (!q.empty()) {
            auto [node, mask, steps] = q.front();
            q.pop();
            
            // If we've visited all nodes, return the steps count
            if (mask == allVisited) return steps;
            
            // Try every neighbor
            for (int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor);
                if (!visited[neighbor][newMask]) {
                    visited[neighbor][newMask] = true;
                    q.push({neighbor, newMask, steps + 1});
                }
            }
        }
        return -1; // This will never be reached since a solution always exists.
    }
};

int main() {
    // Sample input from LeetCode: [[1,2,3],[0],[0],[0]]
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0},
        {0},
        {0}
    };

    Solution sol;
    int result = sol.shortestPathLength(graph);
    cout << "Shortest Path Visiting All Nodes: " << result << endl;
    
    return 0;
}
