#include<bits/stdc++.h>
using namespace std; 
/*
1->2<-3
   ^
   |
   4<-0<-5

this is for directed a cyclic graph
*/
void kahn_algo_dfs(vector<vector<int>>& adj,vector<int>& visited,int src, stack<int>& st)
{
	visited[src]=1;
	for(auto node : adj[src])
	{
		if(!visited[node])
		{
			kahn_algo_dfs(adj, visited, node, st);
		}
	}
	st.push(src);
	return ;
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
	stack<int> st;
	
	for(int i=5;i>=0;i--)
	{
	    if(!visited[i])
		{
		    kahn_algo_dfs(adj,visited,i,st);
		}
	}

	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}