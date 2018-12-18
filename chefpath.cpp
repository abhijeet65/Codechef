#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long m,n;
		cin>>m>>n;
		if(m%2 && n%2)
			cout<<"No\n";
		else if((m==1 && n==2)||(m==2 && n==1))
			cout<<"Yes\n";
		else if((m==1 && n>2)||(m>2 && n==1))
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}