# include <iostream>
using namespace std;
int a[10003]={0},c[10003]={0},l[10003]={0},r[10003]={0};

int cc(int t)
{
	int w,e;
	if (l[t]!=0) 
	{
		c[l[t]]=c[t]+1;
		w=cc(l[t]);
	}
	else w=c[t];
	if (r[t]!=0) 
	{
		c[r[t]]=c[t]+1;
		e=cc(r[t]);
	}
	else e=c[t];
	if (w>e) return w;
	else return e;
}
int main()
{
	int n,o,ll,rr;
	bool b=true;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>ll>>o>>rr;
		if (ll!=-1)
		{
			if (ll<o) 
			{
				a[ll]=o;
				l[o]=ll;
			}
			else b=false;
		}
		if (rr!=-1)
		{
			if (rr>o) 
			{
				a[rr]=o;
				r[o]=rr;
			}
			else b=false;
		}
	}
	if (not b) cout<<"-1";
	else
	{
		int k;
		for (int i=1;i<=n;i++) 
		if (a[i]==0) 
		{
			k=i;
			break;
		}
		c[k]=1;
		int p=cc(k);
		cout<<p;
	}
	return 0;
 } 
