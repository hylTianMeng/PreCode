#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20400
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
    int to,next,Lower,flow;
    bool flag;
    inline void Init(int to_,int ne_,int L,int F,int fl){
        to=to_;next=ne_;Lower=L;flow=F;flag=fl;
    }
}li[N<<1];
int head[N],tail=1,now[N];

int n,m,s,t,A,B,diff,Lasttail,Ans,NowAns;

inline void Add(int from,int to,int L,int F,int fl){
    li[++tail].Init(to,head[from],L,F,fl);head[from]=tail;
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to,L,U;read(from);read(to);read(L);read(U);
        Add(from,to,L,U-L,1);Add(to,from,L,0,0);
    }
    Lasttail=tail;
    s=n+1;t=n+2;
    for(int i=1;i<=n;i++){
        A=0,B=0;
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to,flag=li[x].flag;
            if(flag) B+=li[x].Lower;
            else A+=li[x].Lower;
        }
        diff=A-B;
        if(diff==0) continue;
        else if(diff>0){Add(s,i,0,diff,1);Add(i,s,0,0,0);}
        else{Add(i,t,0,-diff,1);Add(t,i,0,0,0);} 
    }
    // printf("HERE\n");exit(0);
}

int d[N];
queue<int> q;

inline bool bfs(int s){
    memset(d,0,sizeof(d));
    while(q.size()) q.pop();
    d[s]=1;q.push(s);now[s]=head[s];
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,f=li[x].flow;
            if(d[to]||!f) continue;
            now[to]=head[to];
            d[to]=d[top]+1;q.push(to);
            if(to==t) return 1;
        }
    }
    if(d[t]) return 1;return 0;
}

inline int Dinic(int k,int flow){
    if(k==t) return flow;
    int Rest=flow,x;
    for(x=now[k];x&&Rest;x=li[x].next){
        int to=li[x].to,f=li[x].flow;now[k]=x;
        if(!f||d[to]!=d[k]+1) continue;
        int val=Dinic(to,Min(f,Rest));
        if(!val) d[to]=0;
        li[x].flow-=val;li[x^1].flow+=val;
        Rest-=val;
    }
    return flow-Rest;
}

inline void Solve(){
    while(bfs(s)){
        while(NowAns=Dinic(s,INF)) Ans+=NowAns;
    }
    // printf("Ans=%d\n",Ans);
}

inline void Print(){
    for(int x=head[s];x;x=li[x].next){
        int flag=li[x].flag,f=li[x].flow;
        if(flag==0) continue;
        if(f) return(void)puts("NO");
    }
    for(int x=head[t];x;x=li[x].next){
        int flag=li[x].flag,f=li[x].flow;
        if(flag==0) continue; 
        if(f) return(void)puts("NO");
    }
    puts("YES");
    for(int i=2;i<=Lasttail;i+=2){
        printf("%d\n",li[i^1].flow+li[i^1].Lower);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();Print();return 0;
}