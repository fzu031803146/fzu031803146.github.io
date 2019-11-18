# include <iostream>
using namespace std;
int main()
{
	int a[100005],b[100005]={0},c[100005];
	int n;
	int k=0;
	cin>>n;
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
		b[i]=a[i];
	}
	if (n>1)
	for (int i=n-2;i>=0;i--)
	{
		if (b[i+1]>b[i]) b[i]=b[i+1];
	}
	int l=0;
	for (int i=0;i<n;i++)
	{
		if(b[i+1]>a[i])
		{
			l++;
			c[l]=a[i];
		}
		else
		if (b[i+1]<a[i])
		{
			if (k==0) 
			{
				cout<<a[i];
				k=1;
			}
			else cout<<' '<<a[i];
			while ((c[l]>b[i+1])&&(l>0))
			{
				cout<<' '<<c[l];
				l--;
			}
		}
	}
    return 0;
 } 
