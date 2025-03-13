#include<bits/stdc++.h>
using namespace std; 
int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {2, 4, 7}, {4, 1, 5}, {1, 3, 8}, {0, 3, 6}};
	int n = 5; 
	vector<vector<pair<int, int>>> adj(5);
	for(auto edge : edges)
	{
		int src = edge[0];
		int dest = edge[1];
		int weight = edge[2];

		adj[src].push_back({dest, weight});
		adj[dest].push_back({src, weight});
	}

	//starting with let's say vertex 1 
	int src = 1; 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	pq.push({0, src});
	int total_cost = 0 ; 
	vector<int> visited(n,0);
	while(!pq.empty())
	{
		pair<int, int> top_pair = pq.top();
		pq.pop();
		int src = top_pair.second; 
		int cost = top_pair.first;
		if(visited[src])
		{
		    continue;
		}
		visited[src]=1;
		total_cost+=cost;
		for(auto neighbor : adj[src])
		{
			int node = neighbor.first;
			int weight = neighbor.second; 
			if(!visited[node])
			{
				pq.push({weight, node});
			}
		}
	}
	cout<<"cost of MST is : "<<total_cost<<endl;
	return 0;
}