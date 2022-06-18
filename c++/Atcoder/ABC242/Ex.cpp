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
#define N 410
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

template<typename T> inline void reaœd(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,f[N][N];
P a[N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,m){
        int l,r;read(l);read(r);a[i].fi=l;a[i].se=r;
    }
    f[0][m]=1;
    rep(i,1,n+1){
        rep(j,0,i-1){
            int s=0;
            rep(k,1,m) if(a[k].fi>=j+1&&a[k].se>=i&&a[k].fi<=i) s++;
            rep(k,0,m-s) f[i][k]=sub(f[i][k],f[j][k+s]);
        }
        // rep(k,0,m) printf("f[%d][%d]=%d\n",i,k,f[i][k]);
    }
    int ans=0;
    rep(i,0,m-1){
        // printf("f[%d][%d]=%d\n",n+1,i,f[n+1][i]);
        ans=inc(ans,mul(f[n+1][i],1ll*m*ksm(m-i,mod-2,mod)%mod));
    }
    printf("%d\n",ans);
    return 0;
}