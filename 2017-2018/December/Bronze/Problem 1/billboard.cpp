#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int x1,y1,x2,y2;
};
node a,b,t;
int main()
{
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	cin>>b.x1>>b.y1>>b.x2>>b.y2;
	cin>>t.x1>>t.y1>>t.x2>>t.y2;
	int a_area=(a.x2-a.x1)*(a.y2-a.y1),b_area=(b.x2-b.x1)*(b.y2-b.y1);
	int a_t_overlap=0,b_t_overlap=0,a_b_overlap=0,a_b_t_overlap=0;
	int x1=max(a.x1,t.x1),x2=min(a.x2,t.x2);
	int y1=max(a.y1,t.y1),y2=min(a.y2,t.y2);
	if(x1<x2&&y1<y2)
		a_t_overlap=(x2-x1)*(y2-y1);
	x1=max(b.x1,t.x1);x2=min(b.x2,t.x2);
	y1=max(b.y1,t.y1);y2=min(b.y2,t.y2);
	if(x1<x2&&y1<y2)
		b_t_overlap=(x2-x1)*(y2-y1);
	x1=max(a.x1,b.x1);x2=min(a.x2,b.x2);
	y1=max(a.y1,b.y1);y2=min(a.y2,b.y2);
	if(x1<x2&&y1<y2)
		a_b_overlap=(x2-x1)*(y2-y1);
	x1=max(t.x1,max(a.x1,b.x1));x2=min(t.x2,min(a.x2,b.x2));
	y1=max(t.y1,max(a.y1,b.y1));y2=min(t.y2,min(a.y2,b.y2));
	if(x1<x2&&y1<y2)
		a_b_t_overlap=(x2-x1)*(y2-y1);
	cout<<a_area+b_area-a_t_overlap-b_t_overlap-a_b_overlap+2*a_b_t_overlap;
	return 0;
}