# include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	string s[n];
	for (int i=0;i<n;i++) cin>>s[i];
	cin>>m;
	for (int i=0;i<m;i++)
	{
		string a;
		cin>>a;
		int sum=0;
		for (int j=0;j<n;j++)
		{
			bool b=true;
			int k=0;
			while (a[k]!='\0')
			{
				if (a[k]==s[j][k]) k++;
				else
				{
					b=false;
					break;
				}
			}
			if (b) sum++; 
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
