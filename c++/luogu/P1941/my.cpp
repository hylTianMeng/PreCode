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
#define N 10100
#define M 1100
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

int n,m,k;
int f[N][M],tot;
P a[N],b[N];

int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);read(k);
    mset(f,INF);
    rep(i,1,m) f[0][i]=0;
    rep(i,1,n){
        int x,y;read(x);read(y);a[i].fi=x;a[i].se=y;
    }
    mset(b,-1);
    rep(i,1,k){
        int p,l,r;read(p);read(l);read(r);b[p]=mp(l,r);
    }
    rep(i,0,n-1){
        int x=a[i+1].fi,y=a[i+1].se;
        rep(j,1,m) cmin(f[i+1][min(j+x,m)],f[i][j]+1);
        rep(j,1,m) cmin(f[i+1][min(j+x,m)],f[i+1][j]+1);
        rep(j,y+1,m) cmin(f[i+1][j-y],f[i][j]);
        if(b[i+1].fi==-1){
            // rep(j,1,m){
            //     printf("f[%d][%d]=%d\n",i+1,j,f[i+1][j]);
            // }
            continue;
        }
        // puts("");
        rep(j,0,b[i+1].fi) f[i+1][j]=INF;
        rep(j,b[i+1].se,m) f[i+1][j]=INF;
        int minn=INF;
        rep(j,1,m) minn=min(minn,f[i+1][j]);
        if(minn==INF){
            printf("0\n%d\n",tot);
            return 0;
        }
        else tot++;
        // rep(j,1,m){
        //     printf("f[%d][%d]=%d\n",i+1,j,f[i+1][j]);
        // }
    }
    int minn=INF;
    rep(i,1,m){
        minn=min(minn,f[n][i]);
    }
    printf("1\n%d\n",minn);
    return 0;
}