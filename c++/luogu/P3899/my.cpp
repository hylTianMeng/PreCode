#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 300100
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

struct Ques{
    int u,k,id;
    inline Ques(){}
    inline Ques(int u,int k,int id) : u(u),k(k),id(id) {}
}ques[N];

int n,q,qt,fa[N],Dep[N],h[N],Son[N],tag[N],Size[N],ans[N];
vector<int> v[N];

int p[N<<1];
int *o=p,*f[N];

inline void dfs(int k,int fat){
    fa[k]=fat;Dep[k]=Dep[fat]+1;Size[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);if(h[Son[k]]<h[to]) Son[k]=to;
        Size[k]+=Size[to];
    }
    h[k]=h[Son[k]]+1;
    for(int it:v[k]){
        ans[ques[it].id]=(Size[k]-1)*min(Dep[k]-1,ques[it].k);
    }
}

inline void Dp(int k){
    if(Son[k]){
        f[Son[k]]=f[k]+1;Dp(Son[k]);
        tag[k]=tag[Son[k]]+Size[Son[k]]-1;
        f[k][0]+=-tag[Son[k]]-Size[Son[k]]+1;
    }
    // printf("k=%d\n",k);
    // printf("tag=%d\n",tag[k]);
    // for(int i=0;i<h[k];i++){
    //     printf("%d ",f[k][i]);
    // }puts("");
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k]||to==Son[k]) continue;
        f[to]=o;o+=(h[to]<<1);
        Dp(to);
        for(int i=0;i<=h[to]-1;i++){
            f[k][i+1]+=f[to][i]+Size[to]-1+tag[to];
        }
        for(int i=0;i<=h[to];i++) f[k][i]-=f[to][h[to]-1]+Size[to]-1+tag[to];
        tag[k]+=f[to][h[to]-1]+Size[to]-1+tag[to];
    }
    for(int it:v[k]){
        ans[ques[it].id]+=f[k][min(ques[it].k,h[k]-1)]+tag[k];
    }
    // printf("k=%d\n",k);
    // printf("tag=%d\n",tag[k]);
    // for(int i=0;i<h[k];i++){
    //     printf("%d ",f[k][i]);
    // }puts("");
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=q;i++){
        int u,k;read(u);read(k);
        ques[++qt]=Ques(u,k,i);
        v[u].push_back(qt);
    }
    dfs(1,0);
    // printf("%lld\n",ans[1]);
    f[1]=o;o+=(h[1]<<1);Dp(1);
    for(int i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}