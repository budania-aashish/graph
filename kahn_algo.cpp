#include<bits/stdc++.h>
using namespace std; 
/*
1->2<-3
   ^
   |
   4<-0<-5

this is for directed acyclic graph
*/
void kahn_algo(vector<vector<int>>& adj,vector<int>& visited,vector<vector<int>>& edges, int n)
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
		cout<<"Not possible";
	}

	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		visited[front]=1;
		cout<<front<<endl;
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
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,4},{1,2},{3,2},{4,2},{5,0}};
	vector<vector<int>> adj(6);
	for(auto edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
	}
	vector<int> visited(6,0);
	kahn_algo(adj,visited, edges, 6);
	return 0;
}