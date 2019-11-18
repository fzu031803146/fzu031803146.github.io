#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	long long total=0;
	scanf("%d",&n);
	int a[n];
	int o;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	for (int j=0;j<(n-i);j++)
	{
		if (a[j]>a[j+1]) 
		{
			total++;
			o=a[j];
			a[j]=a[j+1];
			a[j+1]=o;
		}
	}
	printf("%lld",total);
	return 0;
}
