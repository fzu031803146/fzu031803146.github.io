//´íÎó 
# include <iostream>
using namespace std;
	int f[100000005]={0}; 
	int N,A,B;
int fibonacci (int n)
{
	if (f[n]>0) return f[n];
	else
	f[n]=(A*fibonacci(n-1)+B*fibonacci(n-2))%2013; 
	return f[n];
}
int main()
{
	f[0]=f[1]=1;
	cin>>N>>A>>B;
	for (int j=1;j<=N;j++)
	{
		int a;
		cin>>a;
		cout<<fibonacci(a)<<endl;
	}
	return 0;
}

