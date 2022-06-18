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
#define N 1010
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

int f[N],n,k,a[N],p[N],g[N];
const int mod=998244353;

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    read(n);read(k);rep(i,1,n) read(a[i]);
    f[0]=1;
    rep(i,1,n)dec(j,0,n)f[j+1]=inc(f[j+1],mul(f[j],a[i]));
    int invn=ksm(n,mod-2,mod);
    p[0]=1;rep(i,1,n) p[i]=mul(p[i-1],invn);
    g[0]=1;
    rep(i,1,n){
        g[i]=1;
        rep(j,1,i) g[i]=mul(g[i],k+1-j);
        g[i]=mul(g[i],p[i]);
    }
    int ans=0;
    rep(i,0,n) ans=inc(ans,mul(f[i],g[n-i]));
    printf("%d\n",ans);
    return 0;
}