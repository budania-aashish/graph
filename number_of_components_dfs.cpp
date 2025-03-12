#include <bits/stdc++.h>
using namespace std;

/*
Graph:
1 - 2 - 3
       
    4 - 0 - 5

    6

number of components in a direct graph here are 3
*/

void dfs(vector<vector<int>>& adj, vector<int>& visited, int src)
{
    visited[src]=1;
    for(auto node : adj[src])
    {
        if(!visited[node])
        {
            dfs(adj, visited, node);
        }
    }
    return ;
}

int main()
{
    vector<vector<int>> edges = {{0, 4}, {1, 2}, {2, 3}, {5, 0}};
    vector<vector<int>> adj(7);//there are 7 nodes but 4 edges

    // Build adjacency list for undirected graph
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> visited(7, 0);
    int count = 0; 
    // Check for cycles in all components
    for (int i = 0; i < 7; i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,i);
            count++;
        }
    }

    cout << count << endl; 
    return 0;
}
