#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 20
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

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

int n,m,a[N],b[N],c[N];

map<int,int> d,d2;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);read(b[i]);
    }
    for(int i=1;i<=n;i++){
        int res=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            res=1ll*res*((1-1ll*a[j]*ksm(a[i],mod-2,mod)%mod)%mod)%mod;
        }
        c[i]=ksm(res,mod-2,mod);
    }
    // for(int i=1;i<=n;i++){
    //     printf("%lld ",c[i]);
    // }puts("");
    d[0]=1;d[b[1]+1]=-ksm(a[1],b[1]+1,mod);
    for(int i=2;i<=n;i++){
        d2.clear();
        for(auto now:d){
            (d2[now.first+b[i]+1]-=1ll*now.second*ksm(a[i],b[i]+1,mod)%mod)%=mod;
        }
        for(auto now:d2){
            (d[now.first]+=now.second)%=mod;
        }
    }
    int Ans=0;
    for(auto now:d){
        if(now.first>m) continue;
        for(int i=1;i<=n;i++){
            Ans=(Ans+1ll*now.second*c[i]%mod*ksm(a[i],m-now.first,mod)%mod)%mod;
        }
    }
    printf("%lld\n",(Ans+mod)%mod);
    return 0;
}