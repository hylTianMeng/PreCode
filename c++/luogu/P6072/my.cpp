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
#define N 4000100
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

struct Trie{
    int a,b,Ans,ch[N][2],en[N],tot;
    vi v;
    inline Trie(){tot=1;Ans=0;a=-1;b=-1;}
    inline P GetPoint(){return mp(a,b);}
    inline int GetAns(){return Ans;}
    inline void Insert(int x,int id){
        // printf("Insert %d %d\n",x,id);
        int p=1;dec(i,0,30){int c=(x>>i)&1;if(!ch[p][c]) ch[p][c]=++tot;p=ch[p][c];}en[p]=id;v.pb(p);
        p=1;int nowans=0;dec(i,0,30){int c=(x>>i)&1;if(ch[p][c^1]){nowans+=(1<<i);p=ch[p][c^1];}else p=ch[p][c];}
        // printf("%d\n",nowans);
        if(nowans>=Ans){Ans=nowans;a=id;b=en[p];}
    }
    inline void Clear(){
        Ans=0;a=-1;b=-1;for(int now:v) en[now]=0;v.clear();
        rep(i,1,tot) ch[i][0]=ch[i][1]=0;tot=1;
    }
}tr;

int n;

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N];
int head[N],tail;

int fa[N][21],ans,f[N],g[N],a[N],dep[N];
P np;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

inline void dfsi(int k,int fat){
    fa[k][0]=fat;rep(i,1,20) fa[k][i]=fa[fa[k][i-1]][i-1];
    dep[k]=dep[fat]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(to==fat) continue;
        a[to]=a[k]^w;dfsi(to,k);
    }
}

inline void dfs(int k,int fat){
    tr.Insert(a[k],k);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);
    }
}

inline int ge(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    dec(i,0,20) if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
    if(a==b) return a;
    dec(i,0,20) if(fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}

inline void dfsx(int k,int fa,int u){
    // printf("k=%d fa=%d u=%d\n",k,fa,u);
    if(k==u) return;
    int nt;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        if(ge(to,u)!=to) continue;
        nt=to;
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==nt||to==fa) continue;
        dfs(to,k);
    }
    tr.Insert(a[k],k);
    f[nt]=tr.GetAns();
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==nt){
            dfsx(to,k,u);
        }
    }
}

namespace s1{
    inline void Solve(){
        tr.Clear();
        rep(i,1,n){
            if(ge(i,np.fi)!=i&&ge(i,np.se)!=i){
                f[i]=ans;
                // printf("First:f[%d]=%d\n",i,f[i]);
            }
        }
        // puts("HERE");
        tr.Clear();dfsx(1,0,np.fi);
        tr.Clear();dfsx(1,0,np.se);
        // printf("HERE|N");
        // rep(i,1,n) printf("f[%d]=%d\n",i,f[i]);
        tr.Clear();
    }
}

namespace s2{
    inline void Solve(){
        tr.Clear();
        int nl=ge(np.fi,np.se);
        int lc=nl;
        while(nl){
            g[nl]=ans;
            nl=fa[nl][0];
        }
        int u=np.fi,v=np.se;
        // exit(0);
        while(u){
            // printf("u=%d\n",u);
            for(int x=head[u];x;x=li[x].next){
                int to=li[x].to;
                if(fa[u][0]==to) continue;
                if(ge(to,np.fi)==to) continue;
                dfs(to,u);g[to]=tr.GetAns();
                tr.Clear();
            }
            u=fa[u][0];
        }
        // exit(0);
        while(v!=lc){
            for(int x=head[v];x;x=li[x].next){
                int to=li[x].to;
                if(fa[v][0]==to) continue;
                if(ge(to,np.se)==to) continue;
                dfs(to,v);g[to]=tr.GetAns();
                tr.Clear();
            }
            v=fa[v][0];
        }
        u=np.fi;v=np.se;
        // exit(0);
        while(u){
            for(int x=head[u];x;x=li[x].next){
                int to=li[x].to;
                if(fa[u][0]==to) continue;
                if(ge(to,np.fi)==to) continue;
                dfs(to,u);
            }
            tr.Insert(a[u],u);
            g[u]=tr.GetAns();
            u=fa[u][0];
        }
        tr.Clear();
        while(v!=lc){
            for(int x=head[v];x;x=li[x].next){
                int to=li[x].to;
                if(fa[v][0]==to) continue;
                if(ge(to,np.se)==to) continue;
                dfs(to,v);
            }
            tr.Insert(a[v],v);
            g[v]=tr.GetAns();
            v=fa[v][0];
        }
        tr.Clear();
        // rep(i,1,n) printf("g[%d]=%d\n",i,g[i]);
    }
}

inline void Solve(){
    int Ans=0;
    rep(i,2,n){
        cmax(Ans,f[i]+g[i]);
    }
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n-1){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
    // puts("COMPLETE INTING");
    dfsi(1,0);dfs(1,0);
    // puts("HERE");
    np=tr.GetPoint();ans=tr.GetAns();
    // printf("%d %d %d\n",np.fi,np.se,ans);
    s1::Solve();
    // exit(0);
    s2::Solve();
    // exit(0);
    Solve();
    return 0;
}