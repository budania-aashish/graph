#include <bits/stdc++.h>
using namespace std; 
void dfs(vector<vector<int>>&adj, vector<int>& visited, vector<int>& disc, vector<int>& low, int timer, vector<vector<int>>& res, int src, int parent)
{
	visited[src]=1;
	disc[src]=low[src]=timer;
	timer++;
	for (auto node : adj[src])
	{
	    if(node==parent)
		{
		      continue;
		}
		if(!visited[node])
		{
		    
		    parent = src; 
			dfs(adj, visited, disc, low, timer, res, node, parent);
			//once the dfs call is over for src
			low[src] = min(low[node],low[src]);//minimum low time 
			if(disc[src]<low[node])
			{
				res.push_back({src,node});
			}
		}
		else
		{
			low[src] = min(low[src], disc[node]);
		}
	}
	return ; 
}
int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,1},{1,3},{0,2},{2,3},{3,4},{4,5},{5,6}};
	int n = 7; 
	vector<vector<int>> adj(7);
	for(auto edge: edges)
	{
		int src = edge[0];
		int dest = edge[1];
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}

	vector<int> disc(n,0);
	vector<int> low(n,0);
	vector<int> visited(n, 0);
	int timer = 1; 
	int src = 1; 
	vector<vector<int>> res; //to store the bridges
	dfs(adj, visited, disc, low, timer, res, src, -1);
	cout<<"All of the bridges are"<<endl;
	for(auto val : res)
	{
		cout<<val[0]<<"-"<<val[1]<<endl;
	}
	return 0;
}