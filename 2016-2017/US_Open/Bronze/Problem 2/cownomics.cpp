#include <iostream>
#include <cstdio>
using namespace std;
char spot[101][101];
char plain[101][101];
bool b[26][2];
int main()
{
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);
	int n,m,i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>spot[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>plain[i][j];
	for(i=1;i<=m;i++)
	{
		for(j=0;j<26;j++)
			b[j][0]=b[j][1]=0;
		int sol=1;
		for(j=1;j<=n;j++)
			b[spot[j][i]-'A'][0]=1;
		for(j=1;j<=n;j++)
		{
			if(b[plain[j][i]-'A'][0]==1)
			{
				sol=0;
				break;
			}
			b[plain[j][i]-'A'][1]=1;
		}
		if(sol==1)
			ans++;
	}
	cout<<ans;
	return 0;
}