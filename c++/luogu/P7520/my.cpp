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
#define N 3010
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
int n,m,q,now,x,y,ans,siz[N];
vector<int> v[N];
vi e[N],t[N];
bool vis[N],a[N][N];
inline void dfs(int k){
    vis[k]=1;
    for(int to:e[k]){
        if(vis[to]||to==now) continue;
        dfs(to);
    }
}
inline void dfs2(int id,int k){
    vis[k]=1;a[id][k]=1;for(int to:e[k]) if(!vis[to]) dfs2(id,to);
}
inline void ge(int k,int fa){
    siz[k]=1;for(int to:t[k]) if(to!=fa) ge(to,k),siz[k]+=siz[to];
}
inline void df(int k,int fa){
    for(int to:t[k]){
        if(to==fa) continue;
        if(a[k][x]&&a[y][to]){ans+=siz[to];}
        else df(to,k);
    }
}
int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);read(m);read(q);
    rep(i,1,m){
        int from,to;read(from);read(to);
        e[from].pb(to);
    }
    rep(i,1,n){
        now=i;dfs(1);
        rep(j,1,n){
            if(j==i) continue;
            if(!vis[j]) v[j].pb(i);
            else vis[j]=0;
        }
    }
    rep(i,1,n){
        dfs2(i,i);
        rep(j,1,n) vis[i]=0;
    }
    rep(i,2,n){
        for(int now:v[i]){
            if(v[now].size()==v[i].size()-1) t[now].pb(i),t[i].pb(now);
        }
    }
    ge(1,0);
    rep(i,1,q){
        read(x);read(y);
        df(1,0);printf("%d\n",ans);
    }
    return 0;
}