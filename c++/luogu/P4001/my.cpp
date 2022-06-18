#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
#define M N*N
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
    int to,next,flow;
    inline void Init(int to_,int ne_,int f_){
        to=to_;next=ne_;flow=f_;
    }
}li[M<<3];
int head[M],tail;

inline void Add(int from,int to,int flow){
    li[++tail].Init(to,head[from],flow);head[from]=tail;
}

int n,m,H[N][N],L[N][N],X[N][N],s,t;

inline int ID(int x,int y,bool op){
    return (x-1)*(m-1)*2+(y-1)*2+op+1;
}

inline void Init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++) read(H[i][j]);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++) read(L[i][j]);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++) read(X[i][j]);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++){
            if(j!=m-1){Add(ID(i,j,0),ID(i,j+1,1),L[i][j+1]);Add(ID(i,j+1,1),ID(i,j,0),L[i][j+1]);}
            if(i!=n-1){Add(ID(i,j,1),ID(i+1,j,0),H[i+1][j]);Add(ID(i+1,j,0),ID(i,j,1),H[i+1][j]);}
            Add(ID(i,j,0),ID(i,j,1),X[i][j]);Add(ID(i,j,1),ID(i,j,0),X[i][j]);
        }
    s=(n-1)*(m-1)*2+1;
    t=s+1;
    for(int i=1;i<=m-1;i++) {Add(ID(1,i,0),t,H[1][i]);Add(t,ID(1,i,0),H[1][i]);}
    for(int i=1;i<=n-1;i++) {Add(ID(i,m-1,0),t,L[i][m]);Add(t,ID(i,m-1,0),L[i][m]);}
    for(int i=1;i<=m-1;i++) {Add(s,ID(n-1,i,1),H[n][i]);Add(ID(n-1,i,1),s,H[n][i]);}
    for(int i=1;i<=n-1;i++) {Add(s,ID(i,1,1),L[i][1]);Add(ID(i,1,1),s,L[i][1]);}
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

inline void dij(int s){
    memset(d,INF,sizeof(d));
    q.push(Node(s,0));d[s]=0;
    while(q.size()){
        Node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].flow;
            if(d[to]<=d[top.id]+w||vis[to]) continue;
            d[to]=d[top.id]+w;q.push(Node(to,d[to]));
        }
    }
}

inline void Clear(){
    for(int i=1;i<=(n-1)*(m-1)*2+2;i++) head[i]=0;tail=0;
    for(int i=1;i<=(n-1)*(m-1)*2+2;i++) vis[i]=0;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    int cnt=0;
    while(scanf("%lld %lld",&n,&m)!=EOF&&n&&m){
        cnt++;
        Init();dij(s);printf("Case %lld: Minimum = %lld\n",cnt,d[t]);Clear();
    }
}