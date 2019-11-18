# include <iostream>
using namespace std;
int c[50005];
void quicksort(int low,int high)
{
	int i=low,j=high,temp=c[(i+j)/2];
    while(i<j)
	{
		
        while((c[i]<temp)&&(i<high)) i++;
        while((c[j]>temp)&&(j>low)) j--;
        if(i<=j) 
		{
			int o;
			o=c[i];
			c[i]=c[j];
			c[j]=o;
			i++;
			j--;
		}
    }
    if (j>low)  quicksort(low,j);
    if (i<high) quicksort(i,high);
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>c[i];
	quicksort(0,n-1);
	int sum=0;
	int l=1;
	while(l<n)
	{
		l++;
		int k=c[0]+c[1];
		sum=sum+k;
		int t=2;
		for (int i=2;i<n;i++)
		if ((k==0)||(k>c[i])) c[i-t]=c[i];
		else 
		{
			c[i-t]=k;
			k=0;
			t=1;
			c[i-t]=c[i];
		}
	}
	cout<<sum;
	return 0;
}
