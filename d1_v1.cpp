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
#include<unistd.h>
#include<stdint.h>
 
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

#define MOD 10000

using namespace std;
#define getcx getchar_unlocked
#define LIM 500000LL
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
class FastOutput {
public:
    FastOutput() {
        m_dataOffset = 0;
    }
    ~FastOutput() {
    }
    void Flush() {
        if (m_dataOffset) {
            if (write(1, m_data, m_dataOffset));
            m_dataOffset = 0;
        }
    }
    void PrintUint(uint32_t v, char d) {
        if (m_dataOffset + 11 > sizeof(m_data)) Flush();
        if (v < 100000) {
            if (v < 1000) {
                if (v < 10) {
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 1;
                } else if (v < 100) {
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 2;
                } else {
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 3;
                }
            } else {
                if (v < 10000) {
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 4;
                } else {
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 5;
                }
            }
        } else {
            if (v < 100000000) {
                if (v < 1000000) {
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 6;
                } else if (v < 10000000) {
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 7;
                } else {
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 8;
                }
            } else {
                if (v < 1000000000) {
                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 9;
                } else {
                    m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48;
                    v /= 10;
                    m_data[m_dataOffset + 0] = v + 48;
                    m_dataOffset += 10;
                }
            }
        }
        m_data[m_dataOffset++] = d;
    }
    void PrintChar(char d) {
        if (m_dataOffset + 1 > sizeof(m_data)) Flush();
        m_data[m_dataOffset++] = d;
    }
    void ReplaceChar(int offset, char d) {
        m_data[m_dataOffset + offset] = d;
    }
public:
    uint8_t m_data[32768];
    size_t m_dataOffset;
};
inline void fastRead( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}
inline void fastread(int &a)
{
	register char c=0;
	while (c<33) c=getchar_unlocked();
	a=0;
	while (c>33)
	{
	    a=(a<<3)+(a<<1)+c-'0';
	    c=getchar_unlocked();
	}
}
bool f=false;
int power(int a,int b)
{
	if(b==0)
		return 1;
	long long t=power(a,b/2);
	t=t*t;
	if( t>10000)
		{f=true; t=t%10000;}
	if(b&1)
	{	
		 t=(t*a); 
		if( t>10000)
		{f=true; t=t%10000;}
	}
	
	return t;
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<bool> isprime(LIM,true);
	vector<vector<int> > prime;
	for(int i=2;i<LIM;i++)
	{
		if(isprime[i])
		{
			prime.push_back(vector<int>());
			int m=1;
			while((long long)m*i<LIM)
			{
				m=m*i;
				prime[prime.size()-1].push_back(m);
				
				
			}
			for(int j=i+i;j<LIM;j+=i)
			{
				isprime[j]=false;				
			}
		}
	}
	/*for(int i=0;i<prime.size();i++)
	{
		for(int j=0;j<prime[i].size();j++)
			cout<<prime[i][j]<<" ";
		cout<<endl;
	}		
			*/
	FastInput in;
	int T;
	T=in.ReadNext();
	for(int t=0;t<T;t++)
	{	
		int n=in.ReadNext();
		//cin>>n;
		
		int no_divisors=1;
		//vector<int> degree(prime.size(),0);
		for(int i=n,j=0;i>1;j++)
		{
			int k=prime[j].size()-1;
			if(prime[j][0]*prime[j][0]>i)
			{
				no_divisors*=2;
				break;
			}
			while(k>=0 && i%prime[j][k]!=0)
			{
				k--;
			}
			if(k>=0)
				i=i/prime[j][k];
			//degree[i]=d;
			//cout<<p<<" "<<d<<"\n";
			no_divisors*=(k+2);
		}
		
		
		int res=0;
//		if(n>10000)
//		{	n=n%10000; f=true;}
//		else	
		f=false;
		if(no_divisors%2==0)
			res=power(n,(no_divisors-2)/2);
		else
			res=power(sqrt(n),no_divisors-2);
		if(f)
			cout<<setfill('0')<< setw(4)<<res<<"\n";
		else
			cout<<res<<"\n";					
	}
	return 0;
}
