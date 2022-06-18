#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 11
#define M 110
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

int n,m,f[N][M],g[M][M],jie[M],jieinv[M],inv[M],dp[M],s[N][10],t[10],ans;
char S[N][M];

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}
    // assert(res>=0);
    return res;
}

inline void Init(){
    read(n);read(m);
    printf("n=%d m=%d\n",n,m);
    for(int i=1;i<=n;i++){
        scanf("%s",S[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+1;j++) s[i][S[i][j]-'0']++;
    }
}

inline int DesPower(int a,int b){
    // printf("a=%d b=%d ans=%d\n",a,b,1ll*jie[a]*jieinv[a-b]%mod);
    return 1ll*jie[a]*jieinv[a-b]%mod;
}

inline int sgn(int x){return (x&1)?(-1):1;}

inline void PreWork(){
    inv[1]=1;jieinv[0]=jieinv[1]=1;jie[0]=jie[1]=1;
    for(int i=2;i<=m;i++){
        jie[i]=1ll*jie[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        jieinv[i]=1ll*jieinv[i-1]*inv[i]%mod;
        printf("jie[%d]=%d\n",i,jie[i]);
        printf("inv[%d]=%d\n",i,inv[i]);
        printf("jieinv[%d]=%d\n",i,jieinv[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=1ll*sgn(i-1)*jie[j]*ksm(ksm(DesPower(m,j),i,mod),mod-2,mod)%mod;
            printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
}

inline void Solve(){
    for(int i=1;i<=(1<<n)-1;i++){
        printf("i=%d\n",i);
        fill(dp+1,dp+m+1,0);
        for(int j=0;j<=9;j++){
            for(int k=0;k<=m;k++){
                g[j][k]=1;
                for(int l=0;l<=n-1;l++){
                    if((i>>l)&1) g[j][k]=1ll*g[j][k]*DesPower(s[l+1][j],k)%mod;
                }
                printf("g[%d][%d]=%d\n",j,k,g[j][k]);
            }
        }//预处理完.
        dp[0]=1;
        for(int j=0;j<=9;j++){
            for(int k=0;k<=m;k++){
                if(dp[k]==-INF) continue;
                for(int l=0;l<=m;l++){
                    dp[k+l]=(dp[k+l]+1ll*dp[k]*g[j][l]%mod*jieinv[l]%mod)%mod;
                }
            }
        }
        int Size=__builtin_popcount(i);
        for(int j=0;j<=m;j++){
            printf("dp[%d]=%d\n",j,dp[j]);
            ans=(ans+1ll*dp[j]*f[Size][j]%mod)%mod;
        }
    }
    printf("%d\n",(ans+mod)%mod);
}


int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();PreWork();Solve();
}
/*
3 3
666
233
366

110916048
*/
