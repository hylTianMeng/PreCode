#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 410
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k,f[N][N];

int main(){
    // freopen("my.out","w",stdout);
    read(n);
    f[1][1]=1;f[1][0]=1;
    for(int i=2;i<=n;i++){
        f[i][0]=1;
        for(int j=1;j<=400;j++){
            for(int p=0;p<=j-1;p++) f[i][j]=(f[i][j]+1ll*f[i-1][p]*f[i-1][j-1-p]%mod)%mod;
            for(int p=0;p<=j;p++) f[i][j]=(f[i][j]+1ll*f[i-1][p]*f[i-1][j-p]%mod)%mod;
            for(int p=0;p<=j;p++) f[i][j]=(f[i][j]+1ll*f[i-1][p]*f[i-1][j-p]%mod*2%mod*j%mod)%mod;
            for(int p=0;p<=j+1;p++) f[i][j]=(f[i][j]+1ll*f[i-1][p]*f[i-1][j+1-p]%mod*(j+1)%mod*j%mod)%mod;
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
    printf("%d\n",f[n][1]);
    return 0;
}