#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100001];
int main()
{
	int n,l,i;
	cin>>n>>l;
	for(i=1;i<=n;i++)
		cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(i=n;i>=1&&a[i]>=(n-i+1);i--)
	int t=i;
	for(i=n;i>=t;i--)
	{
		
	}
	cout<<ans;
	return 0;
}