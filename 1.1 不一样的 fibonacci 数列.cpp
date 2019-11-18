//´íÎó 
# include <iostream>
using namespace std;
	int f[100000005]; 
	int N,A,B;
int fibonacci (int n)
{
	f[0]=f[1]=1;
	for (int i=2;i<=n;i++) f[i]=(A*f[i-1]+B*f[i-2])%2013; 
	return f[n];
}
int main()
{

	cin>>N>>A>>B;
	for (int j=1;j<=N;j++)
	{
		int a;
		cin>>a;
		cout<<fibonacci(a)<<endl;
	}
	return 0;
}

