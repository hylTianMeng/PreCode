#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int n,ans[N];
bool vis[N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++){
        Add(2*i,2*i-1);Add(2*i-1,2*i);
    }
}

inline void dfs(int k,int c){
    // printf("k=%d c=%d\n",k,c);
    vis[k]=1;ans[k]=c;
    // printf("ans[%d]=%d\n",k,ans[k]);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[to]) continue;
        dfs(to,c^1);
    }
}

inline void Print(){
    for(int i=1;i<=2*n;i++){
        if(ans[i]==0) putchar('X');
        else putchar('Y');
    }
}

inline void Solve(){
    for(int i=1;i<=2*n;i++){
        if(vis[i]) continue;
        dfs(i,0);
    }
    Print();
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();Solve();
}