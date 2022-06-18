#include<bits/stdc++.h>
#define dd double
#define ld long double
// #define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct node{
    int val,id;
    inline node(){}
    inline node(int val,int id) : val(val),id(id) {}
    inline bool operator < (const node &b)const{
        if(val!=b.val) return val>b.val;
        return id>b.id;
    }
};
priority_queue<node> q;

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N<<1];
int head[N<<1],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

int n,m,k,a[N],f[N][M<<1];

inline void Init(){
    read(n);read(m);read(k);
    for(int i=1;i<=m;i++){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
    memset(f,INF,sizeof(f));
    for(int i=1;i<=k;i++){
        read(a[i]);f[a[i]][1<<(i-1)]=0;
    }
}

bool vis[N];
inline void dij(int s){
    memset(vis,0,sizeof(vis));
    while(q.size()){
        node top=q.top();q.pop();
        if(vis[top.id]) continue;
        vis[top.id]=1;
        for(int x=head[top.id];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(f[to][s]<f[top.id][s]+w) continue;
            f[to][s]=f[top.id][s]+w;
            q.push(node(f[to][s],to));
        }
    }
}

inline void Dp(){
    for(int s=1;s<=(1<<k)-1;s++){
        for(int i=1;i<=n;i++){
            for(int sub=s&(s-1);sub;sub=s&(sub-1)){
                f[i][s]=Min(f[i][s],f[i][sub]+f[i][s^sub]);
            }
            if(f[i][s]!=INF) q.push(node(f[i][s],i));
            vis[i]=0;
            // printf("before:f[%d][%d]=%d\n",i,s,f[i][s]);
        }
        dij(s);
        // for(int i=1;i<=n;i++){
        //     printf("f[%d][%d]=%d\n",i,s,f[i][s]);
        // }
    }
    printf("%d\n",f[a[1]][(1<<k)-1]);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dp();
}
/*
6781325
*/