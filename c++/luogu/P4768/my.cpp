#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int from,to,next,w,High;
    inline void Init(int fr_,int to_,int ne_,int w_,int h_){from=fr_;to=to_;next=ne_;w=w_;High=h_;}
    inline bool operator < (const edge &b)const{return High>b.High;}
}li[N<<2];
int head[N],tail;

inline void Add(int from,int to,int w,int High){
    li[++tail].Init(from,to,head[from],w,High);
    head[from]=tail;
}

int n,m;

struct Node{
    int ls,rs;
}p[N*40];
int tot;
int Root[N],fa[N*40],Dep[N*40],MinDis[N*40],rtt;
int Hi[N],d[N],Q,K,S;
ll Ans;
bool vis[N];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct DSU{
    inline int NewNode(){return ++tot;}
    inline void Build(int &k,int l,int r){
        k=NewNode();
        if(l==r){fa[k]=l;MinDis[k]=d[l];return;}
        int mid=(l+r)>>1;Build(ls(k),l,mid);Build(rs(k),mid+1,r);
    }
    inline int GetPosi(int k,int l,int r,int w){
        if(l==r) return k;
        int mid=(l+r)>>1;
        if(w<=mid) return GetPosi(ls(k),l,mid,w);
        else return GetPosi(rs(k),mid+1,r,w);
    }
    inline int Find(int k,int x){
        // printf("k=%lld x=%lld\n",k,x);
        int now=GetPosi(k,1,n,x);
        // printf("now=%lld\n",now);
        // printf("fa[%lld]=%lld\n",now,fa[now]);
        if(fa[now]==x) return now;
        else return Find(k,fa[now]);
    }
    inline void Change(int &k,int last,int l,int r,int w,int x){
        k=NewNode();
        p[k]=p[last];
        if(l==r){
            Dep[k]=Dep[last];fa[k]=x;MinDis[k]=MinDis[last];
            return;
        }
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls(k),ls(last),l,mid,w,x);
        else Change(rs(k),rs(last),mid+1,r,w,x);
    }
    inline void Update(int &k,int last,int l,int r,int w){
        k=NewNode();
        p[k]=p[last];
        if(l==r){MinDis[k]=MinDis[last];fa[k]=fa[last];Dep[k]=Dep[last]+1;return;}
        int mid=(l+r)>>1;
        if(w<=mid) Update(ls(k),ls(last),l,mid,w);
        else Update(rs(k),rs(last),mid+1,r,w);
    }
    inline void Update2(int &k,int last,int l,int r,int w,int x){
        k=NewNode();
        p[k]=p[last];
        if(l==r){MinDis[k]=x;fa[k]=fa[last];Dep[k]=Dep[last];return;}
        int mid=(l+r)>>1;
        if(w<=mid) Update2(ls(k),ls(last),l,mid,w,x);
        else Update2(rs(k),rs(last),mid+1,r,w,x);
    }
    inline void Merge(int &k,int last,int a,int b){
        int faa=Find(last,a),fab=Find(last,b);
        if(fa[faa]==fa[fab]) return;
        if(Dep[faa]>Dep[fab]) swap(faa,fab);
        Change(k,last,1,n,fa[faa],fa[fab]);
        if(Dep[faa]==Dep[fab]) Update(k,k,1,n,fa[fab]);
        if(MinDis[faa]<MinDis[fab]) Update2(k,k,1,n,fa[fab],MinDis[faa]);
    }
}dsu;

int t;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to,w,h;read(from);read(to);read(w);read(h);
        Add(from,to,w,h);Add(to,from,w,h);
    }
}
//over

struct node{
    int id,val;
    inline node(){}
    inline node(int id,int val) : id(id),val(val) {}
    inline bool operator < (const node &b)const{return val>b.val;}
};
priority_queue<node> q;

inline void Dij(int s){
    // printf("enter\n");
    memset(d,INF,sizeof(d));
    q.push(node(s,0));d[s]=0;
    while(q.size()){
        node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(d[to]<=d[top.id]+w) continue;
            d[to]=d[top.id]+w;
            q.push(node(to,d[to]));
        }
    }
}
//over

inline void Solve(){
    // printf("enter\n");
    dsu.Build(Root[0],1,n);
    // printf("tot=%lld\n",tot);
    sort(li+1,li+tail+1);
    // printf("now!!!\n");
    for(int i=1,j=1;i<=tail;i=j){
        // if(i>=130000) printf("i=%d\n",i);
        rtt++;int last=Root[rtt-1];Root[rtt]=Root[rtt-1];
        // printf("tot=%lld\n",tot);
        while(li[j].High==li[i].High&&j<=tail){
            dsu.Merge(Root[rtt],last,li[j].from,li[j].to);
            last=Root[rtt];j++;
        }
        Hi[rtt]=li[i].High;
    }
    // printf("tot=%lld\n",tot);
    // printf("rtt=%lld\n",rtt);
    // for(int i=1;i<=rtt;i++) printf("Hi[%lld]=%lld\n",i,Hi[i]);
    // for(int i=1;i<=rtt;i++) printf("Root[%lld]=%lld\n",i,Root[i]);
    // for(int i=1;i<=tot;i++){
    //     if(p[i].ls) printf("%lld %lld\n",i,p[i].ls);
    //     if(p[i].rs) printf("%lld %lld\n",i,p[i].rs);
    // }
    // for(int i=1;i<=tot;i++){
    //     printf("fa[%lld]=%lld\n",i,fa[i]);
    //     printf("MinDis[%lld]=%lld\n",i,MinDis[i]);
    // }
}

inline int Binary(int High){
    int l=1,r=rtt,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Hi[mid]>High){
            ans=mid;l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

inline void Clear(){
    tail=0;for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=tot;i++){fa[i]=Dep[i]=0;MinDis[i]=INF;}
    tot=0;
    for(int i=1;i<=n;i++) Root[i]=0;rtt=tail=0;
    Ans=0;for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) Hi[i]=0;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    memset(MinDis,INF,sizeof(MinDis));
    while(t--){
        // printf("here\n");
        Init();Dij(1);
        // printf("here\n");
        Solve();
        // printf("here\n");
        read(Q);read(K);read(S);
        for(int i=1;i<=Q;i++){
            // printf("i=%d\n",i);
            int V,P;read(V);read(P);
            V=(V+K*Ans-1)%n+1;
            P=(P+K*Ans)%(S+1);
            // printf("P=%lld\n",P);
            int rt=Binary(P);
            // printf("rt=%lld\n",rt);
            int now=dsu.Find(Root[rt],V);
            // printf("V=%lld\n",V);
            Ans=MinDis[now];
            printf("%lld\n",Ans);
        }
        Clear();
    }
    return 0;
}
