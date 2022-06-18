#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;
const int inv=499122177;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

ll n,Ans,m,w;

inline int ksm(int a,int b){
    int res=1;while(b){if(b&1){res=1ll*res*a%mod;}a=1ll*a*a%mod;b>>=1;}return res;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);m=n;while(m){w++;m/=10;}
    if(w==1){
        Ans=1ll*(1+n)%mod*(n%mod)%mod*inv%mod;printf("%lld\n",Ans);return 0;
    }
    // printf("w=%d\n",w);
    Ans+=1ll*(1+n-ksm(10,w-1)+1)%mod*((n-ksm(10,w-1)+1)%mod)%mod*inv%mod;
    for(int i=w-1;i>=2;i--){
        int b=(ksm(10,i)%mod-ksm(10,i-1)%mod)%mod;
        Ans+=1ll*(1+b)*b%mod*inv%mod;
    }
    (Ans+=45)%=mod;
    printf("%lld\n",(Ans%mod+mod)%mod);
    return 0;
}