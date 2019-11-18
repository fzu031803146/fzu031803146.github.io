# include <iostream>
using namespace std;
int main()
{
	int n,a[505],c[505];
	int b[505]={0};
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++)
	{
		int k,o=-1;
		for (int j=1;j<=n;j++)
		if (o==a[i]) break;
		else
		 if (b[j]==0) 
		 {
		 	o++;
		 	k=j;
		 }
		 c[i]=k;
		 b[k]=1;
	}
	for (int i=0;i<n;i++) cout<<c[i]<<' ';
	return 0;
}
