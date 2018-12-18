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
bool cmp(pair<string,int>a ,pair<string,int> b)
{
	return a.second < b.second;
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
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	
	for(int t=0;t<T;t++)
	{	
		int n;
		cin>>n;
		vector<pair<string,int> > namelist;
		string s;
		int r;
		for(int i=0;i<n;i++)
		{
			cin>>s>>r;
			namelist.emplace_back(s,r);
		}
		sort(namelist.begin(),namelist.end(),cmp);
		//for(int i=0;i<namelist.size();i++)
		//	cout<<namelist[i].first<<"  "<<namelist[i].second<<endl;
		bool f=false;
		string res;
		for(int i=0;i<namelist.size();)
		{
			int c=1;
			int j=i+1;
			while(j<namelist.size() && namelist[i].second==namelist[j].second)
			{
				c++;
				j++;
			}
			if(c==1)
			{
				f=true;
				res=namelist[i].first;
				break;
			}
			else
				i+=c;
			
		}
		if(!f)
			cout<<"Nobody wins."<<endl;
		else
			cout<<res<<endl;		
	}
	return 0;
}
