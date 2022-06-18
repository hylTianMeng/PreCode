#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,k) memset(a,k,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 10000
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

struct edge{
    int to,next,w,f;
    inline void Init(int to_,int ne_,int w_,int f_){
        to=to_;next=ne_;w=w_;f=f_;
    }
}li[N];
int head[N],tail=1;

inline void Add(int from,int to,int w,int f){
    li[++tail].Init(to,head[from],w,f);
    head[from]=tail;
}

int n,m,s,t;

int fl[N],d[N],pree[N],prep[N],ans;
bool vis[N];
queue<int> q;

inline bool EK(){
    mset(d,INF);mset(fl,INF);mset(vis,0);
    while(q.size()) q.pop();mset(prep,0);mset(pree,0);
    q.push(s);vis[s]=1;d[s]=0;
    while(q.size()){
        int top=q.front();q.pop();vis[top]=0;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to,f=li[x].f,w=li[x].w;
            if(f==0||d[to]<=d[top]+w) continue;
            d[to]=d[top]+w;fl[to]=min(fl[top],w);prep[to]=top;pree[to]=x;
            if(!vis[to]){q.push(to);vis[to]=1;}
        }
    }
    if(d[t]<INF||fl[t]<INF) return 0;
    return 1;
}

inline void Update(){
    int now=t,nowe;
    while(prep[now]){
        nowe=pree[now];now=prep[now];li[nowe].f-=fl[t];li[nowe^1].f+=fl[t];
        ans=ans+li[nowe].w*fl[t];
    }
}


signed main(){

}