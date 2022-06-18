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
#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

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

int t,n,f[N];

struct edge{
    int to,next,x,y;
    inline void Init(int to_,int ne_,int x_,int y_){
        to=to_;next=ne_;x=x_;y=y_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to,int x,int y){
    li[++tail].Init(to,head[from],x,y);
    head[from]=tail;
}

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

inline int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int q[N],ta,Ans,a[N];

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

namespace g{
    int prime[N], p[N], cnt, mp[N], ans[N];

    void Init()
    { //素数筛
        int len = sqrt(2e5);
        for (int i = 2; i <= len; i++)
        {
            if (!prime[i])
            {
                p[++cnt] = i;
                mp[i] = cnt;
                for (ll j = 2 * i; j <= len; j += i)
                    prime[j] = 1;
            }
        }
    }
    inline void Clear(){
        rep(i,1,n) ans[i]=0;
    }

    ll quick_pow(ll a, ll b)
    { //快速幂
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    inline int getlcm()
    {
        for (int i = 1; i <= ta; i++)
        {
            int pre=q[i];
            for (int j = 1; j <= cnt && pre >= p[j]; j++)
            {
                int cur = 0;
                if (pre % p[j] == 0)
                {
                    while (pre % p[j] == 0)
                    {
                        ++cur;
                        pre /= p[j];
                    }
                }
                ans[j] = max(ans[j], cur);
            }
            if (pre > 1)
            {
                int j = 0;
                if (!mp[pre])
                {
                    p[++cnt] = pre;
                    mp[pre] = cnt;
                    j = cnt;
                }
                else
                    j = mp[pre];
                ans[j] = max(1ll, ans[j]);
            }
        }
        ll res = 1;
        for (int i = 1; i <= cnt; i++)
        {
            res *= quick_pow(p[i], ans[i]);
            res %= mod;
        }
        return res;
    }
}

inline void Clear(){
    rep(i,1,n) head[i]=0,f[i]=0;tail=0;ta=0;g::Clear();Ans=0;
}

inline void dfs2(int k,int fa){
    Ans+=f[k];Ans%=mod;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        f[to]=1ll*f[k]*ksm(li[x].x,mod-2,mod)%mod*li[x].y%mod;
        dfs2(to,k);
    }
}

inline void dfs(int k,int fa){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        q[++ta]=li[x].x;dfs(to,k);
    }
}

signed main(){
    freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);g::Init();
    while(t--){
        read(n);
        rep(i,1,n-1){
            int from,to,x,y;read(from);read(to);read(x);read(y);
            if(from>to){swap(from,to);swap(x,y);}
            Add(from,to,x,y);q[i]=y;
        }
        ta=n-1;int lcm=g::getlcm();
        Clear();
    }
    return 0;
}