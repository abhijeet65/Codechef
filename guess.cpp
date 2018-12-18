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
 long long gcd(long long m, long long n)
{
	unsigned long long r;	
	do
	{
		 r=m%n;
		m=n;
		n=r;
	}while(r!=0);
	return m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int m,n;
		cin>>m>>n;
		int even1=m/2;
		int odd1=m-even1;
		int even2=n/2;
		int odd2=n-even2;
		long long num=(long long)(even1*(long long)odd2+even2*(long long)odd1);
		long long dem=m*(long long)n;
		//cout<<num<<"  "<<dem<<endl;
		if(num==0)
			cout<<num<<"/"<<dem<<endl;
		else
		{
			long long g=gcd(dem,num);
			cout<<num/g<<"/"<<dem/g<<endl;
		}
	}
	return 0;
}
