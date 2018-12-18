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
bool comp(pair<int,int> a,pair<int,int> b)
{
	if(a.first!=b.first)
		return a.first<b.first;
		return a.second>b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	
	for(int t=0;t<T;t++)
	{	
		char ch;
		//cin>>ch;
		int n;
		cin>>n;
		vector<pair<int ,int> > p(n);
		for(int i=0;i<n;i++)
			cin>>p[i].first>>p[i].second;
		sort(p.begin(),p.end(),comp);
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		long double dist=0.0;
		for(int i=1;i<n;i++)
			dist+=sqrt((p[i].first-p[i-1].first)*(p[i].first-p[i-1].first)
				+(p[i].second-p[i-1].second)*(p[i].second-p[i-1].second));
		printf("%.2llf\n",dist);
				
	}
	
	return 0;
}
