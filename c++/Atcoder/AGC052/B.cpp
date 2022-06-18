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

int n,m;

struct edge{
    int to,next,w1,w2;
    inline void Init(int to_,int ne_,int w1_,int w2_){
        to=to_;next=ne_;w1=w1_;w2=w2_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to,int w1,int w2){
    li[++tail].Init(to,head[from],w1,w2);
    head[from]=tail;
}

int f[N],g[N],sum;
multiset<int> s,t;

inline void dfs(int k,int fa){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa) continue;
        int w1=li[x].w1;
        f[to]=f[k]^w1;g[to]=g[k]^li[x].w2;
        sum^=f[to];sum^=g[to];
        dfs(to,k);
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n-1){
        int from,to,w1,w2;
        read(from);read(to);read(w1);read(w2);
        Add(from,to,w1,w2);Add(to,from,w1,w2);
    }
    dfs(1,0);
    bool op=0;
    rep(i,1,n){
        if(f[i]==sum){op=1;break;}
    }
    if(!op){
        puts("NO");return 0;
    }
    rep(i,1,n){
        s.insert(f[i]^sum);
        t.insert(g[i]);
        // printf("f[%d]=%d g[%d]=%d\n",i,f[i],i,g[i]);
    }
    if(s==t){puts("YES");}
    else puts("NO");
    return 0;
}