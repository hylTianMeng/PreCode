#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10010
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
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,Match[N];
bool vis[N];

inline bool dfs(int k){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!vis[to]){
            vis[to]=1;
            if(!Match[to]||dfs(Match[to])){
                Match[to]=k;return 1;
            }
        }
    }
    return 0;
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);to+=n;
        Add(from,to);Add(to,from);
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        if(dfs(i)) tot++;
        memset(vis,0,sizeof(vis));
    }
    // printf("tot=%d\n",tot);
}

bool Ans[N],Not[N];

inline void Dfs(int k){
    vis[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[Match[to]]) continue;
        Ans[Match[to]]=0;Dfs(Match[to]);
    }
}

inline void Solve(){
    for(int i=1;i<=n;i++) Ans[i]=1;
    for(int i=1;i<=(n<<1);i++) vis[i]=0;
    for(int i=n+1;i<=(n<<1);i++) Not[Match[i]]=1;
    // for(int i=n+1;i<=(n<<1);i++){
    //     printf("%d %d\n",i,Match[i]);
    // }
    for(int i=1;i<=n;i++) if(!Not[i]) Ans[i]=0;
    for(int i=1;i<=n;i++){
        if(Not[i]) continue;
        if(vis[i]) continue;
        Dfs(i);
    }
}

inline void Print(){
    for(int i=1;i<=n;i++){
        if(Ans[i]) puts("Slavko");
        else puts("Mirko");
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();Print();
    return 0;
}