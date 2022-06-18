#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

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

int f[N][N],n,K,a[N],ans[N],Size[N],h[N],Pre[N][N],Suf[N][N];

inline void Init(){
    read(n);read(K);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void dfs(int k,int fa){
    Size[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        dfs(to,k);Size[k]+=Size[to];
    }
}

inline void Merge(int a,int b,int id){
    for(int i=1;i<=K;i++) h[i]=0;
    for(int i=id;i<=Min(Size[a],K);i++)
        for(int j=0;j<=Size[b]&&j+i<=K;j++){
            (h[i+j]+=1ll*f[a][i]*f[b][j]%mod)%=mod;
        }
    for(int i=1;i<=K;i++) f[a][i]=h[i];
}

inline void Dp1(int k,int fa){
    for(int i=0;i<=K;i++) f[k][i]=0;
    f[k][1]=a[k];f[k][0]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dp1(to,k);
        Merge(k,to,1);
    }
}

// inline void Dp2(int k,int fa){
//     vector<int> son;son.clear();
//     for(int x=head[k];x;x=li[x].next){
//         int to=li[x].to;
//         if(to==fa) continue;
//         son.push_back(to);
//     }
//     for(int i=0;i<son.size();i++){
//         ...
//     }
// }

// inline void Print(){
//     for(int i=1;i<=n;i++) printf("%d ",ans[i]);
// }

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();dfs(1,0);
    for(int i=1;i<=n;i++){
        Dp1(i,0);
        int ans=0;
        for(int j=1;j<=K;j++) (ans+=f[i][j])%=mod;
        printf("%lld ",ans);
    }
    return 0;
}