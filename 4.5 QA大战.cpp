#include<stdio.h>
#include<string.h>
  
int head[2005]={0};//军队的最后一个士兵位置 
int edge[100005];//记录输入的队列 
int pre[100005];//记录士兵的下一个士兵位置 
int tail[2005];//记录军队第一个士兵位置 
int a,b,k,en,dn;
char s[10];
int u[2005]={0};//u[n]判断是否存在军队n
int ord[2005];//ord[]记录军队的先后顺序 

void add(int x,int y)//x军队里加入y士兵 
{
    edge[en]=y;
    if(head[x]==0) tail[x]=en;
    pre[head[x]]=en;
    head[x]=en;
    en++;
}
  
void output(int x)
{
    if(k) putchar(' ');
    else k=1;
    printf("%d",x);
}
  
int main()
{
    dn=0;//记录军队数目 
    en=1;//记录士兵人数 
    while(scanf("%s",s), s[0]!='E')
    {
       scanf("%d%d",&a,&b);
       if(!u[b])
       {
           u[b]=1;
           ord[dn]=b;
		   dn++;
       }
       add(b, a);
    }
    k=0;
    for(int i=0;i<dn;i++)
    {
    	int j;
    	j=tail[ord[i]];
    	output(edge[j]);
    	while (j!=head[ord[i]])
    	{
    		j=pre[j];
			output(edge[j]);
		}
    }
    return 0;
}
