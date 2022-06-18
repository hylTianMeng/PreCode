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

P a[N];
int R,c,n,K,nans;
vector<int> f[N];
int cnt[N],l[N],r[N],tail,ans;
P b[N];

inline void dfs(int x,int k){
    nans-=b[x].se*cnt[x];
    nans+=b[l[x]].se*cnt[x];
    if(l[x]&&k-1>0) dfs(l[x],k-1);
    if(l[x]) cnt[l[x]]+=cnt[x];
    cnt[x]=0;
}

inline bool cmp(P a,P b){
    return a.se<b.se||(a.se==b.se&&a.fi<b.fi);
}

signed main(){
    read(R);read(c);read(n);read(K);
    rep(i,1,n){read(a[i].fi);read(a[i].se);}
    sort(a+1,a+n+1,cmp);
    rep(i,1,R){
        rep(j,1,R) f[j].clear();
        tail=0;
        rep(j,1,n){
            if(a[j].fi>=i){
                b[++tail]=a[j];
                l[tail]=tail-1;r[tail]=tail+1;
                f[b[tail].fi].pb(tail);
                cnt[tail]=0;
            }
        }
        nans=0;
        for(int j=1,k=0;j<=c;j++){
            while(k+1<=tail&&b[k+1].se<=j) k++;
            if(k-K+1>0) cnt[k-K+1]++,nans+=b[k-K+1].se;
        }
        ans=ans+nans;
        dec(j,i+1,R){
            for(int nw:f[j]){
                dfs(nw,K);r[l[nw]]=r[nw];l[r[nw]]=l[nw];
            }
            ans=ans+nans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}