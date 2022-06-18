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
#define N 400010
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

int t;
ull n,f[N],sum[N];

ll isqrt(ll n){
	ll sqrtN=sqrt(n)-1;
	while(sqrtN+1<=n/(sqrtN+1))sqrtN++;
	return sqrtN;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    f[1]=1;sum[1]=1;
    rep(i,2,100000){
        f[i]=sum[isqrt(i)];
        sum[i]=sum[i-1]+f[i];
    }
    read(t);
    while(t--){
        read(n);
        ull b=isqrt(n);
        ull a=isqrt(b);
        ull ans=0;
        rep(i,1,a) ans=ans+f[i]*((ull)b-i*i+1); 
        printf("%llu\n",ans);
    }
    return 0;
}