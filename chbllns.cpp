#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,r,g,b;
		long long ans=0;
		cin>>r>>g>>b>>k;
		if(r>=k-1)
			ans+=k-1;
		else
			ans+=r;
		if(g>=k-1)
			ans+=k-1;
		else
			ans+=g;
		if(b>=k-1)
			ans+=k-1;
		else
			ans+=b;
		cout<<ans+1<<'\n';
	}
	return 0;
}