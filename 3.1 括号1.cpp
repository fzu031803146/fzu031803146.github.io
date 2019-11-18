//´íÎó 
# include <iostream>
# include <cstring>
using namespace std;
int main()
{
	char s[1000005];
	int a[1000005]={0};
	cin.getline(s,1000005);
	int l=0;
	while (s[l]!='\0')
	{
		if (s[l]==')')
		{
			for (int j=l-1;j>0;j--)
			if ((s[j]=='(')&&(a[j]==0))
			{
				a[j]=1;
				a[l]=1;
				break;
			}
		}
		l++;
	}
	int max=0;
	int number=1;
	int m=0;
	for (int i=0;i<=l;i++)
	{
		if (a[i]==0) 
		{
			if (m>max) 
			{
				max=m;
				number=1;
			}
			else
			if ((m==max)&&(m!=0))
			{
				number++;
			}
			m=0;
		}
		else
		if (a[i]==1)
		{
			m++;
		}
	}
    cout<<max<<endl<<number<<endl;
    return 0;
 } 
