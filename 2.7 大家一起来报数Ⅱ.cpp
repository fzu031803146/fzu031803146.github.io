# include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for (int k=0;k<T;k++)
	{
		int n,m;
		cin>>n>>m;
		int a[1005],b[1005];
		for (int i=1;i<=n;i++) 
		{
			a[i]=i+1;
			b[i]=i-1;
		}
		a[n]=1;
		b[1]=n;
		a[0]=1;
		int o;
		if (n>=3) o=0;else o=1;
		while (n>=3)
		{
			int u=0;
			while (u<m)
			{
				u++;
				o=a[o];
			 } 
			 n=n-2;
			 b[a[a[o]]]=o;
			 a[o]=a[a[o]];
			 a[b[b[o]]]=o;
			 b[o]=b[b[o]];
		}
		int p,q;
		p=o;
		if (n==1) cout<<p<<endl;
		if (n==2) 
		{
			q=a[o];
			if (q<p) cout<<q<<' '<<p<<endl;
			else cout<<p<<' '<<q<<endl;
		}
	}
	return 0;
 } 
