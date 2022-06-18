#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

int prime_list[]={0,2,3,5,11,13,17,19,23,37};

inline ll ksc(ll x,ll y,ll mod){
	ll z=(ld)x/mod*y;
	ll res=(ull)x*y-(ull)mod*z;
	return (res%mod+mod)%mod;
}

inline int ksm(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1) res=ksc(a,res,mod);
        a=ksc(a,a,mod);
        b>>=1;
    }
    return res;
}

inline bool miller_rabin(int d,int r,int n,int a){
    int x=ksm(a,d,n);
    if(x==1) return 1;
    for(int i=0;i<=r-1;i++){
        if(x==n-1) return 1;
        x=ksc(x,x,n);
    }
    return 0;
}

inline bool is_prime(int n){
    if(n<2) return 0;
    int d=n-1,r=0;
    while(!(d&1)) d>>=1,r++;
    for(int i=1;i<=9;i++){
        if(n==prime_list[i]) return 1;
        if(!miller_rabin(d,r,n,prime_list[i])) return 0;
    }
    return 1;
}

int g[N],n;

signed main(){
    for(int i=3;i<=100000;i++){
        int a=i*i-i+1;
        if(is_prime(a-2)) g[i]=(a-2)*2%mod;
        g[i]+=g[i-1];g[i]%=mod;
    }
    read(n);
    for(int i=1;i<=n;i++){
        int l,r;read(l);read(r);
        printf("%lld\n",(g[r]-g[l-1]+mod)%mod);
    }
}