#include<iostream>
#include<ctime>
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
	
	char a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr[i]=a-'0';
		
	}	
	int freq[n][10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
			freq[i][j]=0;
		for(int j=0;j<=i;j++)
			freq[i][arr[j]]++;
	}
	for(int t=0;t<m;t++)
	{
		int x;
		cin>>x;	
		if(x==1)
			cout<<0<<endl;
		else
		{
			
			long left=0,right=0,l=0,r=0;
			for(int i=0;i<arr[x-1];i++)
			{	left+=i*freq[x-2][i];
				l+=freq[x-2][i];
			}
			for(int i=arr[x-1]+1;i<10;i++)
			{	right+=i*freq[x-2][i];
				r+=freq[x-2][i];
			}
			cout<<(l*arr[x-1]-left+right-r*arr[x-1])<<endl;
				
		}
	}
	t1 = time(NULL);

    c1 = clock();


    cerr<<"wall clock time "<< (long) (t1 - t0);

    cerr<<"CPU time "<< ((float) (c1 - c0) / CLOCKS_PER_SEC);
	return 0;
}