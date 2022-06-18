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
#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n,f[N];

struct edge{
    int to,next,x,y;
    inline void Init(int to_,int ne_,int x_,int y_){
        to=to_;next=ne_;x=x_;y=y_;
    }
}li[N<<1];
int head[N],tail,ans;

inline void Add(int from,int to,int x,int y){
    li[++tail].Init(to,head[from],x,y);
    head[from]=tail;
}

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

inline int lcm(int a,int b){
    return a*b/gcd(a,b);
}

inline void dfs(int k,int fa,int val){
    bool op=0;f[k]=val;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        op=1;dfs(to,k,li[x].y);
        f[k]=lcm(f[k],f[to]/li[x].y*li[x].x);
    }
}

inline void dfs2(int k,int fa){
    ans=(ans+f[k])%mod;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa) continue;
        f[to]=f[k]/li[x].x*li[x].y;dfs2(to,k);
    }
}

inline void Clear(){
    rep(i,1,n) head[i]=0,f[i]=0;tail=ans=0;
}

signed main(){
    read(t);
    while(t--){
        read(n);
        rep(i,1,n-1){
            int from,to,x,y;read(from);read(to);read(x);read(y);
            Add(from,to,x,y);Add(to,from,y,x);
        }
        dfs(1,0,1);dfs2(1,0);printf("%lld\n",ans);Clear();
    }
    return 0;
}
