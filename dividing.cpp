#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long sum=0;
	int k;
	for(int i=0;i<n;i++)
	{	
		cin>>k;
		sum+=k;
	}
	long desired=n*(n+1)/2;
	if(desired==sum)
		cout<<"YES";
	else
		cout<<"NO";		
	return 0;
}