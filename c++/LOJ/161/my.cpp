#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 5000100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int base=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],Pre[N],InvPre[N],Inv[N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    read(n);rep(i,1,n)read(a[i]);
    Pre[0]=1;rep(i,1,n) Pre[i]=1ll*Pre[i-1]*a[i]%mod;
    InvPre[n]=ksm(Pre[n],mod-2,mod);
    dec(i,1,n-1) InvPre[i]=1ll*InvPre[i+1]*a[i+1]%mod;
    rep(i,1,n) Inv[i]=1ll*InvPre[i]*Pre[i-1]%mod;
    int now=1,ans=0;
    dec(i,1,n){ans=(ans+1ll*now*Inv[i]%mod)%mod;now=1ll*now*base%mod;}
    // rep(i,1,n) printf("%d ",Inv[i]);puts("");
    rep(i,1,n){assert(1ll*a[i]*Inv[i]%mod==1);}
    printf("%d\n",ans);
    return 0;
}