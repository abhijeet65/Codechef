#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		vector<long long> x(n);
		long long sum=0;
		for(int i=0;i<n;i++)
		{	cin>>x[i];
			sum+=x[i];
		}
		sum/=n-1;
		for(int i=0;i<n;i++)
		{	
			cout<<sum-x[i]<<" ";
		}
		cout<<"\n";
	}	



}
