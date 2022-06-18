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
#define Next(k) for(int x=head[k];x;x=li[x].next)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 2000010
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

int n,m,fa[N],dep[N],dfn[N],low[N],sta[N],top,c[N],tot,ctot,ans[N];
string s[N];
P ve[N];
vi e[N],v[N],ee[N];
bool ins[N];

inline void dfs(int k,int fat){
    fa[k]=fat;dep[k]=dep[fat]+1;
    for(int to:e[k]){if(to==fat) continue;dfs(to,k);}
}
inline vi ge(int a,int b){
    // printf("a=%d b=%d\n",a,b);
    vi l,r;l.clear();r.clear();
    while(a!=b){
        if(dep[a]<dep[b]) r.pb(b),b=fa[b];else l.pb(a),a=fa[a];
    }
    l.pb(a);
    while(r.size()) l.pb(*(--r.end())),r.pop_back();
    // for(int now:l) printf("%d ",now);puts("");
    return l;
}
inline void Add(int a,bool o1,int b,bool o2){
    // printf("%d %d %d %d\n",2*a-o1,2*b-o2,2*b-(!o2),2*a-(!o1));
    ee[2*a-o1].pb(2*b-o2);
    ee[2*b-(!o2)].pb(2*a-(!o1));
}
inline void tarjan(int k){
    dfn[k]=low[k]=++tot;sta[++top]=k;ins[k]=1;
    for(int to:ee[k]){
        if(!dfn[to]) tarjan(to),low[k]=min(low[k],low[to]);
        else if(ins[to]) low[k]=min(low[k],dfn[to]);
    }
    if(dfn[k]==low[k]){
        ctot++;int u;do{u=sta[top--];ins[u]=0;c[u]=ctot;}while(u!=k);
    }
}
int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);rep(i,1,n-1){int from,to;read(from);read(to);e[from].pb(to);e[to].pb(from);}dfs(1,0);
    rep(i,1,m){
        int a,b;read(a);read(b);cin>>s[i];v[i]=ge(a,b);assert(v[i].size()==s[i].length());
        int len=v[i].size()-1;
        rep(j,0,(int)len) ve[v[i][j]]=mp(s[i][j],s[i][len-j]);
    }
    // rep(i,1,n){
    //     printf("%d %c %c\n",i,ve[i].fi,ve[i].se);
    // }
    rep(i,1,m){
        int len=v[i].size()-1;
        // printf("i=%d\n",i);
        rep(j,0,len){
            // printf("j=%d\n",j);
            int c=ve[v[i][j]].fi,rc=ve[v[i][j]].se;
            int d=s[i][j],rd=s[i][len-j];
            int p=v[i][j],rp=v[i][len-j];
            // printf("%c %c %c %c\n",c,rc,d,rd);
            // printf("p=%d rp=%d\n",p,rp);
            if(c!=d) Add(p,1,n+i,0);
            if(c!=rd) Add(p,1,n+i,1);
            if(rc!=d) Add(p,0,n+i,0);
            if(rc!=rd) Add(p,0,n+i,1);
        }
    }
    rep(i,1,(n+m)<<1) if(!dfn[i]) tarjan(i);
    // rep(i,1,(n+m)){
    //     printf("%d %d %d\n",i,c[i*2-1],c[i*2]);
    //     printf("%d %d\n",dfn[i],low[i]);
    // }
    rep(i,1,n+m) if(c[i*2]==c[i*2-1]) return puts("NO"),0;
    puts("YES");
    rep(i,1,n) if(c[i*2]<c[i*2-1]) ans[i]=ve[i].se;else ans[i]=ve[i].fi;
    rep(i,1,n) if(!ans[i]) ans[i]='a';
    rep(i,1,n) putchar((char)ans[i]);
    return 0;
}