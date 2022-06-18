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
#define N 1000100
#define M number
using namespace std;

typedef double dd;
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

int T,n,m,c[N],dep[N],rk[N],fa[N][21],ld[N],rd[N];
int id[N],tot;

vi e[N],d[N];
set<int> s[N];

int root[N],t;

struct Node{
    int ls,rs,val;
}p[N*80];

#define ls(k) p[k].ls
#define rs(k) p[k].rs

inline void PushUp(int k){
    p[k].val=p[ls(k)].val+p[rs(k)].val;
}

inline void Change(int lst,int &k,int l,int r,int w,int x){
    k=++t;p[k]=p[lst];
    if(l==r){p[k].val+=x;return;}
    int mid=(l+r)>>1;
    if(w<=mid) Change(ls(lst),ls(k),l,mid,w,x);
    else if(w>mid) Change(rs(lst),rs(k),mid+1,r,w,x);
    PushUp(k);
}

inline int Ask(int k,int l,int r,int z,int y){
    if(l==z&&r==y) return p[k].val;
    int mid=(l+r)>>1;
    if(y<=mid) return Ask(ls(k),l,mid,z,y);
    else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
    else return Ask(ls(k),l,mid,z,mid)+Ask(rs(k),mid+1,r,mid+1,y);
}

inline void dfs(int k){
    id[k]=++tot;rk[tot]=k;
    dep[k]=dep[fa[k][0]]+1;  
    rep(i,1,20) fa[k][i]=fa[fa[k][i-1]][i-1];
    ld[k]=tot;
    d[dep[k]].pb(k);
    for(int to:e[k]){
        dfs(to);
    }
    rd[k]=tot;
}

inline int ge(int a,int b){
    // printf("a=%d b=%d\n",a,b);
    if(dep[a]<dep[b]) swap(a,b);
    // printf("fa[a][0]=%d\n",fa[a][0]);
    dec(i,0,20) if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
    // printf("a=%d\n",a);
    if(a==b) return a;
    dec(i,0,20) if(fa[a][i]!=fa[b][i]){a=fa[a][i];b=fa[b][i];}
    // printf("a=%d\n",a);
    // printf("lca=%d\n",fa[a][0]);
    return fa[a][0];
}

inline void Init(){
    read(n);read(m);rep(i,1,n) read(c[i]);
    rep(i,2,n){int f;read(f);e[f].pb(i);fa[i][0]=f;}
    dfs(1);
    rep(i,1,n){
        // printf("i=%d\n",i);
        root[i]=root[i-1];
        for(int now:d[i]){
            // printf("now=%d\n",now);
            s[c[now]].insert(id[now]);
            int nc=c[now];
            int l=0,r=0;auto it=s[nc].lower_bound(id[now]);
            
            // cout<<*it<<endl;
            auto pr=it;auto nx=it;
            if(it==s[nc].begin()) l=-1;
            if(it==--s[nc].end()) r=-1;
            if(l!=-1) l=*(--pr);
            if(r!=-1) r=*(++nx);
            // printf("l=%d r=%d\n",l,r);
            // puts("here");
            Change(root[i],root[i],1,n,id[now],1);
            // printf("%d %d %d\n",i,id[now],1);
            if(l!=-1){
                Change(root[i],root[i],1,n,id[ge(rk[l],now)],-1);
                // printf("%d %d %d\n",i,id[ge(rk[l],now)],-1);
            }
            if(r!=-1){
                Change(root[i],root[i],1,n,id[ge(now,rk[r])],-1);
                // printf("%d %d %d\n",i,id[ge(now,rk[r])],-1);
            }
            if(l!=-1&&r!=-1){
                Change(root[i],root[i],1,n,id[ge(rk[l],rk[r])],1);
                // printf("%d %d %d\n",i,id[ge(rk[l],rk[r])],1);
            }
        }
    }
    // puts("COMPLETE INTING");
    // exit(0);
}

inline void Solve(){
    int ans=0;
    rep(i,1,m){
        // printf("i=%d\n",i);
        int x,d;read(x);read(d);
        x^=ans;d^=ans;
        // printf("x=%d d=%d\n",x,d);
        // printf("ld=%d rd=%d\n",ld[x],rd[x]);
        ans=Ask(root[dep[x]+d],1,n,ld[x],rd[x]);
        printf("%d\n",ans);
    }
}

inline void Clear(){
    t=0;tot=0;rep(i,1,n) s[i].clear(),e[i].clear(),d[i].clear();
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(T);
    while(T--){
        // printf("T=%d\n",T);
        Init();Solve();Clear();
    }
    return 0;
}