#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		long long max=a[0];
		for(int j=1;j<n;j++)
			if(a[j]>max)
				max=a[j];
		for(int j=0;j<n;j++)
			a[j]=max-a[j];
	}
	else if(k>1 && k%2==0)
	{
		for(int k=0;k<2;k++)
		{
			long long max=a[0];
		for(int j=1;j<n;j++)
			if(a[j]>max)
				max=a[j];
		for(int j=0;j<n;j++)
			a[j]=max-a[j];
		}	
	}
	else if(k>1 && k%2!=0)
	{
		for(int k=0;k<3;k++)
		{
			long long max=a[0];
		for(int j=1;j<n;j++)
			if(a[j]>max)
				max=a[j];
		for(int j=0;j<n;j++)
			a[j]=max-a[j];
		}	
	}	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}