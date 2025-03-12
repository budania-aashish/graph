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

bool findCycle(vector<vector<int>>& adj,vector<int>& visited,vector<vector<int>>& edges, int n)
{
	vector<int> indegree(n,0);
	for(auto edge: edges)
	{
		indegree[edge[1]]++;
	}
	queue<int> q;
	for(int i=0;i<indegree.size();i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	if(q.size()==0)
	{
		return true;
	}
	int c=0;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		visited[front]=1;
		c++;
		for(auto node : adj[front])
		{
				if(!visited[node])
				{
					indegree[node]--;
					if(indegree[node]==0)
					{
						q.push(node);
					}
				}
		}
	}
	return c!=n;
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
	cout<<findCycle(adj,visited, edges, 6)<<endl;
	return 0;
}