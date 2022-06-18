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
#define N 100010
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

int n,m,mod,siz[N],tot,cnt;
vi e[N];
bool vis[N];

inline void dfs(int k){
    vis[k]=1;cnt++;
    for(int to:e[k]){
        if(vis[to]) continue;dfs(to);
    }
}

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(mod);
    rep(i,1,m){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    rep(i,1,n){
        if(vis[i]) continue;
        cnt=0;dfs(i);siz[++tot]=cnt;
    }
    if(tot==1){
        printf("%d\n",1%mod);return 0;
    }
    int ans=ksm(n,tot-2,mod);
    rep(i,1,tot) ans=mul(ans,siz[i]);
    printf("%d\n",ans);
    return 0;
}