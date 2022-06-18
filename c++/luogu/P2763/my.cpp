#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20000
#define M 21
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
    int to,next,f;
    inline void Init(int to_,int ne_,int f_){
        to=to_;next=ne_;f=f_;
    }
}li[N];
int head[N],tail=1,now[N];
vector<int> v[M];

inline void Add(int from,int to,int f){
    li[++tail].Init(to,head[from],f);head[from]=tail;
}

int k,n,s,t,Ans,NowAns;

inline void Init(){
    read(k);read(n);
    s=k+n+1;t=s+1;
    for(int i=1;i<=k;i++){
        int x;read(x);Add(n+i,t,x);Add(t,n+i,0);Ans+=x;
    }
    for(int i=1;i<=n;i++){
        int x;read(x);
        for(int j=1;j<=x;j++){
            int a;read(a);Add(i,a+n,1);Add(a+n,i,0);
        }
        Add(s,i,1);Add(i,s,0);
    }
}

int d[N];
queue<int> q;

inline bool bfs(int s){
    memset(d,0,sizeof(d));d[s]=1;
    while(q.size()) q.pop();
    q.push(s);now[s]=head[s];
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(d[to]||!f) continue;
            d[to]=d[top]+1;q.push(to);
            now[to]=head[to];if(to==t) return 1;
        }
    }
    if(d[t]) return 1;return 0;
}

inline int Dinic(int k,int flow){
    if(k==t) return flow;
    int rest=flow;
    for(int x=now[k];x;x=li[x].next){
        int to=li[x].to,f=li[x].f;now[k]=x;
        if(d[to]!=d[k]+1||!f) continue;
        int val=Dinic(to,Min(rest,f));
        if(!val) d[to]=0;
        li[x].f-=val;li[x^1].f+=val;rest-=val;
    }
    return flow-rest;
}

inline void GetAns(){
    for(int x=head[s];x;x=li[x].next){
        int to=li[x].to,f=li[x].f;
        if(f) continue;
        for(int a=head[to];a;a=li[a].next){
            int nowto=li[a].to,nowf=li[a].f;
            if(nowf) continue;
            v[nowto-n].push_back(to);
        }
    }
}

inline void Solve(){
    // printf("LastAns=%d\n",Ans);
    while(bfs(s)){
        while((NowAns=Dinic(s,INF))) Ans-=NowAns;
    }
    // printf("Ans=%d\n",Ans);
    if(Ans) return(void)puts("No Solution!");
    GetAns();
    for(int i=1;i<=k;i++){
        printf("%d: ",i);
        for(int x:v[i]) printf("%d ",x);puts("");
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}