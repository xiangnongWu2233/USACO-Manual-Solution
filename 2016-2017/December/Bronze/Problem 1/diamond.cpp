#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1001];
int main()
{
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
	int n,k,i,j,ans=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n&&a[j]-a[i]<=k;j++);
		j--;
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}