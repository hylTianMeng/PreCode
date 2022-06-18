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
#define N 200100
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

struct Ques{
    char s[1];int a,b;
}qu[N];

int n,m;

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w,int x){
        for(int i=w;i<=n;i+=lowbit(i)) p[i]+=x;
    }
    inline int Ask(int w){
        int res=0;for(int i=w;i;i-=lowbit(i)) res+=p[i];return res;
    }
}bit;

int l[N],r[N],tot,dep[N],siz[N],f[N];
int fa[N];
vi e[N];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

inline void dfs(int k,int fat){
    l[k]=++tot;dep[k]=dep[fat]+1;
    f[k]=fat;
    for(int to:e[k]){
        if(to==fat) continue;
        dfs(to,k);
    }
    r[k]=tot;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,m){
        scanf("%s",qu[i].s);
        read(qu[i].a);read(qu[i].b);
    }
    rep(i,1,m){
        if(qu[i].s[0]=='A'){
            e[qu[i].a].pb(qu[i].b);
            e[qu[i].b].pb(qu[i].a);
        }
    }
    rep(i,1,n) if(!l[i]) dfs(i,0);
    rep(i,1,n) fa[i]=i,siz[i]=1;
    rep(i,1,m){
        // printf("i=%d\n",i);
        if(qu[i].s[0]=='A'){
            int a=qu[i].a,b=qu[i].b;
            if(dep[a]>dep[b]) swap(a,b);
            assert(b==fa[b]);
            bit.Add(l[a],siz[b]);
            // printf("a=%d b=%d\n",a,b);
            int faa=Find(a);
            // printf("faa=%d\n",faa);
            if(f[faa]) bit.Add(l[f[faa]],-siz[b]);
            fa[b]=faa;siz[faa]+=siz[b];
            // printf("here\n");
        }
        else{
            int a=qu[i].a,b=qu[i].b;
            if(dep[a]>dep[b]) swap(a,b);
            int faa=Find(a);
            int q=bit.Ask(r[faa])-bit.Ask(l[faa]-1)+1;
            int w=bit.Ask(r[b])-bit.Ask(l[b]-1)+1;
            // printf("q=%d w=%d\n",q,w);
            printf("%lld\n",(q-w)*w);
        }
        // puts("here");
    }
    return 0;
}