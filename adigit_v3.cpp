#include<iostream>
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
	int count[10];
	char a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[i]=a-48;
		
	}	
	long result[n];
	for(int i=0;i<10;i++)
					count[i]=0;
	result[0]=0;		
	for(int x=1;x<n;x++)
	{
				
		count[arr[x-1]]++;
		
		
			
			
			long res=0;
			for(int i=0;i<arr[x];i++)
			{	res+=(arr[x]-i)*count[i];
				
			}
			for(int i=arr[x]+1;i<10;i++)
			{	res+=(i-arr[x])*count[i];
				
			}
			result[x]=res;
				
		
	}
	for(int t=0;t<m;t++)
	{
		int x;
		cin>>x;	
		cout<<result[x-1]<<endl;
	}
	t1 = time(NULL);

    c1 = clock();


    cerr<<"wall clock time "<< (long) (t1 - t0);

    cerr<<"CPU time "<< ((float) (c1 - c0) / CLOCKS_PER_SEC);
	return 0;
}
