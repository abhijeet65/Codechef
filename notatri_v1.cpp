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
	int n;
	cin>>n;
	while(n>0)
	{
		int a[n];
		for(int t=0;t<n;t++)
		{	
			cin>>a[t];
		}
		sort(a,a+n);
		int c=0;
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				int low=j+1,high=n-1;
				while(low<high)
				{
					int mid=(low+high)/2;
					if(a[i]+a[j]<a[mid])	
					{
						high=mid;
					}
					else
					{
						low=mid+1;
					}	
				}
				if(a[low]>a[i]+a[j])
					c+=n-low;					
			}	
		}
		cout<<c<<"\n";	
		cin>>n;
	}		
	return 0;
}
