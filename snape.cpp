

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int B,LS;
		double minRS,maxRS;
		cin>>B>>LS;
		minRS=sqrt(LS*LS-B*B);
		maxRS=sqrt(LS*LS+B*B);
		cout<<minRS<<" "<<maxRS<<endl;

	}
	return 0;
}
