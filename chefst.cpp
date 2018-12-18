#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long m,n,k;
		cin>>m>>n>>k;
		long long s=k*(k+1)/2;
		long long mi=min(min(m,n),s);
		cout<<(m-mi)+(n-mi)<<"\n";		
	}
	return 0;
}
