#include <bits/stdc++.h>
using namespace std;

/*
Graph1:
1 - 2 - 3
    |   |
    4 - 0 


1 - 2-5-3
    |   |
    4 - 0 

number of components in a direct graph here are 3
*/

bool bfs(vector<vector<int>>& adj, vector<int>& visited, int src, vector<int>& colors)
{
    queue<int> q; 
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        visited[front]=1;
        for(auto node : adj[front])
        {
            if(!visited[node])
            {
                colors[node] = 1-colors[front];
                q.push(node);
            }
            else if(colors[node]==colors[front])
            {
                return true; 
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 4}, {1, 2}, {2, 3}, {5, 0},{2,5},{5,3}};
    vector<vector<int>> adj(7);//there are 7 nodes but 4 edges

    // Build adjacency list for undirected graph
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> visited(7, 0);
    vector<int> colors(7, -1);
    // Check for cycles in all components
    for (int i = 0; i < 7; i++)
    {
        if(!visited[i])
        {
            if(bfs(adj,visited,i,colors))
            {
                cout<<"Not bipartie"<<endl;
                return 0;
            }
        }
    }
    cout<<"bipartie"<<endl;
    return 0;
}
