# include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct ufset *UFset;
typedef struct ufset
{
	int *parent;
	int *root;
}UFS;
UFset UFinit(int size)
{
	UFset U=(UFset)malloc(sizeof *U);
	U->parent=(int *)malloc((size+1)*sizeof(int));
	U->root=(int *)malloc((size+1)*sizeof(int));
	for(int e=1;e<=size;e++)
	{
		U->parent[e]=1;
		U->root[e]=1;
	}
	return U;
}
int UFfind(int e,UFset U)
{
	int i,j=e;
	while (!U->root[j]) 
	{
		j=U->parent[j];
	}
	while(j!=e)
	{
		i=U->parent[e];
		U->parent[e]=j;
		e=i;
	}
	return j;
};
int UFunion(int i,int j,UFset U)
{
	if(i==j) return i;
	if(U->parent[i]<U->parent[j])
	{
		U->parent[j]+=U->parent[i];
		U->root[i]=0;
		U->parent[i]=j;
		return j;
	}
	else
	{
		U->parent[i]+=U->parent[j];
		U->root[j]=0;
		U->parent[j]=i;
		return i;
	}
};
void UFfree(UFset U)
{
	free(U->parent);
	free(U->root);
	free(U);
};
int main()
{
	UFset UFS;
	int n;
	cin>>n;
	UFS=UFinit(n);
	char a;
	cin>>a;
	while (a !='S')
	{
		int c1,c2;
		cin>>c1>>c2;
		if (a=='I')
		{
			c1=UFfind(c1,UFS);
			c2=UFfind(c2,UFS);
			UFunion(c1,c2,UFS);
		}
		else
		if (a=='C')
		{
			if (UFfind(c1,UFS)==UFfind(c2,UFS)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		cin>>a;
	}
	int sum=0;
	for (int i=1;i<=n;i++) 
	if (UFS->root[i]==1) sum++;
	if (sum==1) cout<<"The network is connected."<<endl;
	else cout<<"There are "<<sum<<" components."<<endl;
	UFfree(UFS);
	return 0;
}
