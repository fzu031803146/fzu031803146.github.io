# include <iostream>
# include <stdlib.h>
using namespace std;
const int x[4]={0,0,1,-1};
const int y[4]={1,-1,0,0};
int r,c,ent,exi,n;
int p=0;
int a[40005][2]={{0}},d[40005]={0};//a[]记录位置，b[]记录第几步 
int b[205][205]={{0}};//b[][]记录是否走过当前位置
int g[205][205],k[205][205]; 

void l(int nn)
{
	if (nn>n) 
	{
		if (p==0) cout<<"No Way";
		exit(0);
	}
	else
	if ((a[nn][0]==r-1)&&(a[nn][1]==exi))
	{
		cout<<(d[nn]+1);
		p=1;
		exit(0);
	}
	else
	{
		for (int i=0;i<4;i++)
		if ((a[nn][0]+x[i]>-1)&&(a[nn][0]+x[i]<r)
		  &&(a[nn][1]+y[i]>-1)&&(a[nn][1]+y[i]<c)
		  &&(b[a[nn][0]+x[i]][a[nn][1]+y[i]]==0))
		{
			if (((i==0)&&(g[a[nn][0]][a[nn][1]]==0))
			  ||((i==1)&&(g[a[nn][0]+x[i]][a[nn][1]+y[i]]==0))
			  ||((i==2)&&(k[a[nn][0]][a[nn][1]]==0))
			  ||((i==3)&&(k[a[nn][0]+x[i]][a[nn][1]+y[i]]==0)))
			  {
			  	n++;
			  	d[n]=d[nn]+1;
			  	a[n][0]=a[nn][0]+x[i];
			  	a[n][1]=a[nn][1]+y[i];
			  	b[a[n][0]][a[n][1]]=1;
			  }
		}
		l(nn+1);
	}
 } 

int main()
{
	cin>>r>>c>>ent>>exi;
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c-1;j++)
		cin>>g[i][j];
		if (i!=r-1) 
		for (int j=0;j<c;j++)
		cin>>k[i][j];
	 } 
	n=1;
	a[1][0]=0;
	a[1][1]=ent;
	d[1]=1;
	b[a[n][0]][a[n][1]]=1;
	l(1);
	return 0;
}
