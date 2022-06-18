#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,a[N<<1],q;
int Stack[N],top,dcc,tot,c[N],ntot,dfn[N],low[N],root,id[N<<1],rk[N<<1],idtot;
int fa[N<<1],Dep[N<<1],Top[N<<1],son[N<<1],Size[N<<1];
vector<int> vdcc[N];
bool cut[N];
vector<int> v[N<<1];
multiset<int> h[N<<1];

int p[N<<3];

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        p[k]=min(p[ls(k)],p[rs(k)]);
    }
    inline void Change(int k,int l,int r,int w,int x){
        if(l==r){p[k]=x;return;}
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls(k),l,mid,w,x);
        else Change(rs(k),mid+1,r,w,x);PushUp(k);
    }
    inline int GetMin(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;
        if(y<=mid) return GetMin(ls(k),l,mid,z,y);
        else if(z>mid) return GetMin(rs(k),mid+1,r,z,y);
        else return min(GetMin(ls(k),l,mid,z,mid),GetMin(rs(k),mid+1,r,mid+1,y));
    }
}tr;

inline void Tarjan(int k){
    int child=0;
    dfn[k]=low[k]=++tot;Stack[++top]=k;
    if(k==root&&head[k]==0){
        vdcc[++dcc].push_back(k);return;
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!dfn[to]){
            Tarjan(to);low[k]=min(low[k],low[to]);
            if(low[to]>=dfn[k]){
                child++;
                if(k!=root||child>1){c[k]=1;}
                int val;dcc++;
                do{
                    val=Stack[top--];c[val]=dcc;
                    vdcc[dcc].push_back(val);
                }while(val!=to);
                vdcc[dcc].push_back(k);
            }
        }
        else low[k]=min(low[k],dfn[to]);
    }
}

inline void dfs1(int k,int father){
    fa[k]=father;Dep[k]=Dep[father]+1;Size[k]=1;
    for(int to:v[k]){
        if(to==fa[k]) continue;
        dfs1(to,k);Size[k]+=Size[to];if(Size[son[k]]<Size[to]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    id[k]=++idtot;rk[idtot]=k;
    Top[k]=t;
    if(son[k]) dfs2(son[k],t);
    for(int to:v[k]){
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
}

inline void Build(){
    ntot=n;
    for(int i=1;i<=dcc;i++){
        ntot++;a[ntot]=INF;
        for(int k:vdcc[i]){
            v[k].push_back(ntot);v[ntot].push_back(k);
        }
    }
    dfs1(1,0);dfs2(1,1);
    for(int i=2;i<=n;i++){
        h[fa[i]].insert(a[i]);
    }
    for(int i=1;i<=n;i++){
        tr.Change(1,1,idtot,id[i],a[i]);
    }
    for(int i=n+1;i<=idtot;i++){
        tr.Change(1,1,idtot,id[i],*h[i].begin());
    }
}

inline void Change(int k,int x){
    // printf("k=%d fa[k]=%d\n",k,fa[k]);
    if(k!=1){
        assert(h[fa[k]].find(a[k])!=h[fa[k]].end());
        h[fa[k]].erase(h[fa[k]].find(a[k]));
    }
    // printf("idtot=%d id[k]=%d\n",idtot,id[k]);
    a[k]=x;tr.Change(1,1,idtot,id[k],x);
    if(k!=1){
        h[fa[k]].insert(a[k]);
        tr.Change(1,1,idtot,id[fa[k]],*h[fa[k]].begin());
    }
}

inline int AskMin(int x,int y){
    int minn=INF;
    while(Top[x]!=Top[y]){
        // printf("x=%d y=%d\n",x,y);
        if(Dep[Top[x]]<Dep[Top[y]]) swap(x,y);
        minn=min(minn,tr.GetMin(1,1,idtot,id[Top[x]],id[x]));
        // printf("nowminn=%d\n",minn);
        x=fa[Top[x]];
    }
    if(Dep[x]>Dep[y]) swap(x,y);
    minn=min(minn,tr.GetMin(1,1,idtot,id[x],id[y]));
    //a is lca
    if(x>n) minn=min(minn,a[fa[x]]);
    return minn;
}

inline char Get(){
    char c=getchar();
    for(;c!='A'&&c!='C';c=getchar());return c;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(q);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]){root=i;Tarjan(i);}
    Build();
    // for(int i=1;i<=n;i++) printf("fa[%d]=%d\n",i,fa[i]);
    for(int i=1;i<=q;i++){
        // printf("i=%d\n",i);
        char c;c=Get();int x,y;read(x);read(y);
        if(c=='C') Change(x,y);
        else printf("%d\n",AskMin(x,y));
    }
    return 0;
}