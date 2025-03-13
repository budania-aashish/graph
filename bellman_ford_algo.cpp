#include<bits/stdc++.h>
using namespace std; 
int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 2}, {3, 4,-1}, {2, 4, 1},{1, 2, 1}};
	int n = 5; //vertices 0 to 1 
	vector<int> dist(n, INT_MAX);
	int src = 2; 
	dist[src]=0;
	for (int i = 0; i < n-1; ++i)
	{
		for(auto edge : edges)
		{
			int u = edge[0];
			int v = edge[1];
			int w = edge[2];

			if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w)
			{
				dist[v]= dist[u] + w;
			}
		}
	}

	cout<<"from source "<<src<<" distances are : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" till node "<<i<<" :"; 
		if(dist[i]==INT_MAX)
		{
			cout<<"Not reachable"<<endl;
		}
		else
		{
			cout<<dist[i]<<endl;
		}
	}
	return 0;
}