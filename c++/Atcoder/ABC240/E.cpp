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

int n,tot=0;

typedef pair<int,int> P;
P ans[N];

inline void dfs(int k,int fa){
    bool op=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        dfs(to,k);op=1;
    }
    if(!op){
        tot++;ans[k].first=ans[k].second=tot;
        return;
    }
    ans[k].first=INF;ans[k].second=-INF;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        ans[k].first=min(ans[to].first,ans[k].first);
        ans[k].second=max(ans[k].second,ans[to].second);
    }
}

int main(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}