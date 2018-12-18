#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int i,j;
		cin>>i>>j;
		int count=0;
		while(i!=j)
		{
			if(i>j)
			{
				if(i%2==0)
					i=i/2;
				else
					i=(i-1)/2;
				count++;
			}
			else if(j>i)
			{
				if(j%2==0)
					j=j/2;
				else
					j=(j-1)/2;
				count++;
			}	
		}
		cout<<count<<endl;	

	}
	return 0;
}