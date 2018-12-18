#include<bits/stdc++.h>
#define MOD  10000007
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		long long profit=0;
		for(int i=0;i<n;i++)
		{
			profit=max(profit,((long long)k/a[i])*b[i]);
		}	
		cout<<profit<<"\n";
	}	
	return 0;
}