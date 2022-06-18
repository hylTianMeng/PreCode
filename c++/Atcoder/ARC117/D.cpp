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
#define N 200010
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

int dep[N],high[N],son[N],a[N],tot;
int ad,ai;

int n;
vi e[N];

inline void dfs1(int k,int fa){
    dep[k]=dep[fa]+1;
    if(ad<dep[k]){ad=dep[k];ai=k;}
    for(int to:e[k]){
        if(to==fa) continue;
        dfs1(to,k);
    }
}

inline void dfs(int k,int fa){
    dep[k]=dep[fa]+1;
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);
        cmax(high[k],high[to]+1);
        if(high[to]>high[son[k]]) son[k]=to;
    }
}

inline bool cmp(int a,int b){
    return high[a]<high[b];
}

inline void dfs2(int k,int fa){
    a[k]=++tot;
    // printf("a[%d]=%d\n",k,a[k]);
    vi v;v.clear();
    for(int to:e[k]){
        if(to==fa) continue;
        // printf("to=%d\n",to);
        v.pb(to);
    }
    sort(v.begin(),v.end(),cmp);
    for(int to:v){
        // printf("to=%d\n",to);
        dfs2(to,k);
    }
    ++tot;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    dfs1(1,0);dfs(ai,0);dfs2(ai,0);
    rep(i,1,n) printf("%d ",a[i]);
    return 0;
}