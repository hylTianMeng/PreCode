#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10010
#define M 500010
using namespace std;

const int INF=0x3f3f3f3f;
const dd eps=1e-5;

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
}li[M<<1];
int head[N],tail;
int c,I,t,n,m;

dd d[N],TimeLimit[N];
bool vis[N];

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
    read(c);read(I);read(t);
    fill(TimeLimit+1,TimeLimit+n+1,INF);
}

dd l=0,r=1000001;

struct Node{
    int id;
    dd val;
    inline Node(){}
    inline Node(int id,dd val) : id(id),val(val) {}
    inline bool operator < (const Node &b)const{
        return val>b.val;
    }
};
priority_queue<Node> q;

inline void Dij(int s,dd v){
    fill(d+1,d+n+1,INF);
    fill(vis+1,vis+n+1,0);
    if(TimeLimit[s]<=0) return;
    q.push(Node(s,0));d[s]=0;
    while(q.size()){
        Node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to;
            dd w=(dd)li[x].w/v;
            if(d[to]<=d[top.id]+w||TimeLimit[to]<=d[top.id]+w) continue;
            d[to]=d[top.id]+w;q.push(Node(to,d[to]));
        }
    }
}

inline bool Check(dd mid){
    Dij(c,mid);return d[t]!=INF;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dij(I,1);
    for(int i=1;i<=n;i++) TimeLimit[i]=d[i];
    // printf("if=%d\n",Check(0.6));
    while(r-l>eps){
        dd mid=(l+r)/2;
        if(Check(mid)){
            // printf("r=%lf\n",r);
            r=mid;
        }
        else l=mid;
    }
    if(l>=1000000){return puts("-1"),0;}
    else printf("%lf\n",l);
    return 0;
}