#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,n,k;
		cin>>m>>n>>k;
		vector<bool> igr(m+1,0);
		vector<bool> trc(m+1,0);
		int l;
		for(int i=0;i<n;i++)
		{	cin>>l;
			igr[l]=1;
		}
		for(int i=0;i<k;i++)
		{	cin>>l;
			trc[l]=1;
		}
		int ti=0,uu=0;
		for(int i=1;i<=m;i++)
		{	
			if(igr[i] && trc[i])
				ti++;
		}
		for(int i=1;i<=m;i++)
		{	
			if(!igr[i] && !trc[i])
				uu++;
		}
		cout<<ti<<" "<<uu<<"\n";
	}	



}
