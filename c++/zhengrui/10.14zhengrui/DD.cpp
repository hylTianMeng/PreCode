#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000010
#define M 2000100
using namespace std;

const int INF=1e17;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Node{
    int id,dis;
    inline Node(){}
    inline Node(int id,int dis) : id(id),dis(dis) {}
    inline bool operator < (const Node &b)const{return dis>b.dis;}
};
priority_queue<Node> q;

struct edge{
    int from,to,next,w,val;bool tag;
    inline void Init(int fr_,int to_,int ne_,int w_){
        from=fr_;to=to_;next=ne_;w=w_;
    }
    inline bool operator < (const edge &b)const{return val<b.val;}
}li[M<<1],li2[M<<1];
int head[N],tail,t2;

inline void Add(int from,int to,int w){
    li[++tail].Init(from,to,head[from],w);
    head[from]=tail;
}

int n,m,d[N],u,fath[N],Deep[N],fa[N],f[N],val[N];
bool vis[N],visit[N];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

inline void Init(){
    read(n);read(m);read(u);
    for(int i=1;i<=m;i++){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
}

inline void Dij(int s){
    fill(d+1,d+n+1,INF);
    q.push(Node(s,0));d[s]=0;
    while(q.size()){
        Node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(d[to]>d[top.id]+w){d[to]=d[top.id]+w;q.push(Node(to,d[to]));}
        }
    }
}

inline void dfs(int k,int father){
    visit[k]=1;
    fath[k]=father;Deep[k]=Deep[father]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(visit[to]||to==father||d[to]!=d[k]+w) continue;
        li[x].tag=1;dfs(to,k);
    }
}

inline void Signed(int from,int to,int w){
    if(!Deep[from]||!Deep[to]) return;
    int a=Find(from),b=Find(to);
    while(a!=b){
        if(Deep[a]<Deep[b]) swap(a,b);
        val[a]=w;fa[a]=fath[a];a=Find(a);
    }
}

inline void GetF(int s){
    fill(f+1,f+n+1,INF);fill(vis+1,vis+n+1,0);
    q.push(Node(s,0));f[s]=0;
    while(q.size()){
        Node top=q.top();q.pop();
        // printf("top.id=%lld\n",top.id);
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            // printf("to=%lld\n",to);
            if(!vis[to]&&f[to]>Max(val[to],f[top.id]+w)){
                f[to]=Max(val[to],f[top.id]+w);
                q.push(Node(to,f[to]));
            }
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dij(u);dfs(u,0);
    for(int i=1;i<=tail;i+=2){
        if(li[i].tag||li[i+1].tag) continue;
        li2[++t2]=li[i];li2[t2].val=d[li[i].to]+d[li[i+1].to]+li[i].w;
    }
    sort(li2+1,li2+t2+1);for(int i=1;i<=n;i++) fa[i]=i;
    // printf("t2=%lld\n",t2);
    // for(int i=1;i<=t2;i++) printf("from=%lld to=%lld val=%lld\n",li2[i].from,li2[i].to,li2[i].val);
    fill(val+1,val+n+1,INF);
    for(int i=1;i<=t2;i++) Signed(li2[i].from,li2[i].to,li2[i].val);
    for(int i=1;i<=n;i++) val[i]-=d[i];GetF(u);
    for(int i=1;i<=n;i++){
        if(f[i]>INF/10) printf("-1 ");
        else printf("%lld ",f[i]);
    }
    // puts("");
    // for(int i=1;i<=n;i++) printf("val[%lld]=%lld\n",i,val[i]);
    return 0;
}