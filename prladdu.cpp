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
		int n;
		cin>>n;
		/*vector<pair<int,int> > pos,neg;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a>0)
				pos.emplace_back(i,a);
			else
				neg.emplace_back(i,a);
		}
		sort(pos.begin(),pos.end());
		sort(neg.begin(),neg.end());
		int i=0,j=0;
		int s=0;
		while(i<pos.size() && j<neg.size())
		{
			if(pos[i].second + neg[j].second ==0)
			{
				s+=(abs(pos[i].first-neg[j].first)*pos[i].second);
				i++;
				j++;
			}
			else if(pos[i].second + neg[j].second >0)
			{
				s+=(abs(pos[i].first-neg[j].first) *(-1)* neg[j].second);
				pos[i].second+=neg[j].second;
				
				j++;
			}
			else if(pos[i].second + neg[j].second <0)
			{
				s+=abs(pos[i].first-neg[j].first)*pos[i].second;
				neg[j].second+=pos[i].second;
				
				i++;
			}

		}*/
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int i=0,j=0;
		long long s=0;
		while(i<n && j<n)
		{
			while(a[i]<0)
				i++;	
			while(a[j]>0)
				j++;
			if(a[i] + a[j] ==0)
			{
				s+=(abs(i-j)*a[i]);
				i++;
				j++;
			}
			else if(a[i] + a[j] >0)
			{
				s+=(abs(i-j) *(-1)* a[j]);
				a[i]+=a[j];
				
				j++;
			}
			else if(a[i] + a[j] <0)
			{
				s+=abs(i-j)*a[i];
				a[j]+=a[i];
				
				i++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}	
