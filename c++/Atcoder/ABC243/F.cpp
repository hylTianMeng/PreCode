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
#define N 54
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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,k,w[N],p[N],sum,fac[N];
int f[N][N][N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(k);
    rep(i,1,n){
        read(w[i]);sum=inc(sum,w[i]);
    }
    rep(i,1,n) p[i]=mul(w[i],ksm(sum,mod-2,mod));
    // rep(i,1,n) printf("%d\n",p[i]);
    fac[0]=1;rep(i,1,50) fac[i]=mul(fac[i-1],i);
    int now=fac[k];
    rep(i,0,50) fac[i]=ksm(fac[i],mod-2,mod);
    f[0][0][0]=1;
    rep(i,0,n-1)rep(j,0,m)rep(o,0,k)if(f[i][j][o]){
        rep(no,o,k) f[i+1][j+(no!=o)][no]=inc(f[i+1][j+(no!=o)][no],1ll*f[i][j][o]*fac[no-o]%mod*ksm(p[i+1],no-o,mod)%mod);
    }
    printf("%d\n",mul(f[n][m][k],now));
    return 0;
}