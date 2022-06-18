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
#define N 300010
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
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

int n,m;
P ans[N];
int q,fa[N],d[N],cz,ct,ch,siz[N],cnt[N],cm;

inline int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}

vector<P> e[N];
vi qu[N];

inline void Insert(int u,int v){
    int fau=Find(u),fav=Find(v);
    d[u]++;d[v]++;cm++;
    bool op1=(siz[fau]==cnt[fau]);
    bool op2=(siz[fav]==cnt[fav]);
    if(d[u]==3) ct--;
    if(d[v]==3) ct--;
    if(d[u]==2) ct++;
    if(d[v]==2) ct++;
    if(d[u]==1) cz--;
    if(d[v]==1) cz--;
    if(d[u]==3) cnt[fau]--;
    if(d[v]==3) cnt[fav]--;
    if(d[u]==2) cnt[fau]++;
    if(d[v]==2) cnt[fav]++;
    if(fau==fav){
        if(siz[fau]==cnt[fau]) ch++;
        if(op1&&siz[fau]!=cnt[fau]) ch--;
    }
    else{
        fa[fav]=fau;
        siz[fau]+=siz[fav];
        cnt[fau]+=cnt[fav];
        if(op1) ch--;if(op2) ch--;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    int maxx=-INF;
    read(n);read(m);
    rep(i,1,m){
        int from,to,w;read(from);read(to);read(w);
        e[w].pb(mp(from,to));
        maxx=max(maxx,w);
    }
    read(q);
    rep(i,1,q){
        int b;read(b);
        qu[b].pb(i);maxx=max(maxx,b);
    }
    cz=n;ct=0;ch=0;
    rep(i,1,n) fa[i]=i,siz[i]=1,cnt[i]=0;
    dec(i,0,maxx){
        for(auto now:e[i]){
            Insert(now.fi,now.se);
        }
        for(auto now:qu[i]){
            ans[now].fi=n-cz-ct+ch;
            ans[now].se=cm-ct+ch;
        }
    }
    rep(i,1,q) printf("%d %d\n",ans[i].fi,ans[i].se);
    return 0;
}