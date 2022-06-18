#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

int fa[N][21],Son[N],Dep[N],Deep[N],Top[N];
vector<int> u[N],d[N];

inline void dfs(int k,int fat){
    fa[k][0]=fat;for(int i=1;i<=20;i++) fa[k][i]=fa[fa[k][i-1]][i-1];
    Dep[k]=Dep[fat]+1;Deep[k]=Dep[k];
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);Deep[k]=max(Deep[k],Deep[to]);
        if(Deep[Son[k]]<Deep[to]) Son[k]=to;
    }
}

inline void dfs2(int k,int t){
    Top[k]=t;
    if(k==t){
        int len=Deep[k]-Dep[t];
        d[k].push_back(k);int now=k;
        for(int i=1;i<=len;i++){
            now=Son[now];if(now==0) break;
            d[k].push_back(now);
        }
        u[k].push_back(k);now=k;
        for(int i=1;i<=len;i++){
            now=fa[now][0];if(now==0) break;
            u[k].push_back(now);
        }
    }
    if(Son[k]) dfs2(Son[k],t);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa[k][0]||to==Son[k]) continue;
        dfs2(to,to);
    }
}

uint s;
ll Ans;

inline uint get(uint x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

int n,q,root,ans,lg2[N];

inline void Ask(){
    int x=((get(s)^ans)%n)+1;
    int k=(get(s)^ans)%Dep[x];
    // printf("x=%d k=%d\n",x,k);
    if(k==0){ans=x;return;}
    int nowx=fa[x][lg2[k]];int nowk=k-(1<<lg2[k]);
    // printf("nowx=%d nowk=%d\n",nowx,nowk);
    int t=Top[nowx],dep=Dep[nowx]-nowk;
    // printf("t=%d dep=%d\n",t,dep);
    // printf("Dep[t]=%d\n",Dep[t]);
    if(dep>Dep[t]) ans=d[t][dep-Dep[t]];
    else if(dep<=Dep[t]) ans=u[t][Dep[t]-dep];
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);read(s);
    lg2[0]=-1;for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=n;i++){
        int fi;read(fi);
        if(fi==0) root=i;else Add(fi,i);
    }
    dfs(root,0);dfs2(root,root);
    for(int i=1;i<=q;i++){
        Ask();
        Ans^=(1ll*i*ans);
        // printf("ans=%d\n",ans);
    }
    printf("%lld\n",Ans);
    return 0;
}