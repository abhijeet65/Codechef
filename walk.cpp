#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int main()
{
 
int t;
cin>>t;
for(int i=0;i<t;i++)
{
int n;
cin>>n;
int max=INT_MIN;
int pos=-1;
int *a=new int[n];
for(int j=0;j<n;j++)
{
cin>>a[j];
if(a[j]>max)
{
max=a[j];
pos=j;
}
}
int c=max+pos;
int secmax=INT_MIN;
for(int j=pos;j<n;j++)
{
a[j]-=max;
if(a[j]>secmax)
secmax=a[j];
max--;
}
cout<<c+secmax<<endl;
delete [] a;
}
return 0;
} 