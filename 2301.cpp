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
		int n;//排列a的长度
		cin>>n;
		vector<int> a(n);//排列a
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		int ans=0;
		int maxleft=a[0];//当前遍历过的最大值
		for(int i=0;i<n;i++)
		{
			if(maxleft>a[i])
			{
				ans=max(ans,maxleft+a[i]);
			}
			maxleft=max(maxleft,a[i]);
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
