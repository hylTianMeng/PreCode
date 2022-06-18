#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10001000
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

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int f[N][6],mod,k,n,a[N],Ans;
int inv[N];

inline int calc(int i){
    return 1ll*(1ll*2*f[i][1]%mod+2)*inv[i+1]%mod;
}

inline int Get(int i,int k){
    if(k==1) return f[i][1]+1;
    else if(k==2) return (f[i][2]+1ll*2*f[i][1]%mod)%mod+1;
    else if(k==3) return ((f[i][3]+1ll*3*f[i][2]%mod)%mod+1ll*3*f[i][1]%mod)%mod+1;
    else if(k==4) return (((f[i][4]+1ll*4*f[i][3]%mod)%mod+1ll*6*f[i][2]%mod)%mod+1ll*4*f[i][1]%mod)%mod+1;
    else if(k==5) return ((((f[i][5]+1ll*5*f[i][4]%mod)%mod+1ll*10*f[i][3]%mod)%mod+1ll*10*f[i][2]%mod)%mod+1ll*5*f[i][4]%mod)%mod+1;
    assert(0);
}

int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    read(n);read(k);read(mod);
    if(n<=10){
        int Inv=1;
        for(int i=2;i<=n;++i) {
            Inv=1ll*Inv*ksm(i,mod-2,mod)%mod;
        }
        for(int i=1;i<=n;++i) a[i]=i;
        do{
            int cnt=0; 
            for(int i=2;i<n;++i){
                if(a[i]<a[i-1]&&a[i]<a[i+1]) cnt++;
            }
            (Ans+=ksm(cnt,k,mod))%=mod;
        }while(next_permutation(a+1,a+1+n));
        Ans=(1ll*Ans*Inv)%mod;
        printf("%lld\n", Ans);
        return 0;
    }
    inv[1]=1;for(int i=2;i<=n;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=5;j++){
            f[i][j]=(1ll*calc(i-1)*f[i-1][j]%mod+1ll*(1-calc(i-1))*Get(i-1,j)%mod)%mod;
        }
    }
    printf("%d\n",(f[n][k]%mod+mod)%mod);
    return 0;
}