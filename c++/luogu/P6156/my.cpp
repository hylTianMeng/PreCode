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
#define Next(k) for(int x=head[k];x;x=li[x].next)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 10001000
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
// #define int long long
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

int n,m;
ll k;
int pr[N],ta,h[N],g[N],f[N],len=1e7,s[N];
bool no[N];

inline int ksm(int a,ll b,int mod){b%=(mod-1);int res=1;while(b){if(b&1) res=1ll*a*res%mod;a=1ll*a*a%mod;b>>=1;}return res;}

inline void sieve(){
    no[1]=1;h[1]=1;g[1]=1;
    rep(i,2,len){
        if(!no[i]) pr[++ta]=i,h[i]=ksm(i,k,mod),g[i]=i-1;
        for(int j=1;j<=ta&&i*pr[j]<=len;j++){
            no[i*pr[j]]=1;
            if(i%pr[j]) h[i*pr[j]]=mul(h[i],h[pr[j]]),g[i*pr[j]]=g[i]*g[pr[j]];
            else{
                h[i*pr[j]]=mul(h[i],h[pr[j]]);
                if((i/pr[j])%pr[j]==0) g[i*pr[j]]=0;
                else g[i*pr[j]]=g[i/pr[j]]*(-pr[j]);
                break;
            }
        }
    }
    rep(i,1,len) s[i]=(s[i-1]+h[i])%mod;
    rep(i,1,(len>>1)) f[i]=(f[i-1]+(mul(2,(s[i*2]-s[i])%mod)-h[i*2])%mod)%mod;
}

signed main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(k);sieve();
    int Ans=0;
    rep(i,1,n){
        Ans=(Ans+mul(f[n/i],mul(h[i],g[i])))%mod;
        // printf("i=%d f=%d h=%d g=%d\n",i,f[i],h[i],g[i]);
    }
    printf("%lld\n",(Ans%mod+mod)%mod);
}