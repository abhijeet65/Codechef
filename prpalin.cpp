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
 #include<sstream>
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
using namespace std;
#define MOD 1000000007
bool isprime(int n)
{
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i ==0)
			return false;
	}
	return true;
}
bool ispalindrome(int n)
{	
	int p=n;
	int r=0;
	while(n>0)
	{
		r=r*10+ n%10;
		n=n/10;
	}
	return p==r ;
}

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
int main(int argc,char* argv[])
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int i;
	for( i=n;i<n+6;i++)
	{		
		if( ispalindrome(i) && isprime(i) )
		{
			cout<<i;
			return 0;
		}
	}
	i=i/6;
	for(;;i++)
	{
		int num=6*i-1;
		if( ispalindrome(num) && isprime(num) )
		{
			cout<<num;
			return 0;
		}
		 num=6*i+1;
		if( ispalindrome(num) && isprime(num) )
		{
			cout<<num;
			return 0;
		}
	}
	
	
					
	
	return 0;
}
