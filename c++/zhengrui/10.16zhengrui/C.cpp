#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n;

struct edge{
    int to,from,w;
    inline void Init(int fr_,int to_,int w_){
        from=fr_;to=to_;w=w_;
    }
    inline bool operator < (const edge &b)const{return w<b.w;}
}li[N*N];
int tail;

struct Edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li2[N*N];
int head[N],tail2;

inline void Add2(int from,int to,int w){
    li2[++tail2].Init(to,head[from],w);
    head[from]=tail2;
}

inline void Add(int from,int to,int w){
    li[++tail].Init(from,to,w);
}

int fa[N],Size[N],Bian[N];
bool vis[N*N];
int W[N][N],lim[N][N];

inline int Find(int x){return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);}

inline void Init(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);vis[w]=1;W[from][to]=W[to][from]=w;
        Add2(from,to,w);Add2(to,from,w);
    }
    for(int i=1;i<=n;i++){fa[i]=i;Size[i]=1;Bian[i]=0;}
}

typedef pair<int,int> P;

int fath[N][11],Max[N][11],Dep[N];
vector<P> v[N*N];

inline void dfs(int k,int father){
    fath[k][0]=father;Dep[k]=Dep[father]+1;
    for(int i=1;i<=10;i++) fath[k][i]=fath[fath[k][i-1]][i-1];
    for(int i=1;i<=10;i++) Max[k][i]=max(Max[k][i-1],Max[fath[k][i-1]][i-1]);
    for(int x=head[k];x;x=li2[x].next){
        int to=li2[x].to,w=li2[x].w;
        if(to==father) continue;
        Max[to][0]=w;dfs(to,k);
    }
}

inline P Lca(int x,int y){
    // printf("%d %d\n",x,y);
    int ans=-INF;
	if(Dep[x]<Dep[y]) swap(x,y);
	for(int i=10;i>=0;i--){
        if(Dep[fath[x][i]]>=Dep[y]){
            ans=max(ans,Max[x][i]);x=fath[x][i];
        }
    }
	if(x==y) return make_pair(x,ans);
	for(int i=10;i>=0;i--) if(fath[x][i]!=fath[y][i]){
        ans=max(ans,Max[x][i]);ans=max(ans,Max[y][i]);x=fath[x][i],y=fath[y][i];
    }
	return make_pair(fath[x][0],max(ans,max(Max[x][0],Max[y][0])));
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();sort(li+1,li+n);
    int ans=1,nowans=0;
    for(int i=1,j=0;i<=n;i++){
        int Nowans=nowans;
        while(j+1<=n*(n-1)/2&&(i==n||j+1<=li[i].w)){
            j++;if(vis[j]) continue;
            // printf("nowans-j+i=%lld\n",nowans-j+i);
            ans=1ll*ans*(nowans-j+i)%mod;
            // printf("%lld\n",ans);
        }
        if(i==n) break;
        int u=li[i].from,v=li[i].to;
        int fau=Find(u),fav=Find(v);
        nowans-=(Size[fau]*(Size[fau]-1)/2-Bian[fau]);
        nowans-=(Size[fav]*(Size[fav]-1)/2-Bian[fav]);
        fa[fau]=fav;Size[fav]+=Size[fau];Bian[fav]+=Bian[fau]+1;
        nowans+=(Size[fav]*(Size[fav]-1)/2-Bian[fav]);
    }
    printf("%lld\n",ans);
    if(!ans) exit(0);
    memset(Max,-INF,sizeof(Max));
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(W[i][j]) continue;
            if(i==j) continue;
            P now=Lca(i,j);
            // printf("i=%d j=%d\n",i,j);
            // printf("now.first=%d\n",now.first);
            v[now.second].push_back(make_pair(j,i));
            // printf("now.second=%d\n",now.second);
        }
    }
    int nowval=1;
    for(int i=1;i<=n*(n-1)/2;i++){
        for(P now:v[i]){
            while(vis[nowval]) nowval++;
            vis[nowval]=1;
            W[now.second][now.first]=nowval;
            W[now.first][now.second]=nowval;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%lld ",W[i][j]);
        puts("");
    }
    return 0;
}