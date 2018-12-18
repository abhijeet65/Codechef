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
	for(int t=0;t<T;t++)
	{	
		string q;
		cin>>q;
		string p[4]={"00","01","10","11"};
		vector<string> res;
		string s;
		for(int j=0;j<4;j++)
		{
			s=p[j];
			for(int i=2;i<q.size();i++)
				s+=(s[i-2]^s[i-1]^q[i-1]);
			
			string qs="";
			qs+=s[s.size()-1]^s[0]^s[1];
			for(int i=1;i<q.size()-1;i++)
				qs+=(s[i-1]^s[i]^s[(i+1)]);
			qs+=s[s.size()-2]^s[s.size()-1]^s[0];
			if(qs==q)
				res.emplace_back(s);	
			//cout<<s<<"  "<<qs<<"\n"; 		
		}
		if(res.size()==1)
			cout<<res[0]<<"\n";
		else if(res.size()==0)
			cout<<"No solution\n";
		else
			cout<<"Multiple solutions\n";								
	}
	return 0;
}
