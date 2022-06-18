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
#define N 51
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
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

int n,siz[N];
vi e[N];
ld f[N][N],g[N],jie,c[N][N],h[N];

inline void dfs(int k,int fa){
    f[k][0]=1;siz[k]=1;
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);
        // printf("to=%d\n",to);
        rep(i,0,siz[to])
            rep(j,0,siz[to]) if(j<i) g[i]+=f[to][j]*0.5;else if(j==i) g[i]+=f[to][j]*(siz[to]-j);
        // rep(i,0,siz[to]) printf("g[%d]=%Lf\n",i,g[i]);
        // printf("spe %Lf %Lf\n",f[k][0],g[2]);
        rep(i,0,siz[k])
            rep(j,0,siz[to]){
                h[i+j]+=f[k][i]*g[j]*c[i+j][j]*c[siz[k]+siz[to]-1-i-j][siz[k]-1-i];
                // printf("i=%d j=%d %Lf\n",i,j,c[siz[k]+siz[to]-1-i-j][siz[k]-1-i]);
            }
        siz[k]+=siz[to];
        // rep(i,0,siz[k]) printf("h[%d]=%Lf\n",i,h[i]);
        rep(i,0,siz[k]){
            f[k][i]=h[i];
            // printf("f[%d][%d]=%Lf\n",k,i,f[k][i]);
            h[i]=0;g[i]=0;
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    rep(i,0,50)rep(j,0,i)if(j==0||j==i)c[i][j]=1;else c[i][j]=c[i-1][j]+c[i-1][j-1];
    jie=1;rep(i,1,n-1) jie*=i;
    rep(i,1,n){
        rep(i,0,n)rep(j,0,n)f[i][j]=0;
        dfs(i,0);
        printf("%0.8Lf\n",f[i][n-1]/jie);
    }
    return 0;
}