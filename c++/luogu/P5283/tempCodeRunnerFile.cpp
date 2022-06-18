#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=500010;
typedef long long ll;
#define int long long
int n,k,cnt=1;
ll a[maxn],ans;
struct Trie
{
    int ch[2],cnt;
}st[maxn*34];
void insert(ll v)
{
    int nww=1;st[nww].cnt++;
    for(ll i=33;i>=0;i--)
    {
        ll t=(v>>i)&1ll;
        if(!st[nww].ch[t])st[nww].ch[t]=++cnt;
        nww=st[nww].ch[t];st[nww].cnt++;
    }
}
ll query(ll v,int k)
{
    int nww=1;
    ll ans=0;
    for(ll i=33;i>=0;i--)
    {
        ll t=(v>>i)&1ll;
        if(st[st[nww].ch[t]].cnt>=k)nww=st[nww].ch[t];
        else k-=st[st[nww].ch[t]].cnt,nww=st[nww].ch[t^1],ans|=(1ll<<i);
    }
    return ans;
}
struct node
{
    int id,rnk;ll v;
    bool operator<(node x)const{return v<x.v;}
};
priority_queue<node>q;
signed main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%lld%lld",&n,&k);k*=2;
    insert(0);for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]^=a[i-1],insert(a[i]);
    for(int i=0;i<=n;i++)q.push((node){i,n+1,query(a[i],n+1)});
    while(k--)
    {
        node x=q.top();q.pop();
        ans+=x.v;
        if(x.rnk)q.push((node){x.id,x.rnk-1,query(a[x.id],x.rnk-1)});
    }
    printf("%lld\n",ans/2ll);
    return 0;
}