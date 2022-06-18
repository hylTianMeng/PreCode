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
#define N 63
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

int n,K;

int c[N*N][N*N],f[N][N*N][N];

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(K);n<<=1;n++;
    rep(i,0,3601)rep(j,0,i) if(j==0||j==i) c[i][j]=1;else c[i][j]=c[i-1][j]+c[i-1][j-1];
    rep(i,0,n) f[i][i*(i-1)/2][i-1]=1;
    rep(i,1,n)rep(j,0,i*(i-1)/2)rep(k,0,i-1)if(f[i][j][k])rep(o,k+2,n-i){
        int &now=f[i+o][j+o*(o-1)/2][o-k-2];
        now=now+f[i][j][k]*c[o-1][k+1];
    }
    // rep(i,1,n)rep(j,0,i*(i-1)/2)rep(k,0,i-1)printf("f[%lld][%lld][%lld]=%lld\n",i,j,k,f[i][j][k]);
    int ans=0;
    ans+=f[n][K][0];
    rep(i,2,n)
        rep(j,0,K)rep(k,1,n){
            ans=ans+f[i][j][k]*f[n-i][K-j][k-1];
            // printf("f[%d][%d][%d]=%d f[%d][%d][%d]=%d\n",i,j,k,f[i][j][k],n-i,K-j,k-1,f[n-i][K-j][k-1]);
        }
    printf("%lld\n",ans);
    return 0;
}