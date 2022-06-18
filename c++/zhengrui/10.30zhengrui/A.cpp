#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 21
#define M 1000100
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][M],n,k,g[N][M];

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);read(k);
    f[0][0]=1;for(int i=0;i<=n;i++) g[0][i]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            (f[i][j]+=g[i-1][j/2])%=mod;
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
        for(int j=1;j<=n;j++){
            g[i][j]=(g[i][j-1]+f[i][j])%mod;
        }
    }
    printf("%d\n",f[k][n]);
}