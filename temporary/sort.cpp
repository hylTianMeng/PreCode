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
#define N 5
#define M 200010
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

int n,m,a[N][M],ans;

namespace sub1{
    inline void Solve(){
        rep(i,1,n)rep(j,1,n){
            int minn=INF,maxx=-INF;
            rep(k,1,m) minn=min(minn,a[k][i]+a[k][j]);
            rep(k,1,m) maxx=max(maxx,a[k][i]+a[k][j]);
            ans+=minn+maxx;
        }
        printf("%lld\n",ans);
    }
}
namespace sub2{
    inline void Solve(){
        rep(i,1,n)rep(j,1,m)ans+=a[i][j]*n;
        printf("%lld\n",ans);
    }
}

signed main(){
    // freopen("sort.in","r",stdin);
    // freopen("sort.out","w",stdout);
    read(m);read(n);
    rep(i,1,m)rep(j,1,n)read(a[i][j]);
    if(n<=3000) sub1::Solve();
    else if(m==2) sub2::Solve();
    return 0;
}