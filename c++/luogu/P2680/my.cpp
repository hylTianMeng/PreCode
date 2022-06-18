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
#define N 300010
#define M number
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

typedef pair<P,int> PP;

int n,m,f[N][21],v[N][21],s[N][21],dep[N],maxv;
PP a[N];

inline void dfs(int k,int fa){
    f[k][0]=fa;rep(i,1,20) f[k][i]=f[f[k][i-1]][i-1];
    rep(i,1,20) v[k][i]=max(v[k][i-1],v[f[k][i-1]][i-1]);
    rep(i,1,20) s[k][i]=s[k][i-1]+s[f[k][i-1]][i-1];
    dep[k]=dep[fa]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(to==fa) continue;
        v[to][0]=w;s[to][0]=w;
        dfs(to,k);
    }
}

inline PP ge(int a,int b){
    int lca=-1,maxx=-INF,sum=0;
    if(dep[a]<dep[b])swap(a,b);
    dec(i,0,20) if(dep[f[a][i]]>=dep[b]){
        sum+=s[a][i];maxx=max(maxx,v[a][i]);a=f[a][i];
    }
    if(a==b) return mp(mp(sum,maxx),a);
    dec(i,0,20) if(f[a][i]!=f[b][i]){
        sum+=s[a][i]+s[b][i];maxx=max(max(v[b][i],v[a][i]),maxx);
        a=f[a][i];b=f[b][i];
    }
    sum+=s[a][0];sum+=s[b][0];maxx=max(maxx,max(v[b][0],v[a][0]));
    lca=f[a][0];
    return mp(mp(sum,maxx),lca);
}

inline bool cmp(int a,int b){
    return dep[a]>dep[b];
}

inline bool check(int mid){
    int b[5];
    int l=-1,r=-2;
    rep(i,1,m){
        if(a[i].se<=mid) continue;
        if(l==-1){
            l=a[i].fi.fi;r=a[i].fi.se;
        }
        else{
            int nl=a[i].fi.fi,nr=a[i].fi.se;
            b[0]=ge(nl,l).se;b[1]=ge(nl,r).se;
            b[2]=ge(nr,l).se;b[3]=ge(nr,r).se;
            sort(b,b+4,cmp);
            l=b[0];r=b[1];
        }
        if(l==r) return 0;
    }
    if(l==-1) return 1;
    int maxx=ge(l,r).fi.se;
    return maxv-maxx<=mid;
}

inline void Solve(){
    int l=0,r=3e8;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n-1){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
    dfs(1,0);
    rep(i,1,m){
        read(a[i].fi.fi);read(a[i].fi.se);
        PP now=ge(a[i].fi.fi,a[i].fi.se);
        // printf("%d %d %d\n",now.fi.fi,now.fi.se,now.se);
        a[i].se=now.fi.fi;
        maxv=max(maxv,a[i].se);
    }
    // printf("maxv=%d\n",maxv);
    Solve();
    return 0;
}