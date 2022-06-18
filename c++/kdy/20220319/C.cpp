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

int t,n,a[N],b[N],f[N],g[N],siz[N];
vi e[N];

inline void dfs(int k,int fa){
    siz[k]=1;
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);siz[k]+=siz[to];
    }
}

inline void Init(){
    read(n);rep(i,1,n) read(a[i]);rep(i,1,n-1){int from,to;read(from);read(to);e[from].pb(to);e[to].pb(from);}
    dfs(1,0);
}

namespace s1{
    inline void dfs(int k,int fa){
        int sum=0,s2=0;
        for(int to:e[k]){
            if(to==fa) continue;
            dfs(to,k);sum+=siz[to];s2+=f[to];
        }
        if(!b[k]) f[k]=siz[k];
        else{
            for(int to:e[k]){if(to==fa) continue;f[k]+=f[to];}
        }
        for(int to:e[k]){
            if(to==fa) continue;g[k]+=g[to];
        }
        if(!b[k]){
            g[k]+=f[k];
            for(int to:e[k]){
                if(to==fa) continue;
                sum-=siz[to];
                g[k]+=siz[to]*sum;
            }
        }
        else{
            g[k]+=f[k];int nowans=0;
            for(int to:e[k]){
                if(to==fa) continue;
                int ns=sum-siz[to];nowans+=ns*f[to];
                s2-=f[to];nowans-=s2*f[to];
            }
            g[k]+=nowans;
        }
        // printf("f[%d]=%d g[%d]=%d\n",k,f[k],k,g[k]);
    }
}

namespace s2{
    inline void dfs(int k,int fa){
        int sum=0,s2=0;
        for(int to:e[k]){
            if(to==fa) continue;
            dfs(to,k);sum+=siz[to];s2+=f[to];
        }
        if(b[k]) f[k]=siz[k];
        else{
            for(int to:e[k]){if(to==fa) continue;f[k]+=f[to];}
        }
        for(int to:e[k]){
            if(to==fa) continue;g[k]+=g[to];
        }
        if(b[k]){
            g[k]+=f[k];
            for(int to:e[k]){
                if(to==fa) continue;
                sum-=siz[to];
                g[k]+=siz[to]*sum;
            }
        }
        else{
            g[k]+=f[k];int nowans=0;
            for(int to:e[k]){
                if(to==fa) continue;
                int ns=sum-siz[to];nowans+=ns*f[to];
                s2-=f[to];nowans-=s2*f[to];
            }
            g[k]+=nowans;
        }
        // printf("f[%d]=%d g[%d]=%d\n",k,f[k],k,g[k]);
    }
}

namespace s3{
    inline void dfs(int k,int fa){
        int sum=0,s2=0;
        for(int to:e[k]){
            if(to==fa) continue;dfs(to,k);
            sum+=f[to];s2+=siz[to]-f[to];
        }
        if(b[k]){
            f[k]++;
            for(int to:e[k]){
                if(to==fa) continue;f[k]+=(siz[to]-f[to]);
            }
        }
        else{
            for(int to:e[k]) if(to!=fa) f[k]+=f[to];
        }
        g[k]+=f[k];for(int to:e[k]) if(to!=fa) g[k]+=g[to];
        if(b[k]){
            for(int to:e[k]){
                if(to==fa) continue;
                sum-=f[to];s2-=(siz[to]-f[to]);
                g[k]+=f[to]*sum;g[k]+=(siz[to]-f[to])*s2;
            }
        }
        else{
            for(int to:e[k]){
                if(to==fa) continue;
                int ns=sum-f[to];
                g[k]+=ns*(siz[to]-f[to]);
            }
        }
    }
}

inline void cle(){
    rep(i,1,n) g[i]=f[i]=0;
}

inline void Solve(){
    ld ans1=0,ans2=0,ans3=0;
    dec(i,0,20){
        int sum=-1;
        rep(j,1,n) b[j]=(a[j]>>i)&1;
        int s1=0,s0=0;
        rep(j,1,n) if(b[j]) s1++;else s0++;
        s1::dfs(1,0);sum=n*n-(g[1]*2-s0);ans1+=(ld)sum*(1<<i)/(ld)(n*n);cle();
        s2::dfs(1,0);sum=g[1]*2-s1;ans2+=(ld)sum*(1<<i)/(ld)(n*n);cle();
        s3::dfs(1,0);sum=g[1]*2-s1;ans3+=(ld)sum*(1<<i)/(ld)(n*n);cle();
    }
    printf("%.3Lf %0.3Lf %0.3Lf\n",ans1+eps,ans2+eps,ans3+eps);
}

inline void Clear(){
    rep(i,1,n) e[i].clear(),siz[i]=0;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve();Clear();
    }
    return 0;
}