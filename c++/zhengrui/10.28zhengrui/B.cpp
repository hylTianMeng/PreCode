#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M 3000010
using namespace std;

const int INF=0x3f3f3f3f;
const int base=19260817;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[M];
int head[M],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

struct Hash{
    int head[base],val[base],tot,li[base];
    inline void Insert(int x){
        int v=x%base;
        for(int i=head[v];i;i=li[i]){
            if(val[i]==x) return;
        }
        val[++tot]=x;li[tot]=head[v];head[v]=tot;
    }
    inline int Find(int x){
        int v=x%base;
        for(int i=head[v];i;i=li[i]){
            if(val[i]==x) return i;
        }
        assert(0);
        return -1;
    }
}ha;

int n,m,v[N],xu[M],ta;

#define ID(x) ha.Find(x)

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(v[i]);
        ha.Insert(v[i]);
        xu[++ta]=v[i];
    }
    for(int i=1;i<=m;i++){
        int a,b,c;read(a);read(b);read(c);
        // printf("%d %d %d\n",b,a,c);
        ha.Insert(a);ha.Insert(b);
        Add(ID(b),ID(a),c);
        xu[++ta]=a;xu[++ta]=b;
    }
    xu[++ta]=1;ha.Insert(1);
    sort(xu+1,xu+ta+1);
    int len=unique(xu+1,xu+ta+1)-xu-1;
    for(int i=1;i<len;i++) Add(ID(xu[i]),ID(xu[i+1]),xu[i+1]-xu[i]); 
}

struct Node{
    int id,val;
    inline Node(){}
    inline Node(int id,int val) : id(id),val(val) {}
    inline bool operator < (const Node &b)const{return val>b.val;}
};
priority_queue<Node> q;

int d[M];
bool vis[M];

inline void Dij(int s){
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));
    q.push(Node(s,0));d[s]=0;
    while(q.size()){
        Node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(d[to]<=d[top.id]+w) continue;
            d[to]=d[top.id]+w;q.push(Node(to,d[to]));
        }
    }
}

inline void GetAns(){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=d[ID(v[i])];
        // printf("d[%lld]=%lld\n\n",v[i],d[ID(v[i])]);
    }
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dij(ID(1));GetAns();
    return 0;
}