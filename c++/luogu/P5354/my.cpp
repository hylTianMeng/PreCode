#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ull*(a)*(b)%mod
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
// #define int long long
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

ull n,m,K,id[N],rk[N],tot,son[N],siz[N],dep[N],fa[N],top[N];
vi e[N];

ull a[N],b[N];

inline void dfs(int k,int f){
    fa[k]=f;dep[k]=dep[f]+1;siz[k]=1;
    for(int to:e[k]){
        if(to==f) continue;
        dfs(to,k);
        siz[k]+=siz[to];if(siz[to]>siz[son[k]]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    top[k]=t;id[k]=++tot;rk[tot]=k;
    if(son[k]) dfs2(son[k],t);
    for(int to:e[k]){
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
}

struct Node{
    ull a[2];
    inline void Clear(){a[0]=0;a[1]=-1;}
    inline Node operator + (const Node &b)const{
        Node c;c.Clear();
        c.a[0]=(a[0]&b.a[1])|((~a[0])&b.a[0]);
        c.a[1]=(a[1]&b.a[1])|((~a[1])&b.a[0]);return c;
    }
    inline void Print(){
        // printf("%llu %llu\n",a[0],a[1]);
        cout<<a[0]<<' '<<a[1]<<endl;
    }
};

Node st[N];
int t;

#define ls(k) k<<1
#define rs(k) k<<1|1
struct Segment{
    Node p[N<<2],q[N<<2];
    inline void PushUp(int k){
        p[k]=p[ls(k)]+p[rs(k)];
        q[k]=q[rs(k)]+q[ls(k)];
    }
    inline void Build(int k,int l,int r){
        if(l==r){
            if(a[rk[l]]==1) p[k].a[0]=0,p[k].a[1]=b[rk[l]];
            else if(a[rk[l]]==2) p[k].a[0]=b[rk[l]],p[k].a[1]=-1;
            else if(a[rk[l]]==3) p[k].a[0]=b[rk[l]],p[k].a[1]=(-1ull)^b[rk[l]];
            q[k]=p[k];
            return;
        }
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);PushUp(k);
    }
    inline void Change(int k,int l,int r,int w,ull x,ull y){
        if(l==r){
            if(x==1) p[k].a[0]=0,p[k].a[1]=y;
            else if(x==2) p[k].a[0]=y,p[k].a[1]=-1;
            else if(x==3) p[k].a[0]=y,p[k].a[1]=(-1ull)^y;
            q[k]=p[k];
            return;
        }
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls(k),l,mid,w,x,y);
        else if(w>mid) Change(rs(k),mid+1,r,w,x,y);
        PushUp(k);
    }
    inline Node Ask(int k,int l,int r,int z,int y,bool op){
        if(l==z&&r==y) return (op==1)?p[k]:q[k];
        int mid=(l+r)>>1;
        if(y<=mid) return Ask(ls(k),l,mid,z,y,op);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y,op);
        else{
            if(op) return Ask(ls(k),l,mid,z,mid,op)+Ask(rs(k),mid+1,r,mid+1,y,op);
            else return Ask(rs(k),mid+1,r,mid+1,y,op)+Ask(ls(k),l,mid,z,mid,op);
        }
    }
}tr;

inline void Ask(int a,int b,ull z){
    t=0;Node nowans;nowans.Clear();
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]){
            Node now=tr.Ask(1,1,n,id[top[b]],id[b],1);
            st[++t]=now;
            b=fa[top[b]];
        }
        else{
            Node now=tr.Ask(1,1,n,id[top[a]],id[a],0);
            nowans=nowans+now;
            a=fa[top[a]];
        }
    }
    if(dep[a]<dep[b]){
        Node now=tr.Ask(1,1,n,id[a],id[b],1);
        st[++t]=now;
    }
    else{
        Node now=tr.Ask(1,1,n,id[b],id[a],0);
        nowans=nowans+now;
        // now.Print();
    }
    dec(i,1,t) nowans=nowans+st[i];
    // printf("Print\n");
    // nowans.Print();
    ull ans=0,s=0;
    dec(i,0,K-1){
        // printf("i=%d\n",i);
        // printf("ans=%llu s=%llu\n",ans,s);
        if((nowans.a[0]>>i)&1){ans+=(1ull<<i);continue;}
        if(s+(1ull<<i)>z) continue;
        if((nowans.a[1]>>i)&1){ans+=(1ull<<i);s+=(1ull<<i);continue;}
    }
    printf("%llu\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(K);
    rep(i,1,n){
        read(a[i]);read(b[i]);
    }
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    dfs(1,0);dfs2(1,1);
    tr.Build(1,1,n);

    rep(i,1,m){
        int op;
        ull x,y,z;
        read(op);read(x);read(y);read(z);
        if(op==2){
            tr.Change(1,1,n,id[x],y,z);
        }
        else{
            Ask(x,y,z);
        }
    }
    return 0;
}