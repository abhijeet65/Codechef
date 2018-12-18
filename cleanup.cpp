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
		int n,m;
		cin>>n>>m;
		int f[m];
		for(int i=0;i<m;i++)
			cin>>f[i];
		sort(f,f+m);
		vector<int> c;
		vector<int> a;
		bool turn=true;
		for(int i=1,j=0;i<=n;i++)
		{
			if(i ==f[j])
			{
				j++;
				continue;
			}
			if(turn)
			{
				c.push_back(i);
				turn=false;
			}
			else
			{
				a.push_back(i);
				turn=true;
			}						
		}
		for(int i=0;i<c.size();i++)
			cout<<c[i]<<" "; 
		cout<<"\n";
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" "; 
		cout<<"\n";
	}		
	return 0;
}
