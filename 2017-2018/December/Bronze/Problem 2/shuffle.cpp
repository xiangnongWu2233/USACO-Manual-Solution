#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[101];
string id[101];
int main()
{
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>id[i];
	for(i=1;i<=3;i++)
	{
		string t[101];
		for(j=1;j<=n;j++)
			t[j]=id[a[j]];
		for(j=1;j<=n;j++)
			id[j]=t[j];
	}
	for(i=1;i<=n;i++)
		cout<<id[i]<<endl;
	return 0;
}