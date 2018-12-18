#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long sum = 0;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	for (int i = 0; i < n-1; i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<a[i]<< " "<<a[j]<<" "<<(a[i]&a[j])<<endl;
			sum+=a[i]&a[j];
		}
	}
	cout<<sum;
	delete a;
	return 0;
}
