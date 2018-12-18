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
	int N;
	cin>>N;
	vector<int> one,two;
	int W=0;
	for(int i=0;i<N;i++)
	{	
		int w,c;
		cin>>w>>c;
		if(w==1)
			one.push_back(c);
		else
			two.push_back(c);
		W+=w;
	}
	sort(one.begin(),one.end());
	sort(two.begin(),two.end());
	vector<int>ONE=one,TWO=two;
	long long cur=0;
	long long cost[W+1];
	//memset(cost,0,(W+1)*sizeof (long long));	
	for(int i=2;i<=W;i+=2)
	{
		int c1=0,c2=0;
		if(two.size()>=1)
			c1=two.back();
		bool f=true;
		
		if(one.size()>=2)
			c2=(long long)one.back()+one[one.size()-2]; 
		else if(one.size()>=1)
		{	c2=one.back(); f=false;}
		if(c1>c2)
		{
			cur+=c1;
			two.pop_back();
		}
		else
		{
			cur+=c2;
			one.pop_back();
			if(f)
				one.pop_back();
		}
		cost[i]=cur;			
	}
	one=ONE,two=TWO;
	cur=0;
	if(one.size()>=1)
	{
		cur=one.back();
		one.pop_back();
	}
	cost[1]=cur;
	for(int i=3;i<=W;i+=2)
	{
		int c1=0,c2=0;
		if(two.size()>=1)
			c1=two.back();
		bool f=true;
		
		if(one.size()>=2)
			c2=(long long)one.back()+one[one.size()-2]; 
		else if(one.size()>=1)
		{	c2=one.back(); f=false;}
		if(c1>c2)
		{
			cur+=c1;
			two.pop_back();
		}
		else
		{
			cur+=c2;
			one.pop_back();
			if(f)
				one.pop_back();
		}
		cost[i]=cur;			
	}
	for(int i=1;i<=W;i++)
		cout<<cost[i]<<" ";
	return 0;
}
