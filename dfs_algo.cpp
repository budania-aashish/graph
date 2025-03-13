#include<bits/stdc++.h>
using namespace std; 
/*
1-2-3
  |
  4-0
*/
void dfs(vector<vector<int>>& adj, int src, vector<int>& visited)
{
	visited[src]=1;
	cout<<src<<endl;
	for(auto node : adj[src])
	{
		if(!visited[node])
		{
			dfs(adj, node, visited);
		}
	}
	return ;
}


int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,4},{1,2},{3,2},{2,4}};
	vector<vector<int>> adj(5);
	for(auto edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	vector<int> visited(4,0);
	dfs(adj,0,visited);
	return 0;
}