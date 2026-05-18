#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;//数组长度
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int minval=INT_MAX;//最小权值
	for(int mask=1;mask<(1<<n);mask++)//枚举所有非空子序列
	{
		int andval=-1;//当前子序列按位与结果（初始化为全1）
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i))//检查mask的第i位是不是1
			{
				andval&=a[i];
			}
		}
		if(andval<minval)
		{
			minval=andval;
		}
	}
	
	cout<<minval<<endl;
	return 0;
}
