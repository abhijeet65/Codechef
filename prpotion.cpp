//c lang headers
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
#include<unistd.h>
#include<stdint.h> 
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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TREP(it,c) \
for (auto it = (c).begin(); it != (c).end(); it++)


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
		int r,g,b,m;
		cin>>r>>g>>b>>m;
		int rm[3]={INT_MIN,INT_MIN,INT_MIN};
		int a;
		for(int i=0;i<r;i++)
		{	cin>>a;
			rm[0]=max(rm[0],a);
		}
		for(int i=0;i<g;i++)
		{	cin>>a;
			rm[1]=max(rm[1],a);
		}
		for(int i=0;i<b;i++)
		{	cin>>a;
			rm[2]=max(rm[2],a);
		}
		int minso=INT_MAX;
		for(int j=0;j<m;j++)
		{
		int gm=*max_element(rm,rm+3);
		minso=min(minso,gm);
		bool f=true;
		for(int i=0;i<3;i++)
		{
			
			if(rm[i]==gm && f)
			{       f=false;
				rm[i]/=2;
			}
			
		}
		}
		minso=min(minso,*max_element(rm,rm+3));
		cout<<minso<<"\n";
	}
	return 0;
}
