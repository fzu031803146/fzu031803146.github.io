#include<stdio.h>
#include<string.h>
  
int head[2005]={0};//���ӵ����һ��ʿ��λ�� 
int edge[100005];//��¼����Ķ��� 
int pre[100005];//��¼ʿ������һ��ʿ��λ�� 
int tail[2005];//��¼���ӵ�һ��ʿ��λ�� 
int a,b,k,en,dn;
char s[10];
int u[2005]={0};//u[n]�ж��Ƿ���ھ���n
int ord[2005];//ord[]��¼���ӵ��Ⱥ�˳�� 

void add(int x,int y)//x���������yʿ�� 
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
    dn=0;//��¼������Ŀ 
    en=1;//��¼ʿ������ 
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
