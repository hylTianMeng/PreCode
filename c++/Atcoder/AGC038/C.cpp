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
#define N 1000100
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
const int inv2=499122177;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],cnt[N],f[N],m=1000000,inv[N],Ans;
int prime[N],tail,mu[N];
bool no[N];
inline void sieve(){
    mu[1]=1;no[1]=1;
    rep(i,2,m){
        if(!no[i]) prime[++tail]=i,mu[i]=-1;
        for(int j=1;j<=tail&&prime[j]*i<=m;j++){
            no[prime[j]*i]=1;
            if(i%prime[j]) mu[i*prime[j]]=-mu[i];
            else break;
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    sieve();
    read(n);rep(i,1,n) read(a[i]),cnt[a[i]]++;
    rep(i,1,m){
        int s=0;for(int j=i;j<=m;j+=i) s=inc(s,mul(cnt[j],j));
        s=mul(s,s);
        int s2=0;for(int j=i;j<=m;j+=i) s2=inc(s2,mul(cnt[j],mul(j,j)));
        s=sub(s,s2);s=mul(s,inv2);
        f[i]=s;
        // assert(f[i]>=0);
    }
    inv[1]=1;rep(i,2,m) inv[i]=mul((mod-mod/i),inv[mod%i]);
    rep(i,1,m){
        if(!mu[i]) continue;
        int s=0;
        for(int j=i;j<=m;j+=i) s=inc(s,mul(f[j],inv[j]));
        s=mul(s,mu[i]*i);
        Ans=(Ans+s)%mod;
    }
    printf("%lld\n",(Ans%mod+mod)%mod);return 0;
}