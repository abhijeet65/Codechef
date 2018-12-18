
#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int> a,pair<int,int> b)
{
	if( abs(a.first-a.second)!=abs(b.first-b.second))
		return abs(a.first-a.second)>abs(b.first-b.second);
	return a.first>b.first;
}
vector<pair<int,int> > a;
vector<vector<long long> >dp;
	
int main()
{
	int N;
	int m,n,l;
	long long c=0;
	cin>>N>>m>>n;
	a.resize(N);
	for(int i=0;i<N;i++)
	{
		cin>>a[i].first;
	}
	for(int i=0;i<N;i++)
	{
		cin>>a[i].second;
	}

	if(N>0)
	{	
	sort(a.begin(),a.end(),cmp);
	
	
	int x=0,y=0;
	for(int i=0;i<N;i++)
	{
		if(a[i].first>a[i].second)
		{
			if(x<m)
			{
				x++;
				c+=a[i].first;
			}
			else
			{
				y++;
				c+=a[i].second;
			}	
		}
		else
		{
			if(y<n)
			{
				y++;
				c+=a[i].second;
			}
			else
			{
				x++;
				c+=a[i].first;
			}	
		}	
	}
	}
	else if(N>20)
	{

		dp.resize(N+1,vector<long long>(m+1,0));
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<=m;j++)
			{
				long long x=0,y=0;
				if(j>0 && j<=m)
					x=dp[i-1][j-1]+a[i-1].first;
				if(i-j>0 && i-j<=n)
					y=dp[i-1][j]+a[i-1].second;
				dp[i][j]=max(x,y);
				//cout<<dp[i][j]<<" ";
			}		
			//cout<<endl;
		}	
		c=*max_element(dp[N].begin(),dp[N].end());
	}
	else
	{
		
		for(int mask=0;mask<(1<<N);mask++)
		{
			int x=0,y=0;
			long long ct=0;
			for(int i=0;i<N;i++)
			{
				if(mask & (1<<i))
				{
					x++;
					ct+=a[i].first;
				}
				else
				{
					y++;
					ct+=a[i].second;
				}	
			}	
			//cout<<ct<<"\n";
			if(x<=m && y<=n)
				c=max(c,ct);
		}	
	}	
	cout<<c<<"\n";
	return 0;
}