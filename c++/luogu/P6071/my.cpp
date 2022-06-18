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
#define N 800010
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

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N];
int head[N],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

namespace ST{
    #define ls(k) p[k].ls
    #define rs(k) p[k].rs
    struct Node{
        int ls,rs,val;
        inline void Print(){
            printf("ls=%d rs=%d val=%d\n",ls,rs,val);
        }
    }p[N*20];
    int root[N],tot;
    inline void PushUp(int k){p[k].val=p[ls(k)].val+p[rs(k)].val;}
    inline void Add(int lst,int &k,int l,int r,int w){
        k=++tot;p[k]=p[lst];
        if(l==r){p[k].val++;return;}
        int mid=(l+r)>>1;
        if(w<=mid) Add(ls(lst),ls(k),l,mid,w);
        else Add(rs(lst),rs(k),mid+1,r,w);PushUp(k);
    }
    inline int Merge(int a,int b,int l,int r){
        if(!a||!b) return a+b;
        int k=++tot;
        if(l==r){p[k].val=p[a].val+p[b].val;return k;}
        int mid=(l+r)>>1;
        ls(k)=Merge(ls(a),ls(b),l,mid);
        rs(k)=Merge(rs(a),rs(b),mid+1,r);PushUp(k);return k;
    }
    inline int Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k].val;
        int mid=(l+r)>>1;
        if(y<=mid) return Ask(ls(k),l,mid,z,y);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
        else return Ask(ls(k),l,mid,z,mid)+Ask(rs(k),mid+1,r,mid+1,y);
    }
    inline int Ask(int k,int l,int r){return Ask(root[k],1,n,l,r);}
    inline void dfs(int k,int fa){
        Add(root[k],root[k],1,n,k);
        // puts("0");
        // p[0].Print();
        // printf("k=%d\n",k);
        // p[root[k]].Print();
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to;
            if(to==fa) continue;
            dfs(to,k);root[k]=Merge(root[k],root[to],1,n);
            // printf("k=%d\n",k);
            // p[root[k]].Print();
        }
    }
};

int siz[N],dep[N],top[N],fa[N],son[N],d[N],ans,lca[N],id[N],rk[N],tot;

inline void dfs(int k,int fat){
    fa[k]=fat;dep[k]=dep[fat]+1;siz[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(to==fat) continue;
        d[to]=d[k]+w;
        dfs(to,k);siz[k]+=siz[to];if(siz[son[k]]<siz[to]) son[k]=to;
        
    }
}

inline void dfs2(int k,int t){
    top[k]=t;id[k]=++tot;rk[tot]=k;
    if(son[k]) dfs2(son[k],t);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
}

inline int ge(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);return b;
}

inline void Build(int k,int l,int r){
    if(l==r){lca[k]=l;return;}
    int mid=(l+r)>>1;Build(k<<1,l,mid);Build(k<<1|1,mid+1,r);
    lca[k]=ge(lca[k<<1],lca[k<<1|1]);
}

inline int ask(int k,int l,int r,int z,int y){
    if(l==z&&r==y) return lca[k];
    int mid=(l+r)>>1;
    if(y<=mid) return ask(k<<1,l,mid,z,y);
    else if(z>mid) return ask(k<<1|1,mid+1,r,z,y);
    else return ge(ask(k<<1,l,mid,z,mid),ask(k<<1|1,mid+1,r,mid+1,y));
}

inline int gef(int k,int l,int r){
    while(k){
        int val=ST::Ask(top[k],l,r);
        // printf("top[%d]=%d l=%d r=%d\n",k,top[k],l,r);
        if(val){
            int L=id[top[k]],R=id[k];
            while(L<R){
                int mid=(L+R+1)>>1;
                int nowk=rk[mid];
                // printf("nowk=%d mid=%d\n",nowk,mid);
                // printf("spe ST::Ask(3,5,5)=%d\n",ST::Ask(3,5,5));
                if(ST::Ask(nowk,l,r)) L=mid;
                else R=mid-1;
            }
            // printf("L=%d\n",L);
            return rk[L];
        }
        k=fa[top[k]];
    }
    assert(0);
}

int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);
    rep(i,1,n-1){
        int from,to,w;read(from);read(to);read(w);Add(from,to,w);Add(to,from,w);
    }
    dfs(1,0);dfs2(1,1);ST::dfs(1,0);Build(1,1,n);
    rep(i,1,m){
        int p,l,r;read(p);read(l);read(r);
        p^=ans;l^=ans;r^=ans;
        // printf("i=%d p=%d l=%d r=%d\n",i,p,l,r);
        int lc=ask(1,1,n,l,r);int nl=ge(lc,p);
        if(nl==p){
            printf("%d\n",(ans=d[lc]-d[p]));continue;
        }
        int val=ST::Ask(p,l,r);
        if(val<r-l+1&&val){
            ans=0;
            printf("0\n");continue;
        }
        // printf("val=%d\n",val);
        assert(!val);
        int f=gef(p,l,r);nl=ge(f,lc);
        // printf("f=%d\n",f);
        // printf("nl=%d lc=%d f=%d\n",nl,lc,f);
        if(nl==lc){
            printf("%d\n",(ans=d[p]-d[f]));
        }
        else if(nl==f){
            printf("%d\n",(ans=d[lc]+d[p]-2*d[f]));
        }
        else assert(0);
    }
    return 0;
}