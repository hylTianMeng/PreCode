#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define dd double
#define int long long
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M number
using namespace std;

const ll INF=1e18;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

ll f[N];

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);head[from]=tail;
}

int n,m,a[N];
ll Ans=INF;

inline void Init(){
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void Dfs(int k,int fa){
    f[k]=a[k];
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,k);f[k]+=f[to];
    }
}

inline void Dp(int k,int fa){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dp(to,k);
    }
    Ans=Min(Ans,llabs(2*f[k]-f[1]));
}

inline void Solve(){Dfs(1,0);Dp(1,0);}

int cnt=0;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    while(scanf("%lld%lld",&n,&m)!=EOF&&n&&m){
        cnt++;
        Init();Solve();printf("Case %lld: %lld\n",cnt,Ans);
        tail=0;Ans=INF;memset(head,0,sizeof(head));
    }
}