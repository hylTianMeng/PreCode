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
#define M 3000010
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

int n,c[N],fa[N][21],dep[N],lx[N],rx[N],tot;
vi e[N],v[N];
bool vis[N];

struct Ques{
    int l,r,x;
    inline Ques(){}
    inline Ques(int l,int r,int x) : l(l),r(r),x(x) {}
};
vector<Ques> qu[N];

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    int tag[N<<2],minn[N<<2],cnt[N<<2];
    inline void PushUp(int k){
        if(minn[ls(k)]<minn[rs(k)]){
            minn[k]=minn[ls(k)];cnt[k]=cnt[ls(k)];
        }
        else if(minn[rs(k)]<minn[ls(k)]){
            minn[k]=minn[rs(k)];cnt[k]=cnt[rs(k)];
        }
        else{
            minn[k]=minn[ls(k)];cnt[k]=cnt[ls(k)]+cnt[rs(k)];
        }
    }
    inline void Build(int k,int l,int r){
        if(l==r){cnt[k]=1;return;}
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);
        PushUp(k);
    }
    inline void A(int k,int x){
        tag[k]+=x;minn[k]+=x;
    }
    inline void PushDown(int k){
        if(tag[k]){
            A(ls(k),tag[k]);A(rs(k),tag[k]);tag[k]=0;
        }
    }
    inline void Change(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y){A(k,x);return;}
        int mid=(l+r)>>1;PushDown(k);
        if(y<=mid) Change(ls(k),l,mid,z,y,x);
        else if(z>mid) Change(rs(k),mid+1,r,z,y,x);
        else{Change(ls(k),l,mid,z,mid,x);Change(rs(k),mid+1,r,mid+1,y,x);}
        PushUp(k);
    }
    inline int GetAns(){
        if(minn[1]==0) return n-cnt[1];else return 0;
    }
}tr;

inline void Add(int l,int r,int z,int y){
    // printf("l=%d r=%d z=%d y=%d\n",l,r,z,y);
    qu[l].pb(Ques(z,y,1));qu[r+1].pb(Ques(z,y,-1));
    qu[z].pb(Ques(l,r,1));qu[y+1].pb(Ques(l,r,-1));
}

inline void dfs(int k,int fat){
    lx[k]=++tot;
    // printf("lx[%d]=%d\n",k,lx[k]);
    fa[k][0]=fat;rep(i,1,20) fa[k][i]=fa[fa[k][i-1]][i-1];dep[k]=dep[fat]+1;
    for(int to:e[k]){
        if(to==fat) continue;dfs(to,k);
    }
    rx[k]=tot;
}

inline int ge(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    dec(i,0,20) if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
    if(a==b) return a;
    dec(i,0,20) if(fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];return fa[a][0];
}

inline void Insert(int a,int b){
    int lc=ge(a,b);
    if(lc!=a&&lc!=b){Add(lx[a],rx[a],lx[b],rx[b]);}
    else{
        if(lc==a) swap(a,b);
        int nt=-1;
        for(int to:e[b]) if(ge(to,a)==to&&to!=fa[b][0]){nt=to;break;}
        // printf("a=%d b=%d nt=%d\n",a,b,nt);
        // printf("lx=%d rx=%d\n",lx[nt],rx[nt]);
        int nl=lx[nt],nr=rx[nt];
        P q1=mp(1,nl-1),q2=mp(nr+1,n);
        if(q1.fi<=q1.se) Add(lx[a],rx[a],q1.fi,q1.se);
        if(q2.fi<=q2.se) Add(lx[a],rx[a],q2.fi,q2.se);
    }
}

inline void PreWork(){
    read(n);rep(i,1,n)read(c[i]),v[c[i]].pb(i);
    rep(i,1,n-1){int from,to;read(from);read(to);e[from].pb(to);e[to].pb(from);}
    dfs(1,0);
    rep(i,1,n){
        if(vis[c[i]]) continue;
        vis[c[i]]=1;
        rep(j,0,(int)v[c[i]].size()-1)
            rep(k,j,(int)v[c[i]].size()-1){
                if(j==k) continue;Insert(v[c[i]][j],v[c[i]][k]);
            }
    }
    tr.Build(1,1,n);
}

inline void Solve(){
    int ans=0;
    rep(i,1,n+1){
        ans+=tr.GetAns();
        // printf("nowans=%d\n",tr.GetAns());
        for(auto now:qu[i]){
            tr.Change(1,1,n,now.l,now.r,now.x);
        }
    }
    // printf("ans=%d\n",ans);
    ans=(n*n+n-ans)/2;
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();Solve();
    return 0;
}