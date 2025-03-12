#include<bits/stdc++.h>
using namespace std; 
/*
1->2->3
   ^  |
   |  ,,
   4<-0<-5

a cycle for 0 to 4 to 2 to 3 to 0 

finding a cycle in directed graph
*/

bool findCycle(vector<vector<int>>& adj,vector<int>& visited,int src, unordered_set<int> &s)
{
	visited[src]=1;
	s.insert(src);
	for(auto node : adj[src])
	{
		if(!visited[node])
		{
			if(findCycle(adj, visited, node, s))
			{
				return 1; 
			}
		}
		if(s.find(node)!=s.end())
		{
			return 1;
		}
	}
	s.erase(src);
	return 0;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,4},{1,2},{2,3},{4,2},{5,0},{3,0}};
	vector<vector<int>> adj(6);
	for(auto edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
	}
	vector<int> visited(6,0);
	unordered_set<int> s; 
	for(int i=0;i<6;i++)
	{
		if(!visited[i]&&findCycle(adj,visited,i,s))
		{
		     cout<<1<<endl;
		     return 1;
		}
	}
	cout<<0;
	return 0;
}