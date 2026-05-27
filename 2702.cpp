#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;//n个顶点，m条边
	cin>>n>>m;
	
	set<pair<int,int>> edges;//已经存在的边
	long long del=0;
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u==v)//自环
		{
			del++;
			continue;
		}
		if(u>v) swap(u,v);
		if(edges.count({u,v})) del++;
		else edges.insert({u,v});
	}
	
	cout<<del<<endl;
	return 0;
}
