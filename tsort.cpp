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
	
	vector<int> b(T);
	vector<int> a(T);
	
	int i=0;
	int max=-1;
	while(i<T)
	{
		cin>>a[i];
		if(a[i]>max)
			max=a[i];
		i++;
	}
	vector<int> c(max+1,0);
	
	for(int i=0;i<T;i++)
	{
		c[a[i]]++;
	}
	
	for(int i=1;i<=max;i++)
	{
		c[i]+=c[i-1];
	}
	
	for(int i=T-1;i>=0;i--)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	
	for(int i=0;i<T;i++)
	{
		cout<<b[i]<<"\n";
	}
	return 0;
}
