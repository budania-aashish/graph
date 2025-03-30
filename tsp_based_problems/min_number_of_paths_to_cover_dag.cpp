#include <bits/stdc++.h>
using namespace std;

class MinimumPathCoverDAG {
    int n;
    vector<vector<int>> graph;
    vector<vector<bool>> visited;

public:
    MinimumPathCoverDAG(int n) {
        this->n = n;
        graph.resize(n);
        visited.assign(n, vector<bool>(1 << n, false)); // Mask tracking
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    int bfs_minPathCover() {
        queue<pair<int, int>> q;  // {node, bitmask}
        
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i}); // Start BFS from all nodes
            visited[i][1 << i] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == (1 << n) - 1) return steps;  // all nodes are visited
                
                for (int neighbor : graph[node]) {
                    int new_mask = mask | (1 << neighbor);
                    if (!visited[neighbor][new_mask]) {
                        visited[neighbor][new_mask] = true;
                        q.push({neighbor, new_mask});
                    }
                }
            }
            steps++; // increasing steps post each level
        }
        return n;  // Worst case
    }
};

int main() {
    int n = 4;  // Number of nodes
    MinimumPathCoverDAG dag(n);

    dag.addEdge(0, 1);
    dag.addEdge(0, 2);
    dag.addEdge(1, 3);
    dag.addEdge(2, 3);

    cout << "Minimum Path Cover: " << dag.bfs_minPathCover() << endl;
    return 0;
}
