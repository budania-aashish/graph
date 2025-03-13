#include<bits/stdc++.h>
using namespace std; 
int main(int argc, char const *argv[])
{
	vector<vector<int>> M = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
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
	
	int m = M.size();
	cout<<"cost matrix"<<endl;
	for(int i=0;i<m;i++)
	{
		for(auto cost : M[i])
		{
			cout<<cost<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}