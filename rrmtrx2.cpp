#include<bits/stdc++.h>
#define MOD  10000007
using namespace std;
int main()
{
	int m,n,k;
	cin>>n>>m;
	vector<long long> s(m,0);
	long long ans=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>k;
			s[j]+=k;
		}
		
	}
	for(int j=0;j<m;j++)
	{		
		ans=(ans*s[j])%MOD;
	}	
	ans=(ans+MOD)%MOD;
	cout<<ans<<"\n";
	return 0;
}