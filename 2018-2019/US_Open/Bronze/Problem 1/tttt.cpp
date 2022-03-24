#include <iostream>
#include <cstdio>
using namespace std;
char map[4][4]; 
bool b[26]={0};
int main()
{
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);
	int k,t,i,j,ans=0;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			cin>>map[i][j];
	for(k=0;k<26;k++)
	{
		int sol=0;
		for(i=1;i<=3;i++)
		{
			if(map[1][i]==map[2][i]&&map[2][i]==map[3][i]&&map[3][i]==char(k+'A')) {sol=1;break;}
			else if(map[i][1]==map[i][2]&&map[i][2]==map[i][3]&&map[i][3]==char(k+'A')) {sol=1;break;}
		}
		if(map[1][1]==map[2][2]&&map[2][2]==map[3][3]&&map[3][3]==char(k+'A'))
			sol=1;
		else if(map[1][3]==map[2][2]&&map[2][2]==map[3][1]&&map[3][1]==char(k+'A'))
			sol=1;
		if(sol==1)
			ans++;
	}
	cout<<ans<<endl;
	ans=0;
	for(k=0;k<26;k++)
	{
		b[k]=1;
		for(t=k+1;t<26;t++)
		{
			b[t]=1;
			int sol=0;
			for(i=1;i<=3;i++)
			{
				if(b[map[i][1]-'A']&&b[map[i][2]-'A']&&b[map[i][3]-'A']&&(map[i][1]!=map[i][2]||map[i][2]!=map[i][3])) {sol=1;break;}
				else if(b[map[1][i]-'A']&&b[map[2][i]-'A']&&b[map[3][i]-'A']&&((map[1][i]!=map[2][i])||(map[2][i]!=map[3][i]))) {sol=1;break;}
			}
			if(b[map[1][1]-'A']&&b[map[2][2]-'A']&&b[map[3][3]-'A']&&(map[1][1]!=map[2][2]||map[2][2]!=map[3][3])) sol=1;
			else if(b[map[1][3]-'A']&&b[map[2][2]-'A']&&b[map[3][1]-'A']&&((map[1][3]!=map[2][2])||(map[2][2]!=map[3][1]))) sol=1;
			if(sol==1)
				ans++;	
			b[t]=0;
		}
		b[k]=0;
	}
	cout<<ans;
	return 0;
}