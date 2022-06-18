#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1001000
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

int n;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int fa[N],Dep[N],h[N],Son[N];;
int p[N<<2],*o=p,*f[N];
typedef pair<int,int> P;
P ans[N];

inline void dfs(int k,int fat){
    Dep[k]=Dep[fat]+1;fa[k]=fat;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);if(h[Son[k]]<h[to]) Son[k]=to;
    }
    h[k]=h[Son[k]]+1;
}

inline void Dp(int k){
    ans[k]=make_pair(INF,INF);
    if(Son[k]){
        f[Son[k]]=f[k]+1;Dp(Son[k]);ans[k]=ans[Son[k]];ans[k].second++;
    }
    f[k][0]=1;if(ans[k]>make_pair(-1,0)) ans[k]=make_pair(-1,0);
    // printf("k=%d\n",k);
    // printf("ans[k]= %d %d\n",ans[k].first,ans[k].second);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k]||to==Son[k]) continue;
        f[to]=o;o+=(h[to]+1);
        Dp(to);
        for(int i=0;i<h[to];i++){
            f[k][i+1]+=f[to][i];
            if(ans[k]>make_pair(-f[k][i+1],i+1)) ans[k]=make_pair(-f[k][i+1],i+1);
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    dfs(1,0);f[1]=o;o+=(h[1]+1);Dp(1);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i].second);
    return 0;
}