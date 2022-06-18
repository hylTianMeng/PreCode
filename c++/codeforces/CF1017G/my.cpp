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
#define N 100010
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

int n,m,fa[N],top[N],id[N],rk[N],son[N],siz[N],dep[N],tot,lx[N],rx[N];
vi e[N];

struct Node{
    int sum,ans;
    inline void clear(){sum=0;ans=-INF;}
    inline Node operator + (const Node &b)const{
        Node c;c.clear();
        c.sum=sum+b.sum;
        c.ans=max(b.ans,ans+b.sum);return c;
    }
};

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    int tag[N<<2],len[N<<2];
    Node p[N<<2];
    inline void C(int k,int x){
        tag[k]=x;
        p[k].ans=max(x,x*len[k]);
        p[k].sum=x*len[k];
    }
    inline void PushUp(int k){
        len[k]=len[ls(k)]+len[rs(k)];
        p[k]=p[ls(k)]+p[rs(k)];
    }
    inline void PushDown(int k){
        if(tag[k]){
            C(ls(k),tag[k]);C(rs(k),tag[k]);tag[k]=0;
        }
    }
    inline void Build(int k,int l,int r){
        if(l==r){len[k]=1;p[k].ans=p[k].sum=-1;return;}
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);
        PushUp(k);
    }
    inline void Cover(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y){C(k,x);return;}
        int mid=(l+r)>>1;PushDown(k);
        if(y<=mid) Cover(ls(k),l,mid,z,y,x);
        else if(z>mid) Cover(rs(k),mid+1,r,z,y,x);
        else{Cover(ls(k),l,mid,z,mid,x);Cover(rs(k),mid+1,r,mid+1,y,x);}
        PushUp(k);
    }
    inline void Change(int k,int l,int r,int w,int x){
        if(l==r){
            p[k].sum+=x;p[k].ans+=x;;return;
        }
        int mid=(l+r)>>1;PushDown(k);
        if(w<=mid) Change(ls(k),l,mid,w,x);
        else Change(rs(k),mid+1,r,w,x);
        PushUp(k);
    }
    inline Node Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;PushDown(k);
        if(y<=mid) return Ask(ls(k),l,mid,z,y);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
        else return Ask(ls(k),l,mid,z,mid)+Ask(rs(k),mid+1,r,mid+1,y);
    }
}tr;

inline void dfs(int k,int fat){
    dep[k]=dep[fat]+1;fa[k]=fat;siz[k]=1;
    for(int to:e[k]){
        if(to==fat) continue;
        dfs(to,k);siz[k]+=siz[to];if(siz[son[k]]<siz[to]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    top[k]=t;id[k]=++tot;rk[tot]=k;
    lx[k]=tot;
    if(son[k]) dfs2(son[k],t);
    for(int to:e[k]){
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
    rx[k]=tot;
}

inline int ge(int a,int b){
    Node now;now.clear();
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        now=tr.Ask(1,1,n,id[top[a]],id[a])+now;
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);
    now=tr.Ask(1,1,n,id[b],id[a])+now;
    return now.ans;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,2,n){int f;read(f);e[f].pb(i);e[i].pb(f);}
    dfs(1,0);dfs2(1,1);
    assert(tot==n);
    tr.Build(1,1,n);
    rep(i,1,m){
        // printf("i=%d\n",i);
        int op,x;read(op);read(x);
        if(op==1){
            tr.Change(1,1,n,id[x],1);
        }
        else if(op==2){

            tr.Cover(1,1,n,lx[x],rx[x],-1);
            tr.Change(1,1,n,id[x],-(ge(x,1)+1));
        }
        else if(op==3){
            int val=ge(x,1);
            // printf("val=%d\n",val);
            if(val>=0){
                puts("black");
            }
            else puts("white");
        }
    }
    return 0;
}