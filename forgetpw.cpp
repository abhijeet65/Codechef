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
#include<unordered_map>
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
		int N;
		cin>>N;
		vector <pair<char,char>> dict;
		if(N)
		{
			char a,b;
			for(int i=0;i<N;i++)
			{
				cin>>a>>b;
				dict.emplace_back(a,b);
			}				
		}
		// for (auto it=dict.begin(); it!=dict.end(); ++it)
   		//	 std::cout << it->first << " => " << it->second << '\n';
		string word;
			cin>>word;
		bool point=false;
		stringstream ss;
		if(N)
		{	
			for(int i=0;i<word.length();i++)
			{
				bool f=false;
				int j;
				for( j=0;j<dict.size();j++)
				{
					if(dict[j].first==word[i])
					{
						f=true;
						break;
					}
				}
				if(f)
					ss<<dict[j].second;
				else
					ss<<word[i];
			}
		}
		else 
			ss<<word;
		int i=0;
		string out;
		ss>>out;
		for(int i=0;i<out.length();i++)
		{
			if(out[i]=='.')
			{	
				point=true;
				break;
			}
		}

		while(out[i]=='0')
			i++;
		int j=word.length()-1;
		if(point)
		{
			while(out[j]=='0')
				j--;
			if(out[j]=='.')
				j--;
		}
		if(j<i)
			cout<<"0";
		else
		for(int k=i;k<=j;k++)
			cout<<out[k];
		cout<<endl;
	}
	return 0;
}
