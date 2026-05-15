#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;//数组中元素数量
	cin>>n;
	vector<int> a(n);
	vector<int> exsit(9,0);//统计数字出现次数
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		exsit[a[i]-1]++;
	}
	
	bool result=true;
	int k=n/9;
	int r=n%9;
	int countr=0;
	for(int i=0;i<9;i++)
	{
		if(exsit[i]!=k&&exsit[i]!=k+1)
		{
			result=false;
			break;
		}
		if(exsit[i]==k+1) countr++;
	}
	if(countr!=r) result=false;
	
	if(result)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	
	return 0;
}
