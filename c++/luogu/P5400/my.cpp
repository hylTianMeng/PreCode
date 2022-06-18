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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int n,m,l,k;
int inv[N],c[N],len,pn[N],pm[N],pl[N],a[N],Pre[N],InvPre[N],t;
int g[N],Ans;

inline void PreWork(){
    read(n);read(m);read(l);read(k);
    len=min(n,min(m,l));
    inv[1]=1;rep(i,2,len) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    c[k]=1;rep(i,k+1,len) c[i]=1ll*c[i-1]*i%mod*inv[i-k]%mod;
    pn[0]=pm[0]=pl[0]=1;
    rep(i,1,len){
        pn[i]=1ll*pn[i-1]*(n-i+1)%mod;
        pm[i]=1ll*pm[i-1]*(m-i+1)%mod;
        pl[i]=1ll*pl[i-1]*(l-i+1)%mod;
    }
    rep(i,1,len) a[i]=(1ll*n*m%mod*l%mod-1ll*(n-i)*(m-i)%mod*(l-i)%mod)%mod;
    Pre[0]=1;rep(i,1,len) Pre[i]=1ll*Pre[i-1]*a[i]%mod;
    InvPre[len]=ksm(Pre[len],mod-2,mod);
    dec(i,1,len-1) InvPre[i]=1ll*InvPre[i+1]*a[i+1]%mod;
}
 inline int sgn(int k){if(k&1)return mod-1;else return 1;}

inline void Solve(){
    Ans=0;
    rep(i,k,len) g[i]=1ll*pn[i]*pm[i]%mod*pl[i]%mod*InvPre[i]%mod;
    rep(i,k,len) Ans=(Ans+1ll*c[i]*sgn(i-k)%mod*g[i]%mod)%mod;
    printf("%d\n",(Ans+mod)%mod);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        PreWork();
        Solve();
    }
    return 0;
}