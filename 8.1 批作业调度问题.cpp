#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int s,t;
    bool operator<(const node&x) const
    {
        if (s==x.s)
        {
            return t>x.t;
        }
        else return s<x.s;
    }
}que[200001];
int array[6000001];
int main()
{
    int n,i;
    int x,y;
    long long ans=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>que[i].s>>que[i].t;
    sort(que,que+n);
    for(i=n-1;i>=0;i--)
    {
        x=que[i].s;
        y=que[i].t;
        while(y)
        {
            x++;
            if(array[x]==0)
            {
                array[x]=1;
                y--;
            }
        }
        ans+=x;
    }
    cout<<ans;
    return 0;   
}
