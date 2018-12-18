#include<bits/stdc++.h>
using namespace std;
unsigned long long MOD=1000000007;
unsigned long long power(unsigned long long a,unsigned long long b)
{
	unsigned long long p=1;
	a%=MOD;
	while(b)
	{		
		if(b&1)
			p=p*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return p;	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		unsigned long long ans=1;
		if(n>=1)
			ans=(ans*k)%MOD;
		ans=(ans*power(k-1,n-1))%MOD;
		
		cout<<ans<<'\n';
	}
	return 0;
}