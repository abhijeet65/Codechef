#include<iostream>
using namespace std;
int main()
{
	//int T;
	//cin>>T;
	//for(int i=0;i<T;i++)
	{
		long long n;
		cin>>n;
		int l=n%6;
		if(l==0 || l==1||l==3)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}