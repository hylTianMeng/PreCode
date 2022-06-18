#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

int n;
int *f[N],*g[N];
// int f[N][N],g[N][N];
int fa[N],Son[N],Dep[N],Deep[N],Ans,p[N<<2];
int *o=p;

inline void dfs(int k,int fat){
    fa[k]=fat;Dep[k]=Dep[fat]+1;Deep[k]=Dep[k];
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);Deep[k]=max(Deep[to],Deep[k]);
        if(Deep[Son[k]]<Deep[to]) Son[k]=to;
    }
}

inline void Dp(int k){
    // printf("k=%d\n",k);
    if(Son[k]){
        f[Son[k]]=f[k]+1;g[Son[k]]=g[k]-1;Dp(Son[k]);
    }
    Ans+=g[k][0];
    f[k][0]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k]||to==Son[k]) continue;
        // if(to==fa[k]) continue;
        int dep=Deep[to]-Dep[to];
        f[to]=o;o+=((dep+1)<<1);g[to]=o;o+=((dep+1)<<1);
        Dp(to);
        for(int i=0;i<=dep;i++){
            Ans+=f[to][i]*g[k][i+1];
            if(i) Ans+=f[k][i-1]*g[to][i];
        }
        for(int i=0;i<=dep;i++){
            g[k][i+1]+=f[k][i+1]*f[to][i];
            if(i) g[k][i-1]+=g[to][i];
            f[k][i+1]+=f[to][i];
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);Add(from,to);Add(to,from);
    }
    dfs(1,1);
    f[1]=o;o+=(Deep[1]<<1);g[1]=o;o+=(Deep[1]<<1);
    Dp(1);
    printf("%lld\n",Ans);
    return 0;
}