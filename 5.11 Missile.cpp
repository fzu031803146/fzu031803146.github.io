# include <iostream>
using namespace std;
	int a[100002]={0},b[100002]={0};
void q(int l,int r)
{
	int i=l,j=r;
	int kk=a[(l+r)/2];
	do
	{
		while (a[i]<kk) i++;
		while (a[j]>kk) j--;
		if (i<=j)
		{
			int o;
			o=a[i];
			a[i]=a[j];
			a[j]=o;
			o=b[i];
			b[i]=b[j];
			b[j]=o;
			i++;
			j--;
		} 
	}while (i<=j);
	if (i<r) q(i,r);
	if (l<j) q(l,j);
}
int main()
{
	int x1,y1,x2,y2;
	int r1=0,r2=0;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i]=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		b[i]=(x-x2)*(x-x2)+(y-y2)*(y-y2);
	}
	q(1,n);
	r1=a[n];
	a[0]=0;
	int k=r2;
	for (int i=n;i>=0;i--)
	{
		if (b[i]>k) k=b[i];
		if ((r1+r2)>(a[i-1]+k))
		{
			r1=a[i-1];
			r2=k;
		}
	}
	cout<<(r1+r2);
	return 0;
 } 
