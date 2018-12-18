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
	int M,N;
	cin>>N>>M;
	int a[N][M];
	for(int i=0;i<N;i++)
	{	
		for(int j=0;j<M;j++)
		{
			cin>>a[i][j];
		}
	}
	int K;
	cin>>K;
	long long e1=0,e2=0;
	int i,j;
	bool f1=true,f2=true;
	for(int k=0;k<K;k++)
	{
		cin>>i>>j;
		if(f1 && i<=N && j<=M)
			e1+=a[i-1][j-1];
		else
			f1=false;
		if(f2 && i<=M && j<=N)
			e2+=a[j-1][i-1];
		else
			f2=false;
	}
	if(!f1)
		e1=-1;
	if(!f2)
		e2=-2;
	cout<<max(e1,e2);	
	return 0;
}
