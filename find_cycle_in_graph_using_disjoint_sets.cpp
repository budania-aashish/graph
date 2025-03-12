#include<bits/stdc++.h>
using namespace std; 
class DisjointSet
{
	vector<int> rank;
	vector<int> parent;
public:
	DisjointSet(int n)
	{
		parent.resize(n,0);
		rank.resize(n,0);
		for (int i = 0; i < n; ++i)
		{
			parent[i]=i;
		}
	} 

	int find(int x)
	{
		if (x!=parent[x])
		{
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y)
	{
		int parent_x = find(x);
		int parent_y = find(y);

		if(rank[parent_x]>rank[parent_y])
		{
			parent[parent_y] = parent_x;
		}
		else if (rank[parent_x]<rank[parent_y])
		{
			parent[parent_x] = parent_y;
		}
		else
		{
			parent[parent_x] = parent_y;
			rank[parent_y]++;
		}
	}

	bool isconnected(int x, int y)
	{
		return find(x)==find(y);
	}
};



int main(int argc, char const *argv[])
{
	vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,0}};
	int n = 4; //number of nodes
	DisjointSet ds(n);
	for(auto edge : edges)
	{
		if(ds.isconnected(edge[0], edge[1]))
		{
			cout<<"cycle found"<<endl;
			return 1;
		}
		ds.unite(edge[0], edge[1]);
	}
	cout<<"cycle not found"<<endl;
	return 0;
}