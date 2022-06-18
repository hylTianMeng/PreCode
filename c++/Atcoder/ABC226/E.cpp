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
const int mod=998244353;

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
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,cnt;
bool op=1;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

bool vis[N],vise[N<<1];
int cntp,cnte;

inline void dfs(int k){
    // printf("k=%d\n",k);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vise[x]||vise[x^1]) continue;
        cnte++;vise[x]=vise[x^1]=1;
        if(vis[to]) continue;
        cntp++;vis[to]=1;
        dfs(to);
    }
}

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        cntp=1;cnte=0;vis[i]=1;dfs(i);
        if(cntp!=cnte) return(void)puts("0");
        cnt++;
    }
    printf("%d\n",ksm(2,cnt,mod));
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}