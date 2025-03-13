#include<bits/stdc++.h>
using namespace std; 
int main(int argc, char const *argv[])
{
	vector<vector<int>> M = {{0, 1, 43}, {1, 0, 6}, {-1, -7, 0}};
	int n = 3; 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(M[i][k]!=INT_MAX&&M[k][j]!=INT_MAX&&M[i][k]+M[k][j]<M[i][j])
				{
					M[i][j] = M[i][k]+M[k][j];
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(M[i][i]<0)
		{
			cout<<"Negative cycle found"<<endl;
			return 1;
		}
	}
	cout<<"No negative cycle found"<<endl;
	
	return 0;
}