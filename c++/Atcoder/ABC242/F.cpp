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
#define N 51
#define M 2510
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
#define int long long
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

int f[N][N],g[N][N];
int c[M][M],n,m,B,W,ans;

inline void PreWork(){
    rep(i,0,2500)rep(j,0,i)if(j==0||j==i) c[i][j]=1;else c[i][j]=inc(c[i-1][j],c[i-1][j-1]);
}

signed main(){
    read(n);read(m);
    read(B);read(W);
    PreWork();
    rep(i,0,n)rep(j,0,m)f[i][j]=1ll*c[i*j][W];
    rep(i,0,n)rep(j,0,m)rep(k,0,i)rep(o,0,j)g[i][j]=inc(g[i][j],1ll*c[i][k]*c[j][o]%mod*sgn(i+j-k-o)%mod*f[k][o]%mod);
    rep(i,0,n)rep(j,0,m){
        // printf("g[%d][%d]=%d\n",i,j,g[i][j]);
        ans=inc(ans,1ll*g[i][j]*c[(n-i)*(m-j)][B]%mod*c[n][i]%mod*c[m][j]%mod);
    }
    printf("%lld\n",ans);
    return 0;
}