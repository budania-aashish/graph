#include<bits/stdc++.h>
using namespace std; 
// 0 -1 BFS, number of edges to be reversed for finding the minimum distance from u to v
//where the graph has weight of 0 or 1 
int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{1,0,0},{1,2,0},{6,2,0},{3,2,0},{3,4,0},{7,4,0},{7,5,0},{5,6,0}};
	int n = 8; 
	vector<vector<pair<int, int>>> adj(n);
	for(auto edge: edges)
	{
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];//0
		adj[u].push_back({v,w});
		adj[v].push_back({u,w+1});//w is basically 0 
	}

	vector<int> dist(n, INT_MAX);
	deque<pair<int, int>> dq; 

	int src = 2; 
	dist[src]=0;
	dq.push_front({2,0});

	while(!dq.empty())
	{
		pair<int, int> front = dq.front();
		dq.pop_front();
		int src = front.first; 
		int weight = front.second; 

		//check neighbors for 0 or 1 
		for(auto neighbor : adj[src])
		{
			int node = neighbor.first; 
			int weight = neighbor.second; 
			if(dist[src]!=INT_MAX&&dist[src]+weight<dist[node])
			{
				dist[node] = dist[src]+weight;
				if(weight)
				{
					dq.push_back({node,dist[src]+1});
				}
				else
				{
					dq.push_front({node,dist[src]+0});
				}
			}
		}
	}
	cout<<"distance from node "<<src<<endl;
	for(auto val : dist)
	{
		cout<<val<<endl;
	}
	return 0;
}