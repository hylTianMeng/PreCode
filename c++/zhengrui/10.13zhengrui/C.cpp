#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int to,next,from;
    inline void Init(int fr_,int to_,int ne_){
        to=to_;next=ne_;from=fr_;
    }
}li[N<<1];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(from,to,head[from]);
    head[from]=tail;
}

int a,b,n,Pre[N],Pass[N],ct,tag,f[N],g[N],gt;
bool op=1;

typedef pair<int,int> P;

inline void Init(){
    read(n);read(a);read(b);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void dfs(int k,int fa){
    if(k==b){op=0;return;}
    for(int x=head[k];x&&op;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Pre[to]=x;
        dfs(to,k);
    }
}

inline void Connect(){
    dfs(a,0);int now=b;
    while(li[Pre[now]].from!=a){Pass[++ct]=Pre[now];now=li[Pre[now]].from;}
    Pass[++ct]=Pre[now];reverse(Pass+1,Pass+1+ct);
}

inline bool Check(P a){
    if(a.first<=a.second) return 1;
    else return 0;
}

inline bool cmp(int a,int b){return a>b;}

inline void Dp(int k,int fa){
    f[k]=0;
    for(int x=head[k];x;x=li[x].next){
        if(x==tag||x==(tag^1)) continue;
        int to=li[x].to;
        if(to==fa) continue;
        Dp(to,k);
    }
    gt=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa||x==tag||x==(tag^1)) continue;
        g[++gt]=f[to];
    }
    if(!gt) return;
    sort(g+1,g+gt+1,cmp);
    for(int i=1;i<=gt;i++){
        f[k]=Max(f[k],g[i]+i);
    }
}

inline P Solve(int mid){
    tag=Pass[mid];Dp(a,0);Dp(b,0);
    return make_pair(f[a],f[b]);
}

inline int Binary(){
    int l=1,r=ct,ans=l;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(Solve(mid))){l=mid+1;ans=mid;}
        else r=mid-1;
    }
    // printf("ans=%d\n",ans);
    P ans1=Solve(ans),ans2=make_pair(-INF,INF);
    if(ans+1<=ct) ans2=Solve(ans+1);
    return Min(Max(ans1.first,ans1.second),Max(ans2.first,ans2.second));
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Connect();
    printf("%d\n",Binary());
    return 0;
}