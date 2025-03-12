#include<bits/stdc++.h>
using namespace std; 
/*
1-2-3
  |
  4-0-5
*/
void bfs(vector<vector<int>>& adj, int src, vector<int>& visited)
{
	queue<int> q; 
	q.push(src);

	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		cout<<front<<endl;
		visited[front] = 1;
		for(auto node : adj[front])
		{
			if(!visited[node])
			{
				q.push(node);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,4},{1,2},{3,2},{2,4},{0,5}};
	vector<vector<int>> adj(6);
	for(auto edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	vector<int> visited(6,0);
	bfs(adj,0,visited);
	return 0;
}