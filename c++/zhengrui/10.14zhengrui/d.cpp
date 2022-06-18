#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
#define M 5010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a, T b){return a>b?a:b;}
template<typename T> inline T Min(T a, T b){return a<b?a:b;}

int n,m,pre[N],tag,vis[N],cnt[N][N];
ll dis[N],ans[N];

struct edge{
    int from,to,next,w;
    inline void Init(int fr_,int to_,int ne_,int w_){
        from=fr_;to=to_;next=ne_;w=w_;
    }
}li[M];
int head[N],tail=1;

inline void Add(int from,int to,int w){
    li[++tail].Init(from,to,head[from],w);
    head[from]=tail;cnt[from][to]++;
}

typedef pair<ll,ll> P;

priority_queue<P> q; 

void dij(int u) {
    memset(dis,INF,sizeof(dis));memset(vis,0,sizeof(vis));
    dis[u]=0;q.push(make_pair(0,u));
    while(q.size()){
        P now=q.top();q.pop();
        int k=now.second,d=now.first;
        if(vis[k]) continue;
        vis[k]=1;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(dis[to]>dis[k]+w){
                dis[to]=dis[k]+w;pre[to]=x;
                q.push(make_pair(-dis[to],to));
            }
        }
    }
}

void update(int u) {
    while(q.size())q.pop();
    memset(dis,INF,sizeof(dis));memset(vis,0,sizeof(vis));
    dis[u]=0;q.push(make_pair(0,u));
    while(q.size()){
        P now=q.top();q.pop();
        int k=now.second,d=now.first;
        if(vis[k]) continue;vis[k]=1;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to;
            if(x!=tag&&(x^1)!=tag){
                if(dis[to]>dis[k]+li[x].w){
                    dis[to]=dis[k]+li[x].w;
                    q.push(make_pair(-dis[to],to));
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
      ans[i]=Max(ans[i],dis[i]);
}

int main() {
    int st;read(n),read(m),read(st);
    for (int i=1;i<=m;++i){
        int u,v;
        ll w;read(u),read(v),read(w);
        Add(u,v,w);Add(v,u,w);
    }
    dij(st);
    for(int i=1;i<=n;++i)
      if(i!=st&&cnt[li[pre[i]].from][li[pre[i]].to]<=1)
        tag=pre[i],update(st);
    for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
    return 0;
}
