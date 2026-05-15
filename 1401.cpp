#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;//数据组数
	cin>>t;
	
	while(t--)
	{
		int n;//企鹅数
		long long k;//企鹅们每秒最多伤害
		cin>>n>>k;
		vector<long long> a(n);//第i个企鹅每秒能造成的伤害
		long long totalhurt=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			totalhurt+=a[i];
		}
		sort(a.begin(),a.end());
		long long h;//敌人血量
		int x;//吃掉一只企鹅所需时间
		cin>>h>>x;
		
		for(int i=n-1;i>=0;i--)
		{
			h=h-(totalhurt>k?(k*x):(totalhurt*x));
			totalhurt=totalhurt-a[i];
			if(h<=0) break;
		}
		if(h>0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	
	return 0;
}
