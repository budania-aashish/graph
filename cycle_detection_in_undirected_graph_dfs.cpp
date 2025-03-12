#include <bits/stdc++.h>
using namespace std;

/*
Graph:
1 - 2 - 3
    |   |
    4 - 0 - 5

A cycle exists: 0 → 4 → 2 → 3 → 0
*/

bool findCycle(vector<vector<int>>& adj, vector<int>& visited, int src, int parent)
{
    visited[src] = 1;

    for (auto node : adj[src])
    {
        if (!visited[node])  // If node is not visited, perform DFS
        {
            if (findCycle(adj, visited, node, src))
            {
                return true;
            }
        }
        else if (node != parent)  // If visited and NOT the parent, cycle detected
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 4}, {1, 2}, {2, 3}, {4, 2}, {5, 0}};
    vector<vector<int>> adj(6);

    // Build adjacency list for undirected graph
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Adding extra edge to form a cycle
    vector<int> edge = {3, 0};
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);

    vector<int> visited(6, 0);

    // Check for cycles in all components
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i] && findCycle(adj, visited, i, -1))
        {
            cout << "1 (Cycle found)\n";
            return 1;
        }
    }

    cout << "0 (No cycle)\n";
    return 0;
}
