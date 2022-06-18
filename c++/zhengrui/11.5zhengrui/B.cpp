#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 3009
#define M 2010
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=258280327;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,x,y,p,q,ans,Pow1[N],Pow2[N];
int f[N][N][2];
int c[N][N];

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}
    return res;
}

void GetPre(){
    for(int i=0;i<=M;i++){
        for(int j=0;j<=i;j++){
            if(j==i||j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}

inline void Init(){
    read(n);read(x);read(y);
    p=1ll*x*ksm(y,mod-2,mod)%mod;
    q=(mod+1-p)%mod;
    memset(f,0,sizeof(f));
    f[0][n-1][0]=(n-1)*ksm(n,mod-2,mod)%mod;
    f[0][n-1][1]=ksm(n,mod-2,mod);
    Pow1[0]=Pow2[0]=1;
    for(int i=1;i<=n;i++){Pow1[i]=Pow1[i-1]*p%mod;Pow2[i]=Pow2[i-1]*q%mod;}
}

inline void Solve(){     
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k++)
                f[i][j][0]=(f[i][j][0]+f[i-1][k][0]*Pow1[k-j]%mod*Pow2[j]%mod*c[k-1][j-1]%mod)%mod;
        for(int j=0;j<=n-1;j++) f[i][j][1]=f[i][j+1][0]*ksm(j+1,mod-2,mod)%mod;
        for(int j=1;j<=n-1;j++) f[i][j][0]=f[i][j+1][0]*j%mod*ksm(j+1,mod-2,mod)%mod; 
    } 
    for(int i=0;i<=n-1;i++){ans=0;for(int j=0;j<=n;j++) ans=(ans+f[i][j][1])%mod;printf("%lld ",ans);}putchar('\n');
}
signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    int t;read(t);
    GetPre();
    while(t--){
        Init();
        Solve();
    }
    return 0;
}