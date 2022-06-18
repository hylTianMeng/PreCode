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
#define N 800010
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

int f[N][22],n,m,w[N],dep[N],c[N<<1],ans[N],len[N];
vi e[N],v[N],a[N],b[N];
P s[N];

inline void dfs(int k,int fa){
    f[k][0]=fa;dep[k]=dep[fa]+1;
    for(int i=1;i<=20;i++) f[k][i]=f[f[k][i-1]][i-1];
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);
    }
}

inline int gl(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    dec(i,0,20) if(dep[f[a][i]]>=dep[b]) a=f[a][i];
    if(a==b) return a;
    dec(i,0,20) if(f[a][i]!=f[b][i]){a=f[a][i];b=f[b][i];}
    return f[a][0];
}

inline int gd(int a,int b){
    int lca=gl(a,b);
    return dep[a]+dep[b]-2*dep[lca];
}

inline void dfs1(int k,int fa,int last){
    for(int to:e[k]){
        if(to==fa) continue;
        int now=dep[to]+w[to];
        dfs1(to,k,c[now]);
    }
    for(int to:a[k]){
        c[to]++;
        // printf("Add to=%d\n",to);
    }
    // rep(i,1,n) printf("%d ",c[i]);puts("");
    int now=dep[k]+w[k];
    // printf("c[now]=%d last=%d cha=%d\n",c[now],last,c[now]-last);
    // printf("now=%d\n",now);
    ans[k]+=c[now]-last;
    // if(c[now]-last<0) puts("NOOOOO");
    for(int u:v[k]){
        // printf("u.fi=%d\n",u.fi);
        // printf("u.se=%d\n",u.se);
        // for(int to:a[u.fi]){
            // c[to]--;
            // printf("Del to=%d\n",to);
        // }
        int now=dep[s[u].fi];
        c[now]--;
    }
    // rep(i,1,n) printf("%d ",c[i]);puts("");
}

inline void dfs2(int k,int fa,int last){
    for(int to:e[k]){
        if(to==fa) continue;
        int now=dep[to]-w[to]+n;
        dfs2(to,k,c[now]);
    }
    for(int to:b[k]) c[to]++;
    int now=dep[k]-w[k]+n;
    // printf("c[now]=%d last=%d cha=%d\n",c[now],last,c[now]-last);
    // if(c[now]-last<0) puts("NOOOOO");
    ans[k]+=c[now]-last;
    for(int u:v[k]){
        // for(int to:b[u.se]) c[to]--;
        int now=dep[s[u].se]-len[u]+n;
        c[now]--;
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    dfs(1,0);
    rep(i,1,n) read(w[i]);
    rep(i,1,m){
        int from,to;read(from);read(to);
        s[i].fi=from;s[i].se=to;
        int lca=gl(from,to);
        len[i]=gd(from,to);
        v[lca].pb(i);
        a[from].pb(dep[from]);
        b[to].pb(dep[to]-len[i]+n);
        if(dep[from]==dep[lca]+w[lca]) ans[lca]--;
    }
    dfs1(1,0,0);
    dfs2(1,0,0);
    rep(i,1,n) printf("%lld ",ans[i]);
    return 0;
}