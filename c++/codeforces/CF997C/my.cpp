#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M number
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

int n,Ans,Jie[N],Inv[N],Invjie[N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1){res=1ll*res*a%mod;}a=1ll*a*a%mod;b>>=1;}return res;}
inline int C(int n,int m){if(n<m)return 0;return 1ll*Jie[n]*Invjie[n-m]%mod*Invjie[m]%mod;}
inline int sgn(int k){return (k&1)?(mod-1):1;}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    Jie[0]=1;for(int i=1;i<=n;i++) Jie[i]=1ll*Jie[i-1]*i%mod;
    Inv[1]=1;for(int i=2;i<=n;i++) Inv[i]=1ll*(mod-mod/i)*Inv[mod%i]%mod;
    Invjie[0]=1;for(int i=1;i<=n;i++) Invjie[i]=1ll*Invjie[i-1]*Inv[i]%mod;

    for(int i=1;i<=n;i++) Ans=(Ans+1ll*C(n,i)*ksm(3,mod-1-(1ll*n*i)%(mod-1),mod)%mod*sgn(i)%mod*(ksm((1-ksm(3,mod-1+i-n,mod)+mod)%mod,n,mod)-1)%mod)%mod;
    Ans=1ll*Ans*ksm(3,1ll*n*n%(mod-1)+1,mod)%mod;
    // printf("Ans=%d\n",Ans);
    Ans=(Ans+1ll*2*ksm(3,1ll*n*n%(mod-1),mod)%mod*(ksm((1-ksm(3,mod-1+1-n,mod)+mod)%mod,n,mod)-1)%mod)%mod;
    printf("%d\n",((-Ans)%mod+mod)%mod);
    return 0;
}