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
#define N 710
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

int c[N],w[N],a[N][N],n,m;
bool vis[N];
vi e[N],s;

inline void dfs(int k,int id){
    vis[k]=1;
    a[id][c[k]]+=w[k];
    for(int to:e[k]){
        if(vis[to]) continue;
        dfs(to,id);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n) read(c[i]);
    rep(i,1,n) read(w[i]);
    rep(i,1,m){
        int from,to;read(from);read(to);
        e[from].pb(to);
    }
    rep(i,1,n){
        if(c[i]==1){dfs(i,i);s.pb(i);}
        mset(vis,0);
    }
    int ans=0;
    rep(i,2,n){
        for(int j:s){
            ans=max(ans,a[j][i]/w[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}