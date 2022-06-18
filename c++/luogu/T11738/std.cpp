#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=10000010;
struct poi{int too,pre;}e[maxn<<1];
int n,m,x,y,z,tot,cnt,ans,a,b,t,cntt;
int last[maxn],size[maxn],fa[maxn],dep[maxn],son[maxn],w[maxn],top[maxn],mx[maxn],q[maxn],s[maxn];
inline void read(int &k)
{
    int f=1;k=0;char c=getchar();
    while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
    while(c<='9'&&c>='0')k=k*10+c-'0',c=getchar();
    k*=f;
}
inline void add(int x,int y){e[++tot].too=y;e[tot].pre=last[x];last[x]=tot;}
inline void update(int x,int y){q[++cntt]=x;q[++cntt]=y+1;s[x]++;s[y+1]--;}
void dfs1(int x)
{
    size[x]=1;
    for(int i=last[x];i;i=e[i].pre)
    {
        int too=e[i].too;
        if(too==fa[x])continue;
        fa[too]=x;
        dep[too]=dep[x]+1;
        dfs1(too);
        if(size[too]>size[son[x]])son[x]=too;
        size[x]+=size[too];
    }
}
void dfs2(int x,int tp)
{
    mx[x]=w[x]=++cnt;top[x]=tp;
    if(son[x])dfs2(son[x],tp),mx[x]=max(mx[x],mx[son[x]]);
    for(int i=last[x];i;i=e[i].pre)
    if(e[i].too!=son[x]&&e[i].too!=fa[x])
    dfs2(e[i].too,e[i].too),mx[x]=max(mx[x],mx[e[i].too]);
}
inline void work(int x,int y)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(x,y),swap(f1,f2);
        update(w[f1],w[x]);
        x=fa[f1];f1=top[x];
    }
    if(dep[x]<dep[y])swap(x,y);
    update(w[y],w[x]);
}
int main()
{
    read(n);read(m);
    for(int i=1;i<n;i++)read(x),read(y),add(x,y),add(y,x);
    dfs1(1);dfs2(1,1);
    for(int i=1;i<=m;i++)
    {
        read(a);read(b);read(t);cntt=0;
        for(int i=1;i<=a;i++)read(x),read(y),work(x,y);
        for(int i=1;i<=b;i++)read(x),update(w[x],mx[x]);
        q[++cntt]=n+1;q[++cntt]=1;sort(q+1,q+1+cntt);
        cntt=unique(q+1,q+1+cntt)-q-1;
        int sum=0,now=1,ans=0;
        for(int i=1;i<cntt;i++)
        {
            sum+=s[q[i]];
            if(sum>=t)ans+=q[i+1]-q[i];
        }
        for(int i=1;i<=cntt;i++)s[q[i]]=0;
        printf("%d\n",ans);
    }
    return 0;
}