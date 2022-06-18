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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

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

int f[N][2],g[N][2],ans[N],Ans,n;

inline void Dfs(int k,int fa){
    bool op=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,k);f[k][0]+=Max(f[to][1],f[to][0]);
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        f[k][1]=Max(f[k][1],f[k][0]-Max(f[to][1],f[to][0])+f[to][0]+1);
        op=1;
    }
    if(!op) f[k][1]=-INF;
    // printf("f[%d][0]=%d\nf[%d][1]=%d\n",k,f[k][0],k,f[k][1]);
}

inline void Init(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void Dp(int k,int fa){
    int sum=0,X=-1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        sum+=Max(f[to][0],f[to][1]);
        if(f[to][0]>=f[to][1]) X=to;
    }
    if(X==-1){
        int cha=INF;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to;
            if(to==fa) continue;
            if(f[to][1]-f[to][0]<cha){
                cha=f[to][1]-f[to][0];
                X=to;
            }
        }
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        g[to][1]=sum-Max(f[to][0],f[to][1])+g[k][0]+1;
        g[to][0]=sum-Max(f[to][0],f[to][1])+Max(g[k][0],g[k][1]);
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa||to==X) continue;
        g[to][0]=Max(g[to][0],sum-Max(f[to][0],f[to][1])-Max(f[X][0],f[X][1])+f[X][0]+1+g[k][0]);
        g[X][0]=Max(g[X][0],sum-Max(f[X][0],f[X][1])-Max(f[to][0],f[to][1])+f[to][0]+1+g[k][0]);
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dp(to,k);
    }
}

inline void Calc(int k,int fa){
    ans[k]=g[k][0];
    // printf("g[%d][0]=%d\ng[%d][1]=%d\n",k,g[k][0],k,g[k][1]);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        ans[k]+=Max(f[to][0],f[to][1]);
        Calc(to,k);
    }
}

inline void Print(){
    int tot=0;
    Ans=Max(f[1][0],f[1][1]);
    // printf("Ans=%d\n",Ans);
    for(int i=1;i<=n;i++){
        if(Ans==ans[i]) tot++;
        // printf("ans[%d]=%d\n",i,ans[i]);
    }
    printf("%d\n",tot);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dfs(1,0);Dp(1,0);Calc(1,0);Print();
}