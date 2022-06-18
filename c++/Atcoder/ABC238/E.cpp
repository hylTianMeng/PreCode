#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int n,q;

bool vis[N];

inline void dfs(int k){
    vis[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[to]) continue;
        dfs(to);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=q;i++){
        int l,r;read(l);read(r);
        l--;if(l==0) l=n+1;
        Add(l,r);Add(r,l);
    }
    int k=n+1;dfs(k);
    if(vis[n]){printf("Yes\n");}
    else printf("No");
    return 0;
}