#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		int ans=0;
		int k;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			cin>>k;
			ans=ans^i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}