#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	freopen("lostcow.in","r",stdin);
	freopen("lostcow.out","w",stdout);
	int x,y,i,ans=0;
	cin>>x>>y;
	int step=1,pre=0;
	while(1)
	{
		int move=x+step;
		if((move<=y&&y<=x)||(move>=y&&y>=x))
		{
			ans+=abs(y-x)+abs(pre);
			break;
		}
		else
		{
			ans+=abs(step)+abs(pre);
			pre=step;
		}
		step*=(-2);
	}
	cout<<ans;
	return 0;
}