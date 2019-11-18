#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef struct Node
{
    string key;
    int num;
}Node;
bool cmp(Node a, Node b)
{
    if(a.num==b.num)
        return a.key<b.key;
    return a.num>b.num;
}
Node a[100010];
typedef Node *NodePtr;
map<string,int>mp;
set<string>ans,cur;
void solve()
{
    int cnt=0,max_v,key_num=0;
    for(set<string>::iterator it=ans.begin();it!=ans.end();++it)
    {
        a[key_num].key=*it;
        a[key_num].num=mp[*it];
        key_num++;
    }
    sort(a,a+key_num,cmp);
    max_v=a[0].num;
    for(int i=0;i<key_num;++i)
    {
        if(max_v==a[i].num)
            cnt++;
        else break;
    }
    a[0].key[0]='A'+a[0].key[0]-'a';
    cout<<a[0].key<<endl;
    printf("%d\n",a[0].num);
    if(cnt-1!=0)
    printf("And %d more ...",cnt-1);
 
}
int main()
{
    set<string>::iterator it;
    int n,len;
    char input[150];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cur.clear();
        int p=0,num=0;
        int pos[150];
        char processed[150];
        if(i==1)
          getchar();
        gets(input);
        len = strlen(input);
        for(int j=0;j<len;++j)
        {
            if(input[j]=='#'||isalnum(input[j]))
            {
                if(input[j]=='#')
                    pos[num++]=p;
                if(input[j]>='A'&&input[j]<='Z')
                    input[j]='a'+input[j]-'A';
                processed[p++]=input[j];
            }
            else
                processed[p++]=' ';
        }
        processed[p]='\0';
        char key[num/2+1][140];
        for(int j,k=j=0;j<num/2;++j,k+=2)
        {
            int flag=0;
            len=0;
            for(int d=pos[k]+1;d<pos[k+1];d++)
            {
                if(processed[d]!= ' ')
                {
                 key[j][len++]=processed[d];
                 flag=1;
                }
                else
                {
                    if(flag==1)
                    {
                      key[j][len++]=' ';
                    }
                    flag=0;
                }
 
            }
            if(key[j][len-1]==' ')
                len--;
            key[j][len]='\0';
        }
        for(int j=0;j<num/2;++j)
        {
            if(key[j][0]!='\0')
                cur.insert(key[j]);
                ans.insert(key[j]);
        }
        for(it=cur.begin();it!=cur.end();++it)
        {
            mp[*it]++;
        }
    }
    solve();
    return 0;
}
