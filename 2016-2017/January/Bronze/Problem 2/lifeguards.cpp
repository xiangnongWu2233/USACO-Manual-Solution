#include <iostream>
#include <cstdio>
using namespace std;
int spoints[101],epoints[101];
bool b[1001];
int calc(int id,int n)
{
	int i,j;
	for(i=0;i<=1000;i++)
		b[i]=0;
	for(i=1;i<=n;i++)
	{
		if(i==id)continue;
		for(j=spoints[i];j<epoints[i];j++)
			b[j]=1;
	}
	int cnt=0;
	for(i=0;i<=1000;i++)
		cnt+=b[i];
	return cnt;
}
int main()
{
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	int n,i,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>spoints[i]>>epoints[i];
	for(i=1;i<=n;i++)
		ans=max(ans,calc(i,n));
	cout<<ans;
	return 0;
}