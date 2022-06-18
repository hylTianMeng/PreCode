#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int inv2=(mod+1)/2;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k,f[N][N],a[N];
bool vis[N];

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

inline void Solve(int *f,int n){
    int g=gcd(n,k);
    for(int i=0;i<g;i++){
        int b=2,c=-a[i];
        int j=i;
        while((j+k)%n!=i){
            j+=k;j%=n;
            (b*=2)%=mod;(c*=2)%=mod;(c-=a[j])%=mod;
        }
        f[i]=1ll*(-c)*ksm(b-1,mod-2,mod)%mod;
        j=i;
        while((j+k)%n!=i){
            int nxt=(j+k)%n;
            f[nxt]=(1ll*2*f[j]%mod-a[j])%mod;
            j+=k;j%=n;
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    read(n);read(k);
    f[1][0]=1;
    for(int i=2;i<=n;i++){
        // printf("i=%d\n",i);
        for(int j=1;j<i;j++){
            a[j]=f[i-1][(j+k-1)%(i-1)];
        }
        for(int i=0;i<=n;i++) vis[i]=0;
        Solve(f[i],i);
    }
    printf("%d\n",(f[n][(k-1)%n]%mod+mod)%mod);
    return 0;
}