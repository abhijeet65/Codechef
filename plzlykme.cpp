#include<iostream>
#include<string>
#include<cstring>
using namespace std;
double power(long base,long p)
{ double tmp;
if(p==0)
return 1;
tmp=power(base,p/2);
if(p%2==0)
{
return tmp*tmp;
}
else
{
return tmp*tmp*base;
}
 
}
int main()
{
int t;
cin>>t;
long l,d,s,c;double sum;
for(int i=0;i<t;i++)
{
cin>>l>>d>>s>>c;
sum=s*power(c+1,d-1);
if(sum>=l)
{cout<<"ALIVE AND KICKING"<<endl;}
else
{cout<<"DEAD AND ROTTING"<<endl; }
}
 
return 0;
 
}