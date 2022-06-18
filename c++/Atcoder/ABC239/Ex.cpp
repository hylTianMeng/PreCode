#include<bits/stdc++.h>
#include<unordered_map>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

unordered_map<int,int> Map;

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int n,m,inv;

inline int Solve(int x){
    // printf("x=%d\n",x);
    if(Map.find(x)!=Map.end()) return Map[x];
    int ans=0;
    for(int i=2,j;i<=min(x,n);i=j+1){
        j=(x/(x/i));
        assert(x/i==x/j);
        j=min(j,n);
        ans=(ans+1ll*((j-i+1)%mod)*Solve(x/i)%mod*inv%mod)%mod;
    }
    // printf("x=%d ans=%d\n",x,ans);
    // return (Map[x]=(ans+1ll*n*inv%mod)%mod);
    Map[x]=(ans+1ll*n*inv%mod)%mod;
    return Map[x];
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    inv=ksm(n-1,mod-2,mod);Map[0]=0;
    assert(1ll*inv*(n-1)%mod==1);
    printf("%lld\n",Solve(m));
    return 0;
}