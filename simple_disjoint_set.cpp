#include <bits/stdc++.h>
using namespace std; 
class DisjointSet
{
	vector<int> parent;
public:
	DisjointSet(int n)
	{
		parent.resize(n,0);
		for (int i = 0; i < n; ++i)
		{
			parent[i]=i;
		}
	}


	int find(int x)
	{
		if(parent[x]==x) return x; 
		return find(parent[x]);
	}


	void unite(int x, int y)
	{
		int x_root = find(x);
		int y_root = find(y);
		if(x_root!=y_root)
		{
			parent[x_root] = y_root;
		}
	}

	bool isconnected(int x, int y)
	{
		return find(x)==find(y);
	}
};

int main(int argc, char const *argv[])
{
	DisjointSet ds(5);
	ds.unite(0,1);
	ds.unite(2,3);
	cout<<ds.isconnected(1,2)<<endl;
	ds.unite(1,2);
	cout<<ds.isconnected(1,2)<<endl;
	cout<<ds.isconnected(3,4)<<endl;
	return 0;
}