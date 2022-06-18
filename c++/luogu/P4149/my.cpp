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
#define Next(k) for(int x=head[k];x;x=li[x].next)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 400010
#define M 1000100
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
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

bool vis[N];
int root,siz[N],n,m,c[M],as,d[N],cn[M],ans=INF;
ll dep[N];

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

inline void ges(int k,int fa){
    siz[k]=1;
    Next(k){
        int to=li[x].to;if(to==fa||vis[to]) continue;
        ges(to,k);siz[k]+=siz[to];
    }
}

inline void geg(int k,int fa){
    bool op=((as-siz[k])<=as/2);
    Next(k){
        int to=li[x].to;if(to==fa||vis[to]) continue;
        op&=(siz[to]<=as/2);
    }
    if(op){root=k;return;}
    Next(k){int to=li[x].to;if(to==fa||vis[to]) continue;geg(to,k);}
}

inline void ged(int k,int fa){
    Next(k){
        int to=li[x].to;if(to==fa||vis[to]) continue;
        dep[to]=dep[k]+li[x].w;d[to]=d[k]+1;ged(to,k);
    }
}

inline void Init(int k){
    ges(k,0);as=siz[k];geg(k,0);vis[root]=1;ged(root,0);ges(root,0);
}

inline void add(int k,int fa){
    if(dep[k]>m) return;
    cmin(cn[dep[k]],d[k]);
    ans=min(ans,c[m-dep[k]]+cn[dep[k]]);
    Next(k){
        int to=li[x].to;if(to==fa||vis[to]) continue;
        add(to,k);
    }
    // cmin(c[dep[k]],d[k]);
}

inline void dm(int k,int fa){
    if(dep[k]>m) return;
    cmin(c[dep[k]],cn[dep[k]]);
    Next(k){
        int to=li[x].to;if(to==fa||vis[to]) continue;
        dm(to,k);
    }
}

template<typename T> inline void dc(T *f,int k,int fa,int val){
    f[k]=val;Next(k){int to=li[x].to;if(to==fa||vis[to]) continue;dc(f,to,k,val);}
}

inline void dc2(int *f,int k,int fa){
    if(dep[k]>m) return;
    f[dep[k]]=INF;
    Next(k){int to=li[x].to;if(to==fa||vis[to]) continue;dc2(f,to,k);}
}

inline void Clear(int k,int fa){
    dc2(c,k,fa);as=-1;dc(dep,k,fa,0);dc(d,k,fa,0);c[0]=0;
}

inline void dfs(int k,int fa){
    Init(k);
    Next(root){
        int to=li[x].to;if(to==root||vis[to]) continue;
        add(to,root);
        dm(to,root);dc2(cn,to,root);
    }
    Clear(root,0);
    for(int x=head[root];x;x=li[x].next){
        int to=li[x].to;
        if(to==root||vis[to]) continue;
        dfs(to,root);
    }
}

int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);
    rep(i,1,n-1){
        int from,to,w;read(from);read(to);read(w);from++;to++;
        Add(from,to,w);Add(to,from,w);
    }
    mset(c,INF);mset(cn,INF);c[0]=0;
    dfs(1,0);
    if(ans!=INF)printf("%d\n",ans);else puts("-1");
    return 0;
}