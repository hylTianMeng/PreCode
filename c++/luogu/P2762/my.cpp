#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 210
#define M 6100
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
    int to,next,flow;
    inline void Init(int to_,int ne_,int f_){
        to=to_;next=ne_;flow=f_;
    }
}li[M];
int head[N],tail=1,now[N],Ans,NowAns;

inline void Add(int from,int to,int flow){
    li[++tail].Init(to,head[from],flow);head[from]=tail;
}

int n,m,s,t;

inline void Read(int id){
    char tools[10000];
    memset(tools,0,sizeof tools);
    cin.getline(tools,10000);
    int ulen=0,tool;
    while(sscanf(tools+ulen,"%d",&tool)==1){
        Add(id,tool+n,INF);Add(tool+n,id,0);
        if(tool==0) ulen++;
        else{while(tool){tool/=10;ulen++;}}ulen++;
    }
}

inline void Init(){
    read(n);read(m);s=n+m+1;t=s+1;
    for(int i=1;i<=n;i++){
        int x;read(x);Add(s,i,x);Add(i,s,0);Read(i);Ans+=x;
    }
    for(int i=1;i<=m;i++){
        int x;read(x);Add(i+n,t,x);Add(t,i+n,0);
    }
}

int d[N],AAA;
queue<int> q;

inline bool bfs(int s){
    memset(d,0,sizeof(d));
    while(q.size()) q.pop();
    d[s]=1;q.push(s);now[s]=head[s];
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,f=li[x].flow;
            if(!f||d[to]) continue;
            d[to]=d[top]+1;q.push(to);now[to]=head[to];
            if(to==t) return 1;
        }
    }
    if(d[t]) return 1;
    return 0;
}

inline int Dinic(int k,int flow){
    if(k==t) return flow;
    int rest=flow,x;
    for(int x=now[k];x&&rest;x=li[x].next){
        int to=li[x].to,f=li[x].flow;
        if(d[to]!=d[k]+1||!f) continue;
        int val=Dinic(to,Min(rest,f));now[k]=x;
        li[x].flow-=val;li[x^1].flow+=val;rest-=val;
    }
    return flow-rest;
}

inline void Solve(){
    // printf("LastAns=%d\n",Ans);AAA=Ans;
    while(bfs(s)){
        while((NowAns=Dinic(s,INF))) Ans-=NowAns;
    }
}

inline void Print(){
    for(int i=1;i<=n;i++) if(d[i]) printf("%d ",i);puts("");
    for(int i=n+1;i<=n+m;i++) if(d[i]) printf("%d ",i-n);puts("");
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();Print();return 0;
}