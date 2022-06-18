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
#define N 500010
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

int n,m,fa[N],dep[N],siz[N],c[N],maxx[N],ans[N];
vector<P> e[N];
vi col;
set<int> s[N];
vector<P> v[N];

struct Ques{
    P x;int id;
}a[N];

inline void dfs(int k,int fat){
    fa[k]=fat;dep[k]=dep[fat]+1;siz[k]=1;
    for(P to:e[k]){if(to.fi==fat) continue;c[to.fi]=c[k]+to.se;dfs(to.fi,k);siz[k]+=siz[to.fi];}
}

inline int getid(int c){
    return lower_bound(col.begin(),col.end(),c)-col.begin()+1;
}

inline void Merge(int id,int a,int b){
    if(s[a].size()<s[b].size()) swap(s[a],s[b]);
    for(auto x:s[b]){
        auto now=s[a].lower_bound(x);
        if(now!=s[a].end()){
            v[*now].pb(mp(id,x));
        }
        now=s[a].upper_bound(x);
        if(now!=s[a].begin()){
            now--;v[x].pb(mp(id,*now));
        }
    }
    while(s[b].size()){
        s[a].insert(*s[b].begin());
        s[b].erase(s[b].begin());
    }
}

inline void dfs2(int k){
    for(P to:e[k]){
        if(to.fi==fa[k]) continue;dfs2(to.fi);
    }
    int id=getid(c[k]);v[k].pb(mp(id,k));
    s[k].insert(k);
    for(P to:e[k]){
        if(to.fi==fa[k]) continue;
        // printf("Merge(id=%d k=%d to.fi=%d)\n",id,k,to.fi);
        Merge(id,k,to.fi);
    }
}

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w,int x){
        for(int i=w;i;i-=lowbit(i)) p[i]+=x;
    }
    inline int Ask(int w){
        int res=0;for(int i=w;i<=n;i+=lowbit(i)) res+=p[i];
        return res;
    }
}bit;

inline bool cmp(Ques a,Ques b){return a.x.se<b.x.se;}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n-1){
        int from,to,w;read(from);read(to);read(w);e[from].pb(mp(to,w));e[to].pb(mp(from,w));
    }
    dfs(1,0);
    rep(i,1,n) col.pb(c[i]);
    sort(col.begin(),col.end());col.erase(unique(col.begin(),col.end()),col.end());
    // for(int now:col){
    //     printf("%d ",now);
    // }puts("");
    dfs2(1);
    // rep(i,1,n){
    //     printf("r=%d siz=%d\n",i,v[i].size());
    //     for(auto now:v[i]){
    //         printf("id=%d l=%d\n",now.fi,now.se);
    //     }
    //     puts("---------------------");
    // }
    rep(i,1,m) read(a[i].x.fi),read(a[i].x.se),a[i].id=i;
    sort(a+1,a+m+1,cmp);
    int r=0;
    rep(i,1,m){
        while(r+1<=a[i].x.se){
            r++;
            // printf("r=%d\n",r);
            for(P now:v[r]){
                // printf("id=%d l=%d\n",now.fi,now.se);
                if(maxx[now.fi]){
                    bit.Add(maxx[now.fi],-1);
                    // printf("1 %d -1\n",maxx[now.fi]);
                }
                maxx[now.fi]=max(maxx[now.fi],now.se);
                bit.Add(maxx[now.fi],1);
                // printf("1 %d 1\n",maxx[now.fi]);
            }
        }
        ans[a[i].id]=bit.Ask(a[i].x.fi);
    }
    rep(i,1,m) printf("%lld\n",ans[i]);
    return 0;
}