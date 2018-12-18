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
long long count_split_inversion(int a[],int l,int m,int h,int b[])
{
	int n1=m-l,n2=h-m+1;
	long long invcount=0;	
	int i=l,j=m,k=l;	
	while(i<m && j<=h)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else 
		{
			b[k]=a[j];
			//cout<<a[i]<<" "<<a[j]<<" "<<m-i<<endl;
			j++;
			invcount+=m-i;
						
		}	
		k++;
	}

	while(i<m)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(int i=l;i<=h;i++)
		a[i]=b[i];
	return invcount;
}
long long count_inversion(int a[],int l,int h,int b[])
{
	long long icount=0;
	if(l<h)
	{
		int m=(h+l)/2;
		icount=count_inversion(a,l,m,b);
		icount+=count_inversion(a,m+1,h,b);
		icount+=count_split_inversion(a,l,m+1,h,b);
	} 
	return icount;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int a[T];
	for(int t=0;t<T;t++)
	{	
		cin>>a[t];
	}
	int b[T];
	
	cout<<count_inversion(a,0,T-1,b)<<"\n";
	return 0;
}
