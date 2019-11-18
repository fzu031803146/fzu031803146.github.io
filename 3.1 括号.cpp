//´íÎó  ((())(()() 

# include <iostream>
# include <cstring>
using namespace std;
int main()
{
	char s[1000005];
	cin.getline(s,1000005);
	int max=0,m=0;
	int number=1;
	int c=0;
	int i=0;
	while (s[i]!='\0')
	{
		if (s[i]=='(')
		{
			c++;
			m++;
		}
		else
		if (s[i]==')')
		{
			c--;
			m++;
			if (c==0)
			{	
				if (m>max) 
				{
					max=m;
					number=1;
				}
				else
				if (m==max) number++;
			}
			else
			if (c>0)
			{
				if (m-c>max)
				{
					max=m-c;
					number=1;
				}
				else
				if (m-c==max) number++; 
			}
			else
			
			if (c<0)
			{
				m=0;
				c=0;
			}
		}
		i++;
	}
    cout<<max<<endl<<number<<endl;
    return 0;
 } 
