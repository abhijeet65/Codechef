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
vector<pair<int,int> > t[100000];
map<int,int> mp;	
int main()
{
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int tp=0;tp<T;tp++)
	{	
		int n,k;
		cin>>n>>k;
		if(n==0)
		{
			cout<<"0\n";
			continue;
		}
		mp.clear();
		for(int i=0;i<100000;i++)
			t[i].clear();
		int s,f,p;
		int pos=0;
		for(int i=0;i<n;i++)
		{
			cin>>s>>f>>p;
			//cout<<s<<f<<p;
			if(mp.count(p)==0)
			{
				mp[p]=pos++;
			}
			t[mp[p]].emplace_back(f,s);			
		}
		
		//cout<<pos;	
		int count=0;
		for(int i=0;i<pos;i++)
		{
			sort(t[i].begin(),t[i].end());
				count++;
			int last=t[i][0].first;	
			for(int j=1;j<t[i].size();j++)
			{
				if(t[i][j].second>=last)
				{
					count++;
					last=t[i][j].first;
				}
			}
			
		}
		cout<<count<<"\n";		
	}
	return 0;
}
