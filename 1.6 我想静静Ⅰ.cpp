# include <iostream>
using namespace std;
int main()
{
	int n,t=0;
	int a[150005];
	cin>>n;
	for (int k=0;k<n;k++)
	{
		cin>>a[t];
		if (t>0)
		{
		for (int i=0;i<t;i++)
		if (a[t]==a[i]) 
		{
			a[i]=-1;
			a[t]=-1;
			t=t-1;
			break;
		}
		t++;
		}else t++;
	}
	for (int i=0;i<t;i++)
	if (a[i]!=-1) 
	{
		cout<<a[i];
		break;
	}
	return 0;
}
