#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
	int x,y;
}grass[100001];
int ngrass=0;

char map[1002][1002];
bool b[1002][1002];

int n,m;

int Hash(int x,int y)
{
	return x*n+y;
}

int main()
{
	int i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='G')
			{
				ngrass++;
				grass[ngrass].x=i;
				grass[ngrass].y=j;
			}
		}

	for(i=1;i<=ngrass;i++)
	{
		int x=grass[i].x,y=grass[i].y,xx,yy;
		if(map[x+1][y]==map[x][y+1]=='G')
		{
			xx=Hash(x+1,y);
			yy=Hash(x,y+1);
			if(bool[xx,yy]==0)
			{
				ans++;
				bool[xx][yy]=1;
			}
		}
		else if(map[x][y+1]==map[x-1][y]=='G')
		{
			xx=Hash(x,y+1);
			yy=Hash(x-1,y);
			if(bool[xx,yy]==0)
			{
				ans++;
				bool[xx][yy]=1;
			}
		}
		else if(map[x-1][y]==map[x][y-1]=='G')
		{
			xx=Hash(x-1,y);
			yy=Hash(x,y-1);
			if(bool[xx,yy]==0)
			{
				ans++;
				bool[xx][yy]=1;
			}
		}
		else if(map[x][y-1]==map[x+1][y]=='G')
		{
			xx=Hash(x,y-1);
			yy=Hash(x+1,y);
			if(bool[xx,yy]==0)
			{
				ans++;
				bool[xx][yy]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}