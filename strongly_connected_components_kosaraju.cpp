#include<bits/stdc++.h>
using namespace std; 

void dfs(vector<int>& visited, vector<vector<int>>& adj, int i, stack<int> &s)
{
    visited[i] = 1;
    for(auto node : adj[i])
    {
        if(!visited[node])
        {
            dfs(visited, adj, node, s);
        }
    }
    s.push(i);
}

void dfs2(vector<int>& visited, vector<vector<int>>& adjR, int src)
{
    visited[src] = 1;
    for(auto node : adjR[src])
    {
        if(!visited[node])
        {
            dfs2(visited, adjR, node);  // Changed from src to node
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{2,3},{3,4},{4,5},{5,6},{6,4},{6,7}};
    int n = 8; 
    vector<vector<int>> adj(n);
    
    // Build adjacency list
    for(auto edge: edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    
    // First DFS to get finishing times
    vector<int> visited(n, 0);
    stack<int> s;  // Removed size initialization
    int rank = n; 
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(visited, adj, i, s);
        }
    }
    
    // Create reversed graph
    vector<vector<int>> adjR(n);
    for(auto edge : edges)
    {
        adjR[edge[1]].push_back(edge[0]);  // Simply reverse edges
    }
    
    // Second DFS to count SCCs
    fill(visited.begin(), visited.end(), 0);  // Reset visited array
    int count = 0;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            dfs2(visited, adjR, node);
            count++;
        }
    }
    
    cout << "Strongly connected components are " << count << endl;
    return 0;
}