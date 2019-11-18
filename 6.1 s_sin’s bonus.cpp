# include <iostream>
# include <stdio.h>
using namespace std;
int main()
{
	int n,a,b,v[10005];
	int t[10005]={0};
	bool bb[10005];
	double pi[10005],s[10005];
	cin>>n;
	for (int i=0;i<n;i++) 
	{
		pi[i]=1;
		bb[i]=false;
	}
	for (int i=1;i<n;i++)
	{
		cin>>a>>b;
		double p;		
		cin>>p;
		t[b]=a;
		pi[b]=p;
		bb[a]=true; 
	}
	for (int i=1;i<=n;i++)
	if (t[i]!=0)
	{
		pi[i]=pi[i]*pi[t[i]];
	}
	int k=0;
	for (int i=1;i<=n;i++)
	if (not bb[i]) 
	{
		k++;
		s[k]=pi[i];
	}
	for (int i=1;i<k;i++)
	for (int j=i+1;j<=k;j++)
	if (s[i]>s[j])
	{
		double u;
		u=s[i];
		s[i]=s[j];
		s[j]=u;
	}
	for (int i=1;i<=n;i++) cin>>v[i];
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		if (v[i]>v[j])
		{
			int m;
			m=v[j];
			v[j]=v[i];
			v[i]=m;
		}
	}
	double sum=0;
	for (int i=1;i<=k;i++) 
	{
		sum=sum+s[i]*v[k-i+1];
	}
	
	printf("%.10lf\n",sum);
	return 0;
}
