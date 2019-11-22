//ÕýÈ· 
#include<stdio.h> 
  int mod=2013;
 
  void mul(long long a[2][2],long long b[2][2]){
 	long long temp[2][2]={0};
 	for(int i=0;i<2;i++)
 	for(int j=0;j<2;j++)
 	for(int k=0;k<2;k++)
	 temp[i][k]=(a[i][j]*b[j][k]+temp[i][k])%mod; 
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)a[i][j]=temp[i][j];
 	}

int quickPower(int a, int b)
{
    int ans = 1, base = a;
    while(b)
    {
        if(b & 1)
            ans *= base;

        base *= base;
        b >>= 1;
				
    }
    return ans;
}
 int main(){
 	int n,x,y,s;
 	long long b[2][2]={0};
 	scanf("%d%d%d",&s,&x,&y);
 	while(s--){
	b[0][0]=x,b[0][1]=y,b[1][0]=1,b[1][1]=0;
	 	long long ans[2][2]={0};
 			for(int i=0;i<2;i++)ans[i][i]=1;
 		scanf("%d",&n);
 		n--;
 		while(n>0){
 			if(n&1)mul(ans,b);	
			 mul(b,b);
			n>>=1;
		 }
		 printf("%d\n",(ans[0][0]+ans[0][1])%mod);
	 }
 	return 0;
}


