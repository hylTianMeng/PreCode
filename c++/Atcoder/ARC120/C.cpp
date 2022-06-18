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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],b[N],c[N],d[N],cnt[N],tot,t,e[N];
multiset<int> S,T;
map<int,int> Map;
vi v[N];

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w){
        for(int i=w;i;i-=lowbit(i)) p[i]++;
    }
    inline int Ask(int w){
        int res=0;
        for(int i=w;i<=n;i+=lowbit(i)) res+=p[i];return res;
    }
}bit;

signed main(){
    read(n);rep(i,1,n) read(a[i]);rep(i,1,n)read(b[i]);
    rep(i,1,n) a[i]-=(n-i+1);
    rep(i,1,n) b[i]-=(n-i+1);
    rep(i,1,n) S.insert(a[i]);
    rep(i,1,n) T.insert(b[i]);
    if(S!=T){puts("-1");return 0;}
    rep(i,1,n){
        if(!Map[a[i]]) Map[a[i]]=++tot;
        v[Map[a[i]]].pb(i);
    }
    for(auto it:Map){
        for(int now:v[(it).second]) c[now]=++t;
    }
    rep(i,1,tot) v[i].clear();Map.clear();tot=t=0;
    rep(i,1,n){
        if(!Map[b[i]]) Map[b[i]]=++tot;
        v[Map[b[i]]].pb(i);
    }
    for(auto it:Map){
        for(int now:v[(it).second]) d[now]=++t;
    }
    rep(i,1,n) e[d[i]]=i;rep(i,1,n) c[i]=e[c[i]];
    ll ans=0;
    rep(i,1,n){
        ans+=bit.Ask(c[i]);bit.Add(c[i]);
    }
    printf("%lld\n",ans);
    return 0;
}