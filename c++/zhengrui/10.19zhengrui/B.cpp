#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 8000100
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
    int to,next,Color;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,d[N],tot,ans[N];
bool Edge[N];

inline void dfs(int k){
    for(int &x=head[k];x;x=li[x].next){
        int to=li[x].to;int now=x>>1,Now=x;
        if(Edge[Now]||Edge[Now^1]) continue;
        Edge[Now]=Edge[Now^1]=1;
        dfs(to);tot++;
        // li[Now].Color=(tot)&1;li[Now^1].Color=(tot)&1;
        ans[now]=tot&1;
    }
}

int main(){
    memset(ans,-1,sizeof(ans));
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);d[from]++;d[to]++;
    }
    for(int i=1;i<=n;i++) if(d[i]&1){Add(i,n+1);Add(n+1,i);}
    for(int i=n+1;i>=1;i--){
        tot=0;dfs(i);if((tot&1)&&i<=n){puts("-1");exit(0);}
    }
    // for(int i=2;i<=2*m;i+=2){
    //     printf("%d ",li[i].Color);
    // }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}