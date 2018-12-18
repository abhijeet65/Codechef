#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string role;
		cin>>n>>role;
		int p;
		string activity;
		int points=0;
		while(n--)
		{
			cin>>activity;
			if(activity=="CONTEST_WON")
			{
				cin>>p;
				points+=300;
				if(p>=1 && p<=20)
					points+=20-p;
			}
			else if(activity=="TOP_CONTRIBUTOR")
			{
				points+=300;
			}
			else if(activity=="BUG_FOUND")
			{
				cin>>p;
				points+=p;
			}
			else if(activity=="CONTEST_HOSTED")
			{
				points+=50;
			}	
		}
		if(role=="INDIAN")
			cout<<points/200;
		else if(role=="NON_INDIAN")
			cout<<points/400;
		cout<<'\n';		
	}
	return 0;
}