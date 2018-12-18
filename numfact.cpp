#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin >> T;
	vector<int> prime;
	prime.push_back(2);
	for(int i=3;i<1000000;i=i+2)
	{
		bool flag=true;
		for(int j=3;j<=sqrt(i);j+=2)
		{
			if(i%j==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			prime.push_back(i);
	}
	
	for(int t=0;t<T;t++)
	{
		int n;
		cin>>n;
		int power[prime.size()];
		memset(power,0,sizeof(int)*prime.size());
		for(int i=0;i<n;i++)
		{
			int num;
			cin>>num;
			int j=0;
			while(num>1)
			{
				while(num%prime[j]==0)
				{
					power[j]++;
					num/=prime[j];
				}
				j++;
			}
		}
		long long res=1L;
		for(unsigned int i=0;i<prime.size();i++)
			res*=(power[i]+1);
		cout<<res<<endl;
	}

	return 0;
}
