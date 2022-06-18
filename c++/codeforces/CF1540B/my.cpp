#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 220
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int inv=500000004;

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
}li[N];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int n,f[N][N],p[N][N];

inline void PreWork(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=0;i<=200;i++) f[0][i]=1;
    for(int i=1;i<=200;i++) f[i][0]=0;
    // printf("spe: %d\n",f[2][0]);
    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++)
            f[i][j]=1ll*inv*((f[i-1][j]+f[i][j-1])%mod)%mod;
    // printf("spe: %d\n",f[2][0]);
}

int fa[N][10],dep[N];

inline void dfs(int k,int fat){
    fa[k][0]=fat;dep[k]=dep[fat]+1;
    for(int i=1;i<=9;i++) fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);
    }
}

inline int GetLca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=9;i>=0;i--) if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
    if(a==b) return a;
    for(int i=9;i>=0;i--) if(fa[a][i]!=fa[b][i]){a=fa[a][i];b=fa[b][i];}
    return fa[a][0];
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        // printf("i=%d\n",i);
        memset(fa,0,sizeof(fa));
        dfs(i,0);
        for(int j=2;j<=n;j++){
            for(int k=1;k<=j-1;k++){
                // printf("spe: %d\n",f[2][0]);
                int lca=GetLca(j,k);
                int len1=dep[j]-dep[lca];
                int len2=dep[k]-dep[lca];
                // printf("j=%d k=%d lca=%d f[%d][%d]=%d\n",j,k,lca,len1,len2,f[len1][len2]);
                (p[j][k]+=1ll*ksm(n,mod-2,mod)*f[len1][len2]%mod)%=mod;
            }
        }
    }
    int Ans=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i-1;j++) (Ans+=p[i][j])%=mod;
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();
    Solve();
    return 0;
}