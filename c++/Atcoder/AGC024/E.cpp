#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 310
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k,mod,c[N][N],sum[N][N],f[N][N];

inline void PreWork(){
    for(int i=0;i<=300;i++){
        for(int j=0;j<=i;j++){
            if(j==i||j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j==i) sum[j][i]=c[j][i];
            else sum[j][i]=(c[j][i]+sum[j-1][i])%mod;
            // printf("sum[%d][%d]=%d\n",j,i,sum[j][i]);
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);read(mod);
    PreWork();
    for(int i=0;i<=300;i++) f[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int q=1;q<=i;q++){
                f[i][j]=(f[i][j]+1ll*f[q-1][j-1]*f[i-q][j]%mod*sum[i-1][i-q]%mod)%mod;
            }
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
            f[i][j]=(f[i][j]+f[i][j-1])%mod;
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
    printf("%lld\n",f[n][k]);
    return 0;
}