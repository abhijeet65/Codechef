#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	int f[32];
	for (int i = 0; i < 32; i++)
		f[i]=0;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<32;j++)
		{
			if(a[i]&(1<<j))
				f[j]++;

		}
	}
	for (int i = 0; i < 32; i++)
		sum+=(1LL*f[i]*(1LL*f[i]-1LL)*(1LL<<i)/2LL);
	cout<<sum;
	delete a;
	return 0;
}
