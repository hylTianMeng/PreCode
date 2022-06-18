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

int n,q,Mul[N],Sum[N],p[N];

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

inline int Inv(int a){
    return ksm(a,mod-2,mod);
}

inline void Init(){
    read(n);read(q);
    Mul[0]=1;
    for(int i=1;i<=n;i++){
        read(p[i]);
        Mul[i]=1ll*Mul[i-1]*p[i]%mod;
        Sum[i]=(Sum[i-1]+Mul[i])%mod;
    }
}

inline void Solve(int x,int y){
    int a=1ll*Mul[y]*Inv(Mul[x-1])%mod;
    int b=1ll*(Sum[y-1]-Sum[x-1])*Inv(Mul[x-1])%mod+1;
    int Ans=1ll*Inv(a)*b%mod;
    Ans=(Ans+mod)%mod;
    printf("%d\n",Ans);
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();
    while(q--){
        int x,y;read(x);read(y);
        Solve(x,y);
    }
}