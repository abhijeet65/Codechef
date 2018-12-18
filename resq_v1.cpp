#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
 
//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>
 
//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>
 
 
//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

#define MOD 1000000007

using namespace std;
inline void fastRead(int *a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
	    *a=*a*10+c-'0';
	    c=getchar_unlocked();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	vector<bool> isprime(10001,true);
	vector<int> prime;
	for(int p=2;p<10001;p++)
	{
		if(isprime[p])
		{
			prime.push_back(p);
			for(int q=p+p;q<10001;q+=p)
				isprime[q]=false;
		}
	}
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int n;
		cin>>n;
		vector<int> divisiors;
		divisiors.push_back(1);
		for(int i=0,num=n;i<prime.size() && num>1;i++)
		{
			int p=prime[i];
			if (p * p > num) {
				p = num;
			}
			if(num%p==0)
			{
				int deg=0;
				while(num%p==0)
				{
					deg++;
					num/=p;					
				}
				int lim=divisiors.size();
				for(int j=0;j<lim;j++)
				{
					int div=divisiors[j];
					for(int k=1;k<=deg;k++)
					{	div*=p;
						divisiors.push_back(div);
					}					
				}			
			}
		}
		int ans=INT_MAX;
		for(int t=0;t<divisiors.size();t++)
		{	
			cout<<divisiors[t]<<"\n ";
			ans=min(ans,abs(divisiors[t]- n/divisiors[t]));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
