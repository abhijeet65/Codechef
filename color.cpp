#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int r=0,g=0,b=0;
		for(int i=0;i<n;i++)
		{
			switch(s[i])
			{
				case 'R': r++; break;
				case 'G': g++; break;
				case 'B': b++; break;
			}
		}
		int ans=min(min(r+b,r+g),g+b);
		cout<<ans<<'\n';
	}
	return 0;
}