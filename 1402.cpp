#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	vector<int> costa(n);//起始为奇数
	vector<int> costb(n);//起始为偶数
	for(int i=0;i<n;i++)
	{
		int targeta=(i%2==0)?1:0;
		int targetb=(i%2==0)?0:1;
		int cur=a[i]%2;
		costa[i]=(cur!=targeta)?1:0;
		costb[i]=(cur!=targetb)?1:0;
	}
	
	vector<int> prea(n+1,0),preb(n+1,0);
	for(int i=0;i<n;i++)
	{
		prea[i+1]=prea[i]+costa[i];
		preb[i+1]=preb[i]+costb[i];
	}
	
	int mina=INT16_MAX,minb=INT_MAX;
	for(int i=0;i<=n-m;i++)
	{
		int suma=prea[i+m]-prea[i];
		int sumb=preb[i+m]-preb[i];
		mina=min(mina,suma);
		minb=min(minb,sumb);
	}
	
	cout<<min(mina,minb)<<endl;
	return 0;
}
