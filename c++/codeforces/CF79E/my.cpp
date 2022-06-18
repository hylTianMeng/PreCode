#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

struct edge{
    int to,next;
    bool OnTree;
    inline edge(){OnTree=1;}
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m;
int Fa[N],Size[N],Dep[N],Top[N],Son[N],Root[N];
bool vis[N];

inline void dfs1(int k,int fa){
    vis[k]=1;Root[k]=Root[fa];
    Fa[k]=fa;Size[k]=1;Dep[k]=Dep[fa]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa||vis[to]) continue;
        dfs1(to,k);vis[to]=1;li[x].OnTree=1;
        if(Size[Son[k]]<Size[to]) Son[k]=to;
    }
}

inline void dfs2(int k,int t){
    Top[k]=t;vis[k]=1;
    if(Son[k]) dfs2(Son[k],t);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(!li[x].OnTree) continue;
        if(to==Son[k]||to==Fa[k]) continue;
        dfs2(to,to);
    }
}

inline int GetLca(int a,int b){
    while(Top[a]!=Top[b]){
        if(Dep[Top[a]]<Dep[Top[b]]) swap(a,b);
        a=Fa[Top[a]];
    }
    if(Dep[a]>Dep[b]) swap(a,b);
    return a;
}

int low[N],dfn[N],tot,Stack[N],top,cnt,belo[N];
bool cut[N];
vector<int> v[N];

inline void Tarjan(int k,int fa){
    low[k]=dfn[k]=++tot;
    Stack[++top]=k;
    if(k==Root[k]&&head[k]==0){
        v[++cnt].push_back(k);belo[k]=cnt;
        return;
    }
    int flag=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        if(!dfn[to]){
            Tarjan(to,to);low[k]=Min(low[to],low[k]);
            if(low[to]>=dfn[k]){
                flag++;if(k!=Root[k]||flag>1) cut[k]=1;
                int now;do{now=Stack[top--];v[cnt].push_back(now);belo[now]=cnt;}while(now!=to);v[cnt].push_back(k);
            }
        }else low[k]=Min(low[k],dfn[to]);
    }
}

int c[N];

inline bool Color(int k,int co){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(belo[to]!=belo[k]) continue;
        if(c[to]!=0||c[to]!=co) return 1; 
        if(c[to]) continue;
        c[to]=co;Color(to,3-co);
    }
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++){
        if(Dep[i]) continue;
        dfs1((Root[i]=i),0);dfs2(i,i);
        Tarjan(i,0);
    }
}



vector<int> v[N];

int main(){
    Init();
}