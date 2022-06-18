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
#define N 500010
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

int t;
vi e[N];
int n,m;char s[N];
int ans=0;

int dfn[N],low[N],tot,cnt[N],c[N],dcc;
int sta[N],top;
bool vis[N];

inline void Clear(){
    rep(i,1,n<<1|1) dfn[i]=low[i]=c[i]=sta[i]=cnt[i]=vis[i]=0,e[i].clear();
}

inline void Tarjan(int k){
    dfn[k]=low[k]=++tot;
    sta[++top]=k;vis[k]=1;
    for(int to:e[k]){
        if(!dfn[to]) Tarjan(to),low[k]=min(low[k],low[to]);
        else if(vis[to]) low[k]=min(low[k],dfn[to]);
    }
    if(dfn[k]==low[k]){
        dcc++;cnt[dcc]=0;
        int minn=n+1,x=0;
        while(top){
            int u=sta[top--];
            vis[u]=0;
            c[u]=dcc;
            if(s[u>>1]=='E') minn=min(minn,u>>1);
            else if(x) ans=0;
            else x=(u>>1);
            for(int to:e[u]) cnt[dcc]|=cnt[c[to]];
            if(u==k) break;
        }
        // printf("x=%d\n",x);
        if(x){
            if(x>=minn) ans=0;
            else if(cnt[dcc]) ans=0;
            cnt[dcc]=1;
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(m);
        scanf("%s",s+1);
        tot=0;dcc=0;
        rep(i,1,m){
            // printf("i=%d\n",i);
            int a,b;read(a);read(b);
            a=(a>0)?(a<<1):((-a)<<1|1);b=(b>0)?(b<<1):((-b)<<1|1);
            // printf("a=%d b=%d\n",a,b);
            e[a^1].pb(b);e[b^1].pb(a);
            // puts("here\n");
        }
        ans=1;
        rep(i,2,n<<1|1){ if(!dfn[i]) Tarjan(i);}
        rep(i,1,n){
            if(c[i<<1]==c[i<<1|1])ans=0;
        }
        if(ans) puts("TRUE");
        else puts("FALSE");
        Clear();
    }
}