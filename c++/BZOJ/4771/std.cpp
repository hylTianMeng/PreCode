#include<bits/stdc++.h>
using namespace std;
const int RLEN=1<<20|1;
inline char gc(){
    static char ibuf[RLEN],*ib,*ob;
    (ob==ib)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ob==ib)?EOF:*ib++;
}
#define gc getchar
inline int read(){
    char ch=gc();
    int res=0,f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
#define ll long long
#define re register
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define cs const
const int mod=1e9+7;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline void Add(int &a,int b){a=add(a,b);}
inline int dec(int a,int b){return a>=b?a-b:a-b+mod;}
inline void Dec(int &a,int b){a=dec(a,b);}
inline int mul(int a,int b){return 1ll*a*b>=mod?1ll*a*b%mod:a*b;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,a=mul(a,a))(b&1)?(res=mul(res,a)):0;return res;}
inline void chemx(int &a,int b){a<b?a=b:0;}
inline void chemn(int &a,int b){a>b?a=b:0;}
cs int N=100005;
namespace Pt{
    cs int M=N*100;
    int val[M],lc[M],rc[M],tot;
    #define mid ((l+r)>>1)
    inline void copy(int u,int clo){
        lc[u]=lc[clo],rc[u]=rc[clo],val[u]=val[clo];
    }
    inline void insert(int r1,int &u,int l,int r,int p,int k){
        u=++tot;copy(u,r1),val[u]+=k;
        if(l==r)return;
        if(p<=mid)insert(lc[r1],lc[u],l,mid,p,k);
        else insert(rc[r1],rc[u],mid+1,r,p,k);
    }
    inline int query(int u,int l,int r,int st,int des){
        if(!u)return 0;
        if(st<=l&&r<=des)return val[u];
        int res=0;
        if(st<=mid)res+=query(lc[u],l,mid,st,des);
        if(mid<des)res+=query(rc[u],mid+1,r,st,des);
        return res;
    }
    #undef mid
}
int rt[N];
int n,q,c[N];
int fa[N],siz[N],son[N],dep[N],top[N],in[N],out[N],idx[N],dfn;
int tp[N],last,mxdep;
set<int> st[N];
vector<int> e[N];
#define IT set<int>::iterator 
void dfs1(int u){
    siz[u]=1,son[u]=0;
    chemx(mxdep,dep[u]);
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        dep[v]=dep[u]+1;
        dfs1(v),siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void dfs2(int u,int tp){
    in[u]=++dfn,idx[dfn]=u,top[u]=tp;
    if(son[u])dfs2(son[u],tp);
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v==son[u])continue;
        dfs2(v,v);
    }
    out[u]=dfn;
}
inline int Lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]>dep[v]?v:u;
}
inline bool comp(int a,int b){
    return dep[a]<dep[b];
}
int main(){
    int T=read();
    while(T--){
        n=read(),q=read();
        for(int i=1;i<=n;i++)c[i]=read();
        for(int i=2;i<=n;i++)fa[i]=read(),e[fa[i]].pb(i);
        dfs1(1),dfs2(1,1);
        for(int i=1;i<=n;i++)tp[i]=i;
        sort(tp+1,tp+n+1,comp);
        for(int i=1;i<=n;i++){
            int u=tp[i],v=c[u],pre=0,nxt=0;
            Pt::insert(rt[dep[tp[i-1]]],rt[dep[u]],1,n,in[u],1);
            IT it=st[v].lower_bound(in[u]);
            if(it!=st[v].end())nxt=idx[*it];
            if(it!=st[v].begin())it--,pre=idx[*it];
            if(pre)Pt::insert(rt[dep[u]],rt[dep[u]],1,n,in[Lca(pre,u)],-1);
            if(nxt)Pt::insert(rt[dep[u]],rt[dep[u]],1,n,in[Lca(u,nxt)],-1);
            if(pre&&nxt)Pt::insert(rt[dep[u]],rt[dep[u]],1,n,in[Lca(pre,nxt)],1);
            st[v].insert(in[u]);
        }
        while(q--){
            int x=read()^last,d=read()^last;
            cout<<(last=Pt::query(rt[min(dep[x]+d,mxdep)],1,n,in[x],out[x]))<<'\n';
        }
        last=mxdep=dfn=0;
        for(int i=1;i<=n;i++)st[c[i]].clear(),e[i].clear();
        Pt::tot=0,rt[0]=0;
    }
}

