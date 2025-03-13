#include<bits/stdc++.h>
using namespace std; 

// Function to compare two edges based on their weights
bool mycompare(vector<int> a, vector<int> b)
{
    return a[2] < b[2]; // Compare based on the weight (a[2] and b[2])
}

// Find function for union-find (disjoint set)
int find(int x, vector<int>& parent)
{
    if(x != parent[x])
    {
        parent[x] = find(parent[x], parent);  // Path compression
    }
    return parent[x];
}

// Union function for union-find (disjoint set)
void unite(int u, int v, vector<int>& parent, vector<int>& rank)
{
    int parent_u = find(u, parent);
    int parent_v = find(v, parent);

    // Union by rank
    if(rank[parent_u] > rank[parent_v])
    {
        parent[parent_v] = parent_u;
    }
    else if(rank[parent_u] < rank[parent_v])
    {
        parent[parent_u] = parent_v;
    }
    else
    {
        parent[parent_v] = parent_u;
        rank[parent_u]++;
    }
}

// Function to check if two vertices are connected
bool isConnected(int u, int v, vector<int>& parent)
{
    return find(u, parent) == find(v, parent);
}

int main(int argc, char const *argv[])
{
    // Define the edges as {u, v, weight}
    vector<vector<int>> edges = {{0,1,1},{1,2,2},{0,3,4},{3,5,1},{2,3,9},{2,4,3},{4,5,2}};
    
    // Sort edges based on their weight (ascending order)
    sort(edges.begin(), edges.end(), mycompare);
    
    // Initialize parent and rank vectors for union-find
    vector<int> parent(6);
    vector<int> rank(6, 0);
    
    // Initially, each vertex is its own parent (disjoint set)
    for(int i = 0; i < 6; i++)
    {
        parent[i] = i;
    }

    int cost = 0; // Variable to store the total cost of MST
    
    // Process each edge
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];  // Corrected: the weight is at edge[2]
        
        // If the vertices are not connected, add this edge to the MST
        if(!isConnected(u, v, parent))
        {
            unite(u, v, parent, rank);
            cost += w;
        }
    }
    
    cout << "Cost of MST is " << cost << endl;
    
    return 0;
}
