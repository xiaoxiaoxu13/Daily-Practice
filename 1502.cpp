#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void dfs(int n,int sum,int last,vector<int>& path)
{
	if(sum==n)
	{
		ans.push_back(path);
		return;
	}
	for(int i=1;i<=n-sum;i++)
	{
		if(i!=last)//相邻元素不相等
		{
			path.push_back(i);
			dfs(n,sum+i,i,path);
			path.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<int> path;
	dfs(n,0,0,path);
	for(auto& arr:ans)
	{
		for(int i=0;i<arr.size();i++)
		{
			if(i>0) cout<<" ";
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}
