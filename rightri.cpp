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
int dist(int x1,int y1,int x2,int y2)
{
	return  ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int c=0;	
	for(int t=0;t<T;t++)
	{	
		int x1,y1,x2,y2,x3,y3;
		cin>> x1>>y1>>x2>>y2>>x3>>y3;
		int d1=dist(x1,y1,x2,y2);
		int d2=dist(x1,y1,x3,y3);
		int d3=dist(x3,y3,x2,y2);
		c+=(2*max(d1,max(d2,d3))==d1+d2+d3);
	}
	cout<<c<<"\n";
	return 0;
}
