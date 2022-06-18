#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(mod-1):1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 210
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

vi e[N];
int n,m,f[N],g[N],h[N][N][2],siz[N],p[N][2],c[N][N];

inline void dfs(int k,int fa){
    h[k][1][1]=1;h[k][1][0]=1;siz[k]=1;
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);
        dec(i,1,siz[k])dec(j,1,siz[to]){
            p[i+j][0]=inc(p[i+j][0],1ll*h[k][i][0]*h[to][j][1]%mod);
            p[i+j][1]=inc(p[i+j][1],1ll*h[k][i][1]*h[to][j][1]%mod);
            p[i+j-1][0]=inc(p[i+j-1][0],1ll*h[k][i][0]*h[to][j][0]%mod);
            p[i+j-1][1]=inc(p[i+j-1][1],1ll*h[k][i][1]*h[to][j][0]%mod);
            p[i+j-1][1]=inc(p[i+j-1][1],1ll*h[k][i][0]*h[to][j][1]%mod);
        }
        siz[k]+=siz[to];
        rep(i,1,siz[k]) h[k][i][0]=p[i][0],h[k][i][1]=p[i][1],p[i][0]=p[i][1]=0;
    }
    // rep(i,1,siz[k]){
    //     printf("f[%d][%d][0]=%d\nf[%d][%d][1]=%d\n",k,i,h[k][i][0],k,i,h[k][i][1]);
    // }
}

inline void PreWork(){
    read(n);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    rep(i,0,n)rep(j,0,i) if(j==0||j==i) c[i][j]=1;else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}

inline void Solve(){
    g[n-1]=1;dfs(1,0);rep(i,0,n-2) g[i]=1ll*ksm(n,n-i-2,mod)*h[1][n-i][1]%mod;

    // rep(i,0,n-1) printf("g[%d]=%d\n",i,g[i]);

    rep(i,0,n)rep(j,i,n)f[i]=inc(f[i],1ll*sgn(j-i)*c[j][i]%mod*g[j]%mod);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();Solve();
    rep(i,0,n-1) printf("%d ",f[i]);
    return 0;
}