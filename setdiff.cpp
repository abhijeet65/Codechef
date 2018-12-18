#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
int main()
{
	int T;
	cin>>T;
	long long p[100001];
	p[0]=1;
	for(int i=1;i<100001;i++)
		p[i]=(p[i-1]*2)%mod;
	while(T--)
	{
		int N;
		cin>>N;
		int a[N];
		bool f=false;
		for(int i=0;i<N;i++)
		{	cin>>a[i];
		}
		sort(a,a+N);
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			ans=(ans+ ((p[i]-p[N-1-i])%mod)*a[i])%mod;
			
		}	
		cout<<ans<<"\n";
	}	
	return 0;
		
}