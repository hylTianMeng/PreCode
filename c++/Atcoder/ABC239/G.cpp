#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 400
#define M 600010
using namespace std;

const ll INF=1e18;

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
    inline void intt(int to_,int ne_,int f_){
        to=to_;next=ne_;f=f_;
    }
};
edge li[M];
int head[N],tail=1,now[N];

inline void Add(int from,int to,int f){
    li[++tail].intt(to,head[from],f);
    head[from]=tail;
}

int s,t,n,m,a[N];

queue<int> q;
int d[N];
inline bool bfs(int s){
    while(q.size()) q.pop();
    memset(d,0,sizeof(d));
    d[s]=1;now[s]=head[s];q.push(s);
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(!f||d[to]) continue;
            d[to]=d[top]+1;now[to]=head[to];
            q.push(to);
            if(to==t) return 1;
        }
    }
    if(!d[t]) return 0;
    return 1;
}

inline int dicnic(int k,int flow){
    if(k==t) return flow;
    int rest=flow,x;
    for(x=now[k];x&&rest;x=li[x].next){
        int to=li[x].to,re=li[x].f;
        if(!re||d[to]!=d[k]+1) continue;
        int val=dicnic(to,min(rest,re));
        if(!val) d[to]=0;
        li[x].f-=val;
        li[x^1].f+=val;
        rest-=val;
    }
    now[k]=x;
    return flow-rest;
}

ll ans,col[N];

bool vis[N];

inline void dfs(int k,int X){
    col[k]=X;vis[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,f=li[x].f;
        if(!f||vis[to]) continue;
        dfs(to,X);
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        // printf("%lld %lld\n",from+n,to);
        // printf("%lld %lld\n",to+n,from);
        Add(from+n,to,INF);Add(to,from+n,0);
        Add(to+n,from,INF);Add(from,to+n,0);
    }
    for(int i=1;i<=n;i++) read(a[i]);
    int nowtail=tail;
    for(int i=1;i<=n;i++){
        // printf("%lld %lld\n",i,i+n);
        if(i==1||i==n) a[i]=INF;
        Add(i,i+n,a[i]);
        Add(i+n,i,0);
    }
    s=2*n+1;t=s+1;
    Add(s,1,INF);Add(1,s,0);
    Add(n+n,t,INF);Add(t,n+n,0);
    ll flow;
    while(bfs(s)){
        // printf("here\n");
        while((flow=dicnic(s,INF))) ans+=flow;
    }
    printf("%lld\n",ans);

    dfs(s,1);
    vector<int> Ans;Ans.clear();

    for(int i=2;i<=n-1;i++){
        if(col[i]!=col[i+n]) Ans.push_back(i);
    }

    sort(Ans.begin(),Ans.end());
    printf("%lld\n",(int)Ans.size());
    for(int i=0;i<Ans.size();i++) printf("%lld ",Ans[i]);

    return 0;
}