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
	int a[T];
	for(int t=0;t<T;t++)
		cin>>a[t];
	int count=0;
	bool f[T];
	memset(f,0,T*sizeof(bool));
	int mark=0;
	int ind=1;
	vector<vector<int> > l;	
	while(mark<T)
	{
		for(int i=0;i<T;i++)
			if(a[i]==ind)
			{
				ind=i;
				break;
			}
		int t=ind;
		l.push_back(vector<int>());
		int s=l.size()-1;
		do
		{
			l[s].push_back(a[t]);
			f[a[t]-1]=true;
			mark++;
			t=a[t]-1;				
		}while(t!=ind);
		l[s].push_back(a[ind]);
		for(int i=0;i<T;i++)
			if(f[i]==false)
			{
				ind=i+1;
				break;
			}
		
	}
	cout<<l.size()<<"\n";
	for(int i=0;i<l.size();i++)
	{
		for(int j=0;j<l[i].size();j++)
			cout<<l[i][j]<<" ";
		cout<<"\n";
	}	
	return 0;
}
