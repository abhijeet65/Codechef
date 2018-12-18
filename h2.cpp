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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TREP(it,c) \
for (auto it = (c).begin(); it != (c).end(); it++)


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
class FastInput {
public:
    FastInput() {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    
    }
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
bool isparted(double a,vector<pair<int,int> > &points)
{
	int N=points.size();
	double dist[N];
	double div=sqrt(a*a+1);
	for(int i=0;i<N;i++)
	{
		dist[i]=(a*points[i].first-points[i].second)/div;
	}
	sort(dist,dist+N);
	for(int i=0;i+i<N;i++)
	{
		if(dist[i]+dist[N-i-1]>0)
			return false;	
	}
	return true;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	FastInput in;
	int T=in.ReadNext();
	vector<pair<int,int> >points(T);
	for(int t=0;t<T;t++)
	{	
		points[t].first=in.ReadNext()+10;
		points[t].second=in.ReadNext();
	}
	double high=1.9,low=0.1;
	while(high-low>1e-8)
	{
		double mid=(low+high)/2;
		if(isparted(mid,points))
			low=mid;
		else
			high=mid;
	}
	cout<<fixed<<setprecision(6)<<(low+high)/2<<"\n";
	return 0;
}
