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
#define N 251
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

int f[N][N],n,m,c[N][N],p[N][N*N],len=250;

int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);
    rep(i,0,m) f[i][0]=1;
    rep(i,0,len)rep(j,0,i)if(j==0||j==i) c[i][j]=1;else c[i][j]=inc(c[i-1][j-1],c[i-1][j]);
    rep(i,0,len){
        p[i][0]=1;
        rep(j,1,len*len) p[i][j]=mul(p[i][j-1],i);
    }
    rep(i,1,m){
        rep(j,1,n-1){
            rep(k,0,j){
                f[i][j]=inc(f[i][j],mul(mul(f[i-1][k],c[n-1-k][j-k]),p[m-i+1][(j-k)*(j-k-1)/2+k*(j-k)]));
                // printf("%d %d %d\n",f[i-1][k],c[n-1-k][j-k],p[m-i+1][(j-k)*(j-k-1)/2+k*(j-k)]);
                // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
            }
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
    printf("%d\n",f[m][n-1]);
}