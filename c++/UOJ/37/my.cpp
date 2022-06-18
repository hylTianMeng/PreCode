#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(mod-1):1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 20
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
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,all[1<<N],dp[1<<N],f[1<<N],p[1<<N],cross[1<<N],tn,cnt[1<<N],Pow[N*N],fun[1<<N];
int in[N],out[N];

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,m){
        int from,to;read(from);read(to);
        from--;to--;out[from]|=(1<<to);in[to]|=(1<<from);
    }
    tn=(1<<n)-1;
    for (int i = 0; i < n; ++i) fun[1 << i] = i;
    Pow[0]=1;for (int  i = 1; i <= n * n; ++i) Pow[i] = Pow[i - 1] * 2 % mod;
    for (int S = 1; S <= tn; ++S) cnt[S] = cnt[S >> 1] + (S & 1);
    dp[0]=all[0]=1;p[0]=mod-1;
    rep(S,1,tn){
        if(cnt[S]==1){p[S]=all[S]=dp[S]=1;continue;}
        int tmp=0;
        rep(j,0,n-1) if((S>>j)&1) tmp+=cnt[S&out[j]];
        dp[S]=all[S]=Pow[tmp];
        // printf("tmp=%d\n",tmp);
        int rem=S-((S&(-S)));
        for(int i=rem;;i=(i-1)&rem){
            int t=i|(S&(-S));
            if(t<S) (p[S]+=mod-1ll*dp[t]*p[S-t]%mod)%=mod;
            if(!i) break;
        }
        for(int T=S;T;T=(T-1)&S){
            if(T==S) cross[T]=0;
            else{
                int t=fun[(S-T)&(T-S)];
                // printf("t=%d\n",t);
                cross[T]=cross[T+(1<<t)]+cnt[in[t]&T]-cnt[out[t]&(S-T-(1<<t))];
                // printf("%d %d %d\n",cross[T+(1<<t)],cnt[in[t]&T],cnt[out[t]&(S-T-(1<<t))]);
                // printf("t=%d in[t]=%d cnt=%d\n",t,in[t],cnt[in[t]&T]);
            }
            (dp[S]+=mod-1ll*p[T]*all[S-T]%mod*Pow[cross[T]]%mod)%=mod;
            // printf("p[%d]=%d all[%d]=%d cross[%d]=%d\n",T,p[T],S-T,all[S-T],T,cross[T]);
            // printf("dp[%d]=%d\n",S,dp[S]);
        }
        (p[S]+=dp[S])%=mod;
        // printf("S=%d dp[s]=%d all[s]=%d p[s]=%d\n",S,dp[S],all[S],p[S]);
    }
    printf("%lld\n",dp[tn]);
}