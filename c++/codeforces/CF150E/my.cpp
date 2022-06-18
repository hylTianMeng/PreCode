#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100100
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
    int to,next,w,nw;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

int n,ans;
int *f[N],p[N<<2],*o,fa[N],Dep[N],h[N],Son[N],c[N];
int tag[N];

inline void dfs(int k,int fat){
    fa[k]=fat;Dep[k]=Dep[fat]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat||to==Son[k]) continue;
        dfs(to,k);
        if(h[Son[k]]<h[to]) Son[k]=to;
    }
    h[k]=h[Son[k]]+1;
}

inline void dfs2(int k){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k]) continue;
        if(to==Son[k]) c[k]=li[x].nw;
        dfs2(to);
    }
}

inline void Dp(int k){
    if(Son[k]){
        f[Son[k]]=f[k]+1;Dp(Son[k]);tag[k]+=tag[Son[k]];
        f[k][0]-=c[k]+tag[Son[k]];tag[k]+=c[k];
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].nw;
        if(to==fa[k]||to==Son[k]) continue;
        f[to]=o;o+=(h[to]+1);
        Dp(to);
        
        for(int i=0;i<h[to];i++){
            if(f[k][i+1]+tag[k]<f[to][i]+tag[to]+w){
                f[k][i+1]=f[to][i]+tag[to]+w-tag[k];
            }
        }
    }
}

inline bool Check(int mid){
    for(int i=1;i<=tail;i++){
        li[i].nw=(li[i].w<mid)?0:1;
    }
    dfs2(1);ans=0;
    memset(p,0,sizeof(p));*o=p;
    f[1]=o;o+=(h[1]+1);
    Dp(1);
}

int main(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to,w;read(from);read(to);read(w);Add(from,to,w);Add(to,from,w);
    }
    dfs(1,0);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(Check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}