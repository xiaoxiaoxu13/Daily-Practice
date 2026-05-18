#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m,x;
	cin>>n>>m>>x;
	vector<bool> trap(n+1,false);//陷阱标记
	for(int i=0;i<x;i++)
	{
		int a;
		cin>>a;
		trap[a]=true;
	}
	vector<vector<int>> adj(n+1);//存路线图
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> visited(n+1,false);//标记是否可访问
	queue<int> q;//标记起点，用来找接下来要访问的房间
	q.push(1);//起点
	visited[1]=true;
	
	while(!q.empty())//队列非空，即有可访问的房间
	{
		int u=q.front();//以队列开头为起点
		q.pop();//弹出该点
		for(int v:adj[u])//访问该起点可到达的所有地点
		{
			if(!trap[v]&&!visited[v])//不是陷阱且未访问
			{
				visited[v]=true;
				q.push(v);//该地点加入队列，准备当起点
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	
	return 0;
	
	return 0;
}
