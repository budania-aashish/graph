#include<bits/stdc++.h>
using namespace std; 
class DisjointSets
{
	vector<int> parent, rank;
public: 
	DisjointSets(int n)
	{
	    parent.resize(n,0);
	    rank.resize(n,0);
		for (int i = 0; i < n; ++i)
		{
			parent[i]=i;
			rank[i]=0;
		}
	}

	int find(int x)
	{
		if(x!=parent[x])
		{
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}

	void unite(int x, int y)
	{
		int parent_x = find(x);
		int parent_y = find(y);

		if(parent_x!=parent_y)
		{
			int rank_x = rank[parent_x];
			int rank_y = rank[parent_y];

			if (rank_x>rank_y)
			{
				parent[parent_y]=parent[parent_x];
			}
			else if (rank_y>rank_x)
			{
				parent[parent_x] = parent[parent_y];
			}
			else
			{
				//same rank 
				parent[parent_x] = parent[parent_y];
				rank[parent_y]++;
			}
		}
	}

	bool isconnected(int x, int y)
	{
		int parent_x = find(x);
		int parent_y = find(y);
		return parent_x == parent_y;
	}
};

int main(int argc, char const *argv[])
{
	DisjointSets ds(6);
	ds.unite(0,1);
	cout<<ds.isconnected(0,1);
	ds.unite(2,3);
	cout<<ds.isconnected(2,1);
	ds.unite(1,2);
	cout<<ds.isconnected(0,3);
	ds.unite(4,5);
	ds.unite(1,4);
	cout<<ds.isconnected(2,5);
	return 0;
}
