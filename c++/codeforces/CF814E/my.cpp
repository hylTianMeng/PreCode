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
#define N 55
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
const int mod=1e9+7;
const int inv2=500000004;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,d[N],g[N][N][N],f[N][N],c[N][N],jie[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);rep(i,1,n) read(d[i]);
    rep(i,0,n)rep(j,0,i)if(j==0||j==i)c[i][j]=1;else c[i][j]=inc(c[i-1][j],c[i-1][j-1]);
    jie[0]=1;rep(i,1,n) jie[i]=1ll*jie[i-1]*i%mod;
    g[0][0][0]=1;
    rep(k,1,n){
        rep(l,2,k-1){
            g[0][0][k]=inc(g[0][0][k],1ll*g[0][0][k-1-l]*c[k-1][l]%mod*jie[l]%mod*inv2%mod);
        }
        // printf("g[%d][%d][%d]=%d\n",0,0,k,g[0][0][k]);
    }
    rep(j,1,n)rep(k,0,n){
        if(j>=2) g[0][j][k]=inc(g[0][j][k],1ll*(j-1)*g[0][j-2][k]%mod);
        if(k>=1) g[0][j][k]=inc(g[0][j][k],1ll*g[0][j][k-1]*k%mod);
        // printf("g[%d][%d][%d]=%d\n",0,j,k,g[0][j][k]);
    }
    rep(i,1,n)rep(j,0,n)rep(k,0,n){
        if(j>=1) g[i][j][k]=inc(g[i][j][k],1ll*j*g[i-1][j-1][k]%mod);
        if(k>=1) g[i][j][k]=inc(g[i][j][k],1ll*k*g[i-1][j+1][k-1]%mod);
        // printf("g[%d][%d][%d]=%d\n",i,j,k,g[i][j][k]);
    }
    f[d[1]+1][d[1]]=1;
    rep(i,d[1]+2,n)rep(j,1,i){
        int c1=0,c2=0;
        rep(k,1,i-j){
            if(d[i-j-k+1]==2) c1++;else c2++;
            // printf("i=%d j=%d k=%d c1=%d c2=%d\n",i,j,k,c1,c2);
            f[i][j]=inc(f[i][j],1ll*f[i-j][k]*g[j][c1][c2]%mod);
        }
        // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
    }
    int ans=0,c1=0,c2=0;
    rep(j,1,n){
        if(d[n-j+1]==2) c1++;
        else c2++;
        ans=inc(ans,1ll*f[n][j]*g[0][c1][c2]%mod);
    }
    printf("%d\n",ans);
    return 0;
}