#include<bits/stdc++.h>
#include<unordered_map>
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
#define N 5000100
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int prime[N],tail,p[N],len=5000000,sum[N],inv6,Ans=0,mod,inv2;
ll n;
bool no[N];
unordered_map<int,int> ma;

inline void sieve(){
    no[1]=1;p[1]=1;
    rep(i,2,len){
        if(!no[i]) prime[++tail]=i,p[i]=i-1;
        for(int j=1;j<=tail&&i*prime[j]<=len;j++){
            no[i*prime[j]]=1;
            if(i%prime[j]) p[i*prime[j]]=p[i]*p[prime[j]];
            else{p[i*prime[j]]=p[i]*prime[j];break;}
        }
    }
    
}
inline int sh(int x){return 1ll*x*(x+1)%mod*(2*x+1)%mod*inv6%mod;}
inline int ksm(int a,int b,int mod){int res=1;a%=mod;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
inline int inv(int x){return ksm(x,mod-2,mod);}
inline int p2(int x){return mul(x,x);}
inline int s(int x){return p2(1ll*mul(x,x+1)*inv2%mod);}
inline void pre(){
    rep(i,1,len) sum[i]=inc(sum[i-1],mul(p[i],1ll*i*i%mod));inv6=inv(6);inv2=inv(2);
}
inline int ge(ll n){
    if(n<=len) return sum[n];
    if(ma[n]) return ma[n];
    int ans=s(n%mod);
    for(ll i=2,j;i<=n;){
        j=n/(n/i);
        ans=sub(ans,1ll*(sub(sh(j%mod),sh((i-1)%mod)))*ge(n/i)%mod);i=j+1;
    }
    ma[n]=ans;return ans;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(mod);read(n);
    sieve();pre();
    for(ll i=1,j;i<=n;){
        j=n/(n/i);Ans=inc(Ans,1ll*sub(ge(j),ge(i-1))*s((n/i)%mod)%mod);i=j+1;
    }
    // for(int i=1;i<=n;i++){
    //     Ans=inc(Ans,1ll*s(n/i)*i%mod*i%mod*p[i]%mod);
    //     // printf("p[%d]=%d\n",i,p[i]);
    // }
    printf("%lld\n",Ans);
    return 0;
}