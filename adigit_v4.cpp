#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	clock_t c0, c1;

    time_t t0, t1;


    t0 = time(NULL);

    c0 = clock();
	std::ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int arr[n];
	int count[10][n];
	memset(count,0,sizeof(int)*10*n);
	char a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[i]=a-48;
		
	}	
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			count[i][j]=(arr[j]==i);
			else	
			count[i][j]=count[i][j-1]+(arr[j]==i);
		}
	}
	for(int t=0;t<m;t++)
	{
		int x;
		cin>>x;	
		if(x==1)
			cout<<0<<endl;
		else
		{
			int b1=0,b2=0;
			int p=arr[x-1];
			for(int i=0;i<p;i++)
			{	
				b1+=count[i][x-2]*(p-i);
			}
			for(int i=p+1;i<10;i++)
			{	
				b2+=count[i][x-2]*(i-p);
			}
			cout<<(b1+b2)<<endl;
				
		}
	}
	t1 = time(NULL);

    c1 = clock();


    cerr<<"wall clock time "<< (long) (t1 - t0);

    cerr<<"CPU time "<< ((float) (c1 - c0) / CLOCKS_PER_SEC);
	return 0;
}
