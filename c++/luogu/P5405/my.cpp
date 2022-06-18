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
#define N 3010
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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],b[N],c[N],s[N],f[N][N],siz[N],g[N],Ans;
int inv[N];

vector<P> e[N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

inline void dfs(int k,int fa){
    f[k][1]=1ll*a[k]*s[k]%mod;
    f[k][2]=1ll*b[k]*s[k]%mod*2%mod;
    f[k][3]=1ll*c[k]*s[k]%mod*3%mod;
    siz[k]=1;
    for(P to:e[k]){
        if(to.fi==fa) continue;
        dfs(to.fi,k);
        rep(i,1,siz[k]*3)rep(j,1,siz[to.fi]*3){
            int now=1ll*f[k][i]*f[to.fi][j]%mod;
            if(to.se){
                g[i+j]=sub(g[i+j],now);g[i]=inc(g[i],now);
            }
            else g[i+j]=inc(g[i+j],now);
        }
        siz[k]+=siz[to.fi];
        rep(i,1,siz[k]*3) f[k][i]=g[i],g[i]=0;
    }
    rep(i,1,siz[k]*3) f[k][i]=1ll*f[k][i]*inv[i]%mod;
    // printf("siz=%d\n",siz[k]);
    // rep(i,1,siz[k]*3) printf("f[%d][%d]=%d\n",k,i,f[k][i]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);rep(i,1,n){read(a[i]);read(b[i]);read(c[i]);s[i]=a[i]+b[i]+c[i];}
    rep(i,1,n) s[i]=ksm(s[i],mod-2,mod);
    inv[1]=1;rep(i,2,n*3) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(mp(to,0));e[to].pb(mp(from,1));
    }
    dfs(1,0);
    rep(i,1,n*3){
        // printf("f[1][%d]=%d\n",i,f[1][i]);
        Ans=inc(Ans,f[1][i]);
    }
    printf("%d\n",Ans);
    return 0;
}