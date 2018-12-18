#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int a;
		bool f=false;
		int m=INT_MAX;
		long long sum=0;
		for(int i=0;i<N;i++)
		{	cin>>a;
			sum+=a;
			m=min(a,m);
		}
		if(m<2)
			cout<<"-1\n";
		else
			cout<<sum-m+2<<"\n";

	}	
	return 0;
		
}
