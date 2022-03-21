#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct node
{
	int day;
	string name,change;
}log[101];
bool cmp(node a,node b)
{
	return a.day<b.day;
}
int main()
{
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>log[i].day>>log[i].name>>log[i].change;
	stable_sort(log+1,log+1+n,cmp);
	int bessie=7,elsie=7,mildred=7;
	int bstatus=1,estatus=1,mstatus=1;
	int maxx=7;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		int t=0;
		if(log[i].change.find('+')!=string::npos)
		{
			int p=log[i].change.find('+')+1;
			while(p<log[i].change.size())
				t=t*10+log[i].change[p++]-'0';
		}
		else
		{
			int p=log[i].change.find('-')+1;
			while(p<log[i].change.size())
				t=t*10+log[i].change[p++]-'0';
			t=-t;
		}
		if(log[i].name=="Bessie")
			bessie+=t;
		else if(log[i].name=="Elsie")
			elsie+=t;
		else
			mildred+=t;
		maxx=max(bessie,max(elsie,mildred));
		int change=0;
		if(bessie==maxx&&bstatus==0)
		{
			bstatus=1;
			change=1;
		}
		else if(bessie!=maxx&&bstatus==1)
		{
			bstatus=0;
			change=1;
		}
		if(elsie==maxx&&estatus==0)
		{
			estatus=1;
			change=1;
		}
		else if(elsie!=maxx&&estatus==1)
		{
			estatus=0;
			change=1;
		}
		if(mildred==maxx&&mstatus==0)
		{
			mstatus=1;
			change=1;
		}
		else if(mildred!=maxx&&mstatus==1)
		{
			mstatus=0;
			change=1;
		}
		if(change==1)
			ans++;
	}
	cout<<ans;
	return 0;
}