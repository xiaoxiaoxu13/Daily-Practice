#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin>>q;
	
	vector<long long> sum;//前缀和数组，sun[i]表示前i条蛇的总长度
	sum.push_back(0);
	int head=0;//队列头部
	long long offset=0;//队首被移除的蛇的总长度
	
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			long long l;
			cin>>l;
			sum.push_back(sum.back()+l);
		}
		else if(op==2)
		{
			offset+=sum[head+1]-sum[head];
			head++;
		}
		else if(op==3)
		{
			int k;
			cin>>k;
			cout<<sum[head+k-1]-offset<<endl;
		}
	}
	
	return 0;
}
