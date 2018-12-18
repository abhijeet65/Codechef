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


class dish
{
	private: int *score;
		int *own;
	public: dish(int N)
	{
		score=new int[N];
		own=new int[N];
		for(int i=0;i<N;i++)
		{
			cin>>score[i];	
			own[i]=i;
		}

	}	 
	int root(int p)
	{
		while(p!=own[p])
		{
			own[p]=own[own[p]];
			p=own[p];
		}
		return p;
	}
	bool isSameOwner(int p,int q)
	{
		return root(p)==root(q);
	}
	void takeOver(int p,int q)
	{
		int pid=root(p);
		int qid=root(q);
		if(pid!=qid)
		{
			if(score[pid]<score[qid])
			{
				own[pid]=qid;
				
			}
			else if(score[pid]>score[qid])
			{
				own[qid]=pid;
			}
		}
	}	
};
int main()
{
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{	
		int N;
		cin>>N;
		dish obj=dish(N);
		int Q;
		cin>>Q;
		for(int i=0;i<Q;i++)
		{
			int q;
			cin>>q;
			if(q==0)
			{
				int x,y;
				cin>>x>>y;
				x--;y--;
				if(obj.isSameOwner(x,y))
				{	
					cout<<"Invalid query!\n";
				}
				else
				{
					obj.takeOver(x,y);
				}
			}
			else 
			{
				int x;
				cin>>x;
				x--;
				cout<<obj.root(x)+1<<"\n";
			}
		}
	}
	return 0;
}
