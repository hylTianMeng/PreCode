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
#define N 3010
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,K;

struct Bag{
    int a[N];
    inline void Clear(){mset(a,0);}
    inline void Insert(int k,int x){
        dec(i,0,K-k){
            cmax(a[i+k],a[i]+x);
        }
    }
};

int a[N],b[N],ans;
vi v[N];

inline void dfs(int l,int r,Bag lst){
    if(l==r){
        ans=cmax(ans,lst.a[K]);
        for(int i=1;i<=a[l]&&i<=K;i++) ans=max(ans,v[l][i]+lst.a[K-i]);
        return;
    }
    int mid=(l+r)>>1;
    Bag now;
    now.Clear();now=lst;rep(i,mid+1,r) now.Insert(a[i],b[i]);
    dfs(l,mid,now);
    now.Clear();now=lst;rep(i,l,mid) now.Insert(a[i],b[i]);
    dfs(mid+1,r,now);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(K);
    rep(i,1,n){
        int len;read(len);
        v[i].push_back(0);
        rep(j,1,len){
            int x;read(x);
            v[i].pb(v[i][(int)v[i].size()-1]+x);
        }
        a[i]=len;b[i]=v[i][(int)v[i].size()-1];
    }
    Bag now;now.Clear();
    dfs(1,n,now);
    printf("%lld\n",ans);
    return 0;
}