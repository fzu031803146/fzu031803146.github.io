# include <iostream>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	int r1=0,r2=0;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		int a,b;
		a=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		b=(x-x2)*(x-x2)+(y-y2)*(y-y2);
		if ((a>r1)&&(b>r2))
		if (a>b)
		{
			if (r2<b) r2=b;
		}
		else
		{
			if (r1<a) r1=a;
		}
	}
	cout<<(r1+r2);
	return 0;
 } 
