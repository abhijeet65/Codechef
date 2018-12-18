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
int partition(int a[],int l,int h)
{
	int r=l+rand()%(h-l+1);
	swap(a[r],a[l]);	
	int pivot=a[l];
	int i=l;
	int j=l+1;
	while(j<=h)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
		j++;
	}
	swap(a[l],a[i]);
	return i;
}
void quickSort(int a[],int l,int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}	


}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int a[T];
	
	for(int i=0;i<T;i++)
	{
		cin>>a[i];
	}
	
	
	quickSort(a,0,T-1);
	
	for(int i=0;i<T;i++)
	{
		cout<<a[i]<<"\n";
	}
	return 0;
}
