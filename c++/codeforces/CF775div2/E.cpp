#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 200010
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

#define int long long

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,s[N],t[N],cnt[N],ans,jie[N],invjie[N];

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w,int x){
        for(int i=w;i<=200000;i+=lowbit(i)) (p[i]+=x)%=mod;
    }
    inline int Ask(int w){
        int res=0;
        for(int i=w;i;i-=lowbit(i)) (res+=p[i])%=mod;
        return res;
    }
}bit;

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n){
        read(s[i]);bit.Add(s[i],1);cnt[s[i]]++;
    }
    jie[0]=1;rep(i,1,200000)jie[i]=1ll*jie[i-1]*i%mod;
    rep(i,0,200000) invjie[i]=ksm(jie[i],mod-2,mod);
    int nowans=1;
    rep(i,1,200000) nowans=1ll*nowans*invjie[cnt[i]]%mod;
    rep(i,1,m)read(t[i]);
    // cout<<bit.Ask(4)<<endl;;
    int nowc=1;
    rep(i,0,min(n,m)){
        // printf("i=%d\n",i);
        int now=0;
        if(i==m) break;
        if(i!=m) now=bit.Ask(t[i+1]-1);
        // printf("now=%d\n",now);
        now=1ll*now*jie[n-i-1]%mod*nowc%mod;
        // if(n>m) now=1ll*now*invjie[n-m]%mod;
        ans=inc(ans,now);
        if(i==m) break;
        if(!cnt[t[i+1]]) break;
        // printf("ans=%d\n",ans);
        nowc=1ll*nowc*cnt[t[i+1]]%mod;
        bit.Add(t[i+1],-1);cnt[t[i+1]]--;
    }
    rep(i,1,n)cnt[s[i]]=0;
    rep(i,1,n)cnt[s[i]]++;
    bool op=1;
    rep(i,1,n){
        if(!cnt[t[i]]){op=0;break;}
        cnt[t[i]]--;
    }
    // printf("op=%d\n",op);
    if(op&&n<m) ans=inc(ans,nowc);
    printf("%lld\n",1ll*ans*nowans%mod);
    return 0;
}