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
	map<char,int> lookup;
	lookup['A']=1;
	lookup['B']=2;
	lookup['C']=0;
	lookup['D']=1;
	lookup['E']=0;
	lookup['F']=0;
	lookup['G']=0;
	lookup['H']=0;
	lookup['I']=0;
	lookup['J']=0;
	lookup['K']=0;
	lookup['L']=0;
	lookup['M']=0;
	lookup['N']=0;
	lookup['O']=1;
	lookup['P']=1;
	lookup['Q']=1;
	lookup['R']=1;
	lookup['S']=0;
	lookup['T']=0;
	lookup['U']=0;
	lookup['V']=0;
	lookup['W']=0;
	lookup['X']=0;
	lookup['Y']=0;
	lookup['Z']=0;

	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int count=0;
		for(int j=0;j<s.size();j++)
			if(s[j]=='B')
				count+=2;
			else if(s[j]=='A' || s[j]=='D' || s[j]=='O' || s[j]=='P' || s[j]=='Q' || s[j]=='R')
				count++; 		
		cout<<count<<endl;;	
	}
	return 0;
}
