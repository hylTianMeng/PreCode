#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 500100
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=201314;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int fa[N],dep[N],siz[N],son[N],top[N],n,m,id[N],rk[N],tot;
vi e[N];

inline void dfs1(int k){
    siz[k]=1;dep[k]=dep[fa[k]]+1;
    for(int to:e[k]){
        dfs1(to);siz[k]+=siz[to];
        if(siz[son[k]]<siz[to]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    top[k]=t;id[k]=++tot;rk[tot]=k;
    if(son[k]) dfs2(son[k],t);
    for(int to:e[k]){
        if(to==son[k]) continue;
        dfs2(to,to);
    }
}

int p[N<<2],len[N<<2],tag[N<<2];

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        p[k]=(p[ls(k)]+p[rs(k)])%mod;
        len[k]=len[ls(k)]+len[rs(k)];
    }
    inline void Build(int k,int l,int r){
        if(l==r){len[k]=1;return;}
        int mid=(l+r)>>1;Build(ls(k),l,mid);Build(rs(k),mid+1,r);PushUp(k);
    }
    inline void A(int k,int x){
        (p[k]+=x*len[k])%=mod;(tag[k]+=x)%=mod;
    }
    inline void PushDown(int k){
        if(tag[k]){A(ls(k),tag[k]);A(rs(k),tag[k]);tag[k]=0;}
    }
    inline void Change(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y){A(k,x);return;}
        int mid=(l+r)>>1;PushDown(k);
        if(y<=mid) Change(ls(k),l,mid,z,y,x);
        else if(z>mid) Change(rs(k),mid+1,r,z,y,x);
        else{Change(ls(k),l,mid,z,mid,x);Change(rs(k),mid+1,r,mid+1,y,x);}
        PushUp(k);
    }
    inline int Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;PushDown(k);
        if(y<=mid) return Ask(ls(k),l,mid,z,y);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
        else return Ask(ls(k),l,mid,z,mid)+Ask(rs(k),mid+1,r,mid+1,y);
    }
}tr;

inline void ca(int a,int b,int x){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        tr.Change(1,1,n,id[top[a]],id[a],x);
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);
    tr.Change(1,1,n,id[b],id[a],x);
}

inline int as(int a,int b){
    int ans=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        (ans+=tr.Ask(1,1,n,id[top[a]],id[a]))%=mod;
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);
    (ans+=tr.Ask(1,1,n,id[b],id[a]))%=mod;
    return ans;
}

struct Ques{
    int r,id,sign,x;
}qu[N<<2];

int ta,ans[N];
vi v[N<<1];

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,2,n){
        read(fa[i]);fa[i]++;
        e[fa[i]].pb(i);
    }
    dfs1(1);dfs2(1,1);
    tr.Build(1,1,n);
    rep(i,1,m){
        // printf("i=%d\n",i);
        int l,r,z;read(l);read(r);read(z);l++;r++;z++;
        ++ta;qu[ta].id=i;qu[ta].r=l-1;qu[ta].sign=-1;qu[ta].x=z;
        v[l-1].pb(ta);
        ++ta;qu[ta].id=i;qu[ta].r=r;qu[ta].sign=1;qu[ta].x=z;
        v[r].pb(ta);
    }
    rep(i,1,n){
        // printf("i=%d\n",i);
        ca(i,1,1);
        for(int j:v[i]){
            ans[qu[j].id]+=as(qu[j].x,1)*qu[j].sign;
            // printf("id=%d val=%d\n",qu[j].id,as(qu[j].x,1));
        }
    }
    rep(i,1,m) printf("%lld\n",(ans[i]%mod+mod)%mod);
    return 0;
}