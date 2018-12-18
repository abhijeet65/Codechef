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
bool comp(pair<long long,long long> a,pair<long long,long long> b)
{
	return a.second<b.second;

}
int main()
{
	ios_base::sync_with_stdio(false);
	long long N,M,H;
	cin>>N>>M>>H;
	long long cost=0;
	long long nm=N*M;
	vector<pair<long long,long long> > tc(H);
	for(int i=0;i<H;i++)
	{	
		
		cin>>tc[i].first>>tc[i].second;
	}
	sort(tc.begin(),tc.end(),comp);
	for(int i=0;i<H && nm>0;i++)
	{
		int topaint=min(tc[i].first,nm);
		cost+=topaint*(tc[i].second);
		nm-=topaint;
	}
	if(nm==0)
		cout<<cost<<"\n";
	else
		cout<<"Impossible\n";
	return 0;
}
