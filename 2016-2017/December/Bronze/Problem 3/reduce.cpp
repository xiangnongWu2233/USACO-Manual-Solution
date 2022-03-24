#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
	int x,y;
}cows[50001];
priority_queue<int, vector<int>, less<int> > x_max;
priority_queue<int,vector<int>, greater<int> > x_min;
priority_queue<int,vector<int>, less<int> > y_max;
priority_queue<int,vector<int>, greater<int> > y_min;
int main()
{
	freopen("reduce.in","r",stdin);
	freopen("reduce.out","w",stdout);
	int n,i,j,ans=1600000001;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>cows[i].x>>cows[i].y;
		x_max.push(cows[i].x);x_min.push(cows[i].x);
		y_max.push(cows[i].y);y_min.push(cows[i].y);
	}
	for(i=1;i<=n;i++)
	{
		int maxx,minx,maxy,miny;
		if(cows[i].x==x_max.top())
		{
			x_max.pop();
			maxx=x_max.top();
			x_max.push(cows[i].x);
		}
		else
			maxx=x_max.top();
		if(cows[i].x==x_min.top())
		{
			x_min.pop();
			minx=x_min.top();
			x_min.push(cows[i].x);
		}
		else
			minx=x_min.top();
		if(cows[i].y==y_max.top())
		{
			y_max.pop();
			maxy=y_max.top();
			y_max.push(cows[i].y);
		}
		else
			maxy=y_max.top();
		if(cows[i].y==y_min.top())
		{
			y_min.pop();
			miny=y_min.top();
			y_min.push(cows[i].y);
		}
		else
			miny=y_min.top();
		ans=min(ans,(maxx-minx)*(maxy-miny));
	}
	cout<<ans;
	return 0;
}