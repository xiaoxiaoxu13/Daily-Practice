#include<bits/stdc++.h>
using namespace std;

bool has(const string &s,int k)
{
	int n=s.length();
	for(int i=0;i<=n-k;i++)
	{
		bool ispalin=true;
		for(int j=0;j<k/2;j++)
		{
			if(s[i+j]!=s[i+k-1-j])
			{
				ispalin=false;
				break;
			}
		}
		if(ispalin) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	
	sort(s.begin(),s.end());
	
	int ans=0;
	do
	{
		if(!has(s,k))
		{
			ans++;
		}
	}while(next_permutation(s.begin(),s.end()));
	
	cout<<ans<<endl;
	return 0;
}
