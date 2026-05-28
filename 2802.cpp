#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;//有n个村庄
	cin>>n;
	vector<long long> x(n);//村庄坐标
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	vector<long long> p(n);//村庄人数
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	
	vector<long long> prefix(n+1,0);//前缀和
	for(int i=0;i<n;i++)
	{
		prefix[i+1]=prefix[i]+p[i];
	}
	
	int q;//有q个查询
	cin>>q;
	
	while(q--)
	{
		long long l,r;
		cin>>l>>r;
		int left=lower_bound(x.begin(),x.end(),l)-x.begin();
		int right=upper_bound(x.begin(),x.end(),r)-x.begin()-1;
		long long ans=0;
		if(left<=right)
		{
			ans=prefix[right+1]-prefix[left];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
