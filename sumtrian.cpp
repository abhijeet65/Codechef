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

void sumdp(const vector<int> &a,int n,vector<int> &s)
{
	for(int i=0;i<n;i++)
		s[(n-1)*n+i]=a[(n-1)*n+i];
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i;j>=0;j--)
		{
			s[i*n+j]=a[i*n+j]+max(s[(i+1)*n+j],s[(i+1)*n+j+1]);
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n*n,0);
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>a[i*n+j];
		vector<int> sp(n*n,-1);
		sumdp(a,n,sp);
		cout<<sp[0]<<endl;
	}
	return 0;
}
