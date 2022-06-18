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

struct edge{
    int to,next,from;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;li[tail].from=from;;
}

int n,m,p;

int dfn[N],low[N],tot;
bool bridge[N<<1];

inline void Tarjan(int k,int inedge){
    dfn[k]=low[k]=++tot;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!dfn[to]){
            Tarjan(to,x);low[k]=min(low[k],low[to]);
            if(low[to]>dfn[k]){
                bridge[x]=bridge[x^1]=1;
                // printf("from=%d to=%d\n",li[x].from,li[x].to);
            }
        }
        else if((inedge^1)!=x) low[k]=min(low[k],dfn[to]);
    }
}

int dcc,c[N];
bool vis[N];
vector<int> v[N],v2[N];

inline void dfs(int k){
    vis[k]=1;c[k]=dcc;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[to]||bridge[x]) continue;
        dfs(to);
    }
}

int ans[N<<1],cnt;

inline void Build(){
    for(int i=1;i<=n;i++){if(!vis[i]){dcc++;dfs(i);}}
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;
            if(c[i]==c[to]) continue;
            v[c[i]].push_back(c[to]);
            v2[c[i]].push_back(x);
        }
    }
}

int a[N];
bool vis2[N];

inline void dfs2(int k,int fa){
    vis2[k]=1;
    for(int j=0;j<v[k].size();j++){
        int to=v[k][j],x=v2[k][j];
        if(to==fa) continue;
        dfs2(to,k);a[k]+=a[to];
        if(a[to]>0) ans[x]=ans[x^1]=(c[li[x].from]==k)?li[x].from:li[x].to;
        else if(a[to]<0) ans[x]=ans[x^1]=(c[li[x].from]==k)?li[x].to:li[x].from;
        else ans[x^1]=ans[x]=-1;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,0);
    Build();
    // for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
    read(p);
    for(int i=1;i<=p;i++){
        int x,y;read(x);read(y);
        a[c[x]]++;a[c[y]]--;
    }
    // printf("dcc=%d\n",dcc);
    for(int i=1;i<=dcc;i++) if(!vis2[i]) dfs2(i,0);
    // for(int i=2;i<=tail;i++) printf("%d ",ans[i]);puts("");
    // for(int i=1;i<=dcc;i++) printf("%d ",a[i]);puts("");
    for(int i=2;i<=tail;i++) if(ans[i]==0) ans[i]=-1;
    for(int i=2;i<=tail;i+=2){
        if(ans[i]==-1) putchar('B');
        else if(ans[i]==li[i].from) putchar('L');
        else if(ans[i]==li[i].to) putchar('R');
        else{
            // assert(0);
            // printf("i=%d\n",i);
            // printf("ans=%d\n",ans[i]);
            // printf("from=%d to=%d\n",li[i].from,li[i].to);
        }
    }
    return 0;
 }