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
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int a[10];
		int min=10,ind;
		for(int i=0;i<10;i++)
		{	cin>>a[i];
			if(min>a[i])
			{
				min=a[i];
				ind=i;
			}
		}
		if(ind==0)
		for(int i=1;i<10;i++)
		{
			if(min==a[i])
			{
				ind=i;
				break;
			}
		}
		if(ind==0)
		{
			cout<<"1";
			for(int i=0;i<=a[ind];i++)
				cout<<"0";
		}
		else
		{
			for(int i=0;i<=a[ind];i++)
				cout<<ind;
		}
		cout<<"\n";
	}
	return 0;
}
