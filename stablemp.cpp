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
int men[501][501];
int women[501][501];
int wPartner[501];
bool mFree[501];
int main()
{
	ios_base::sync_with_stdio(false);
		
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int n;
		cin>>n;
		memset(men,0,sizeof(men));
		memset(women,0,sizeof(women));
		memset(wPartner,0,sizeof(wPartner));
		memset(mFree,0,sizeof(mFree));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n;j++)
				cin>>women[i][j];
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n;j++)
				cin>>men[i][j];
		int free=n;
		while(free>0)
		{
			int m;
			for(m=1;mFree[m];m++);
			
			for(int i=1;i<=n && !mFree[m];i++)
			{
				int w=men[m][i];
				if(wPartner[w]==0)
				{
					mFree[m]=1;
					wPartner[w]=m;
					free--;
				}
				else
				{
					bool prefer;
					for(int i=1;i<=n;i++)
					{
						if(women[w][i]==m)
						{
							prefer=true;
							break;
						}
						if(women[w][i]==wPartner[w])
						{
							prefer=false;
							break;
						}	
					}
					if(prefer)
					{
						mFree[wPartner[w]]=0;
						wPartner[w]=m;
						mFree[m]=1;
						
					}
				}
			}
		}
		vector<pair<int,int> > sol;
		for(int i=1;i<=n;i++)
		sol.emplace_back(wPartner[i],i);
		sort(sol.begin(),sol.end());
		for(int i=0;i<n;i++)
			cout<<sol[i].first<<" "<<sol[i].second<<"\n";
			
	}
	return 0;
}
