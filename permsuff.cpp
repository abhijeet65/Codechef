//c lang headers
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
#include<unistd.h>
#include<stdint.h> 
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

int main()
{
	ios_base::sync_with_stdio(false);	
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int n,m;
		cin>>n>>m;
				
		vector<int> a(n+1);
		vector<pair<int,int> >p;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
		{
			int l,r;
			cin>>l>>r;
			p.push_back(make_pair(l,r));
		}
		sort(p.begin(),p.end());
		int first=p[0].first,second=p[0].second; 
		for(int i=1;i<m;i++)
		{
			//cout<<p[i].first<<" "<<p[i].second<<endl;
			if(second < p[i].first )
			{
				sort(a.begin()+first,a.begin()+second+1);
				first=p[i].first;second=p[i].second; 
			}
			else
			{
				if(second<p[i].second)
					second=p[i].second; 
			}
		}
		sort(a.begin()+first,a.begin()+second+1);
		bool f=true;
		for(int i=1;i<=n;i++)
		{//cout<<a[i];
			if(i!=a[i])
			{
				
				f=false;
				//break;
			}
		}
		if(f)
			cout<<"Possible\n";
		else
			cout<<"Impossible\n";
	}
	return 0;
}
