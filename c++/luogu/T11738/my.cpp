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
#define N 10000010
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int siz[N],top[N],son[N],dep[N],fa[N],id[N],lx[N],rx[N],tot;
vi e[N];
int s[N],q[N],qt;

inline void dfs1(int k,int f){
    dep[k]=dep[f]+1;fa[k]=f;siz[k]=1;
    for(int to:e[k]){
        if(to==f) continue;
        dfs1(to,k);siz[k]+=siz[to];
        if(siz[son[k]]<siz[to]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    top[k]=t;id[k]=++tot;lx[k]=tot;
    if(son[k])dfs2(son[k],t);
    for(int to:e[k]){
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
    rx[k]=tot;
}

int n,m;

inline void add(int a,int b){
    // printf("a=%d b=%d\n",a,b);
    q[++qt]=a;q[++qt]=b+1;s[a]++;s[b+1]--;
}

inline void ge(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        add(id[top[a]],id[a]);a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);
    add(id[b],id[a]);
}

inline void Solve(){
    int a,b,t;read(a);read(b);read(t);
    rep(i,1,a){
        int u,v;read(u);read(v);
        ge(u,v);
    }
    rep(i,1,b){
        int u;read(u);
        add(lx[u],rx[u]);
    }
    q[++qt]=n+1;q[++qt]=1;
    sort(q+1,q+qt+1);qt=unique(q+1,q+qt+1)-q-1;
    int sum=0,ans=0;
    rep(i,1,qt-1){
        sum+=s[q[i]];
        if(sum>=t) ans+=(q[i+1]-q[i]);
    }
    printf("%lld\n",ans);
    rep(i,1,qt) s[q[i]]=0;
    qt=0;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    dfs1(1,0);dfs2(1,1);
    rep(i,1,m){
        Solve();
    }
    return 0;
}