#include<bits/stdc++.h>
#define MOD  10000007
using namespace std;
int main()
{
	double invsum[3001]={0};
	for(int i=1;i<=3000;i++)
		invsum[i]=invsum[i-1]+1.0/i;
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cout<<setprecision(15);
		cout<<invsum[N]*N<<"\n";
	}	
	
	return 0;
}