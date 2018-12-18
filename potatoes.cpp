#include<iostream>
using namespace std;
int main()
{
	int prime[2000];
	prime[0]=2;
	int k=1;
	for(int i=3;k<2000;i=i+2)
	{
		bool flag=true;
		for(int j=3; j<i;j++)
			if(i%j==0)
				flag=false;
		if(flag)	
			prime[k++]=i;
			
	}		
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
		{
			int x,y,z;
			cin>>x>>y;
			for(int j=0;j<2000;j++)
				if(prime[j]>x+y)
				{
					z=prime[j]-x-y;
					break;
				}
			cout<<z<<endl;	
		}
	return 0;
}