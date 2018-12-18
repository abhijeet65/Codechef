#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int comp(const void* a,const void *b)
{
return (*(const char*)a-*(const char*)b);
 
}
inline int max(int a,int b)
{
return (a>b)?a:b;
}
int lcs( const char *X,const char *Y, int m, int n )
{
int L[m+1][n+1];
int i, j;
/* Following steps build L[m+1][n+1] in bottom up fashion. Note
that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (i=0; i<=m; i++)
{
for (j=0; j<=n; j++)
{
if (i == 0 || j == 0)
L[i][j] = 0;
else if (X[i-1] == Y[j-1])
L[i][j] = L[i-1][j-1] + 1;
else
L[i][j] = max(L[i-1][j], L[i][j-1]);
}
}
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
}
int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
//char *a=new char[10001];
//char *b=new char[10001];
//fgets(a,10001,stdin);
//fgets(a,10001,stdin);
string a,b;
cin>>a>>b;
const char* p=a.c_str();
const char *q=b.c_str();
qsort(( void*)a.c_str(),a.size(),sizeof(char),comp);
qsort(( void*)b.c_str(),b.size(),sizeof(char),comp);
int c=0;
while(*p&&*q)
{
if(*p==*q)
{c++; p++;q++;}
else if(*p<*q)
p++;
else
q++;
 
 
}
cout<<c<<"\n";
 
 
 
}
 
return 0;
}