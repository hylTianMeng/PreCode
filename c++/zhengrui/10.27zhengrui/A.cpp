#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}
template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<2];
int head[N<<1],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,tot,a[N],c[N],fa[N<<1],Dep[N<<1],ans,f[N<<1];
bool vis[N];

inline int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}

inline char GetChar(){
    char c=getchar();
    while(c!='R'&&c!='B') c=getchar();
    return c;
}

inline void Init(){
    read(n);tot=n;
    for(int i=1;i<=n;i++){
        char c;c=GetChar();
        if(c=='R') a[i]=1;
        else a[i]=0;
    }
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void Dfs(int k,int Fa){
    vis[k]=1;c[k]=tot;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Fa||a[k]!=a[to]) continue;
        Dfs(to,k);
    }
}

inline void Shrinking(){
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        tot++;Dfs(i,0);
    }
}

inline void Build(){
    for(int i=1;i<=n<<1;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;
            if(c[i]==c[to]) continue;
            int fai=Find(c[i]),fato=Find(c[to]);
            if(fai==fato) continue;
            Add(c[i],c[to]);Add(c[to],c[i]);
            fa[fai]=fato;
        }
    }
}

inline void dfs(int k,int fa){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        dfs(to,k);
        ans=Max(ans,f[k]+f[to]+1);
        f[k]=Max(f[k],f[to]+1);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Shrinking();Build();dfs(c[1],0);
    printf("%d\n",(ans+1)/2);
    return 0;
}