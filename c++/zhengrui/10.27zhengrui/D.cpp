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

int n,p,q;

inline void Init(){
    read(n);read(p);read(q);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

int Dep[N],Son[N],Fa[N],Top[N];

inline void Dfs1(int k,int fa){
    Fa[k]=fa;Deep[k]=Dep[fa]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs1(to,k);
        if(Dep[son[k]]<Dep[to]) son[k]=to;
    }
}

inline void Dfs2(int k,int t){
    Top[k]=t;
    if(son[k]) Dfs2(son[k],t);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Fa[k]||to==Son[k]) continue;
        Dfs2(to,to);
    }
}

inline void Subdivision(){
    Dfs1(1,0);Dfs1(1,1);
}

vector<int> v[N];
int tot=0,f[N][2];
//0 为 p，1 为 q

inline void Merge(int a,int b){
    int len=v[b].size()-1;
    for(int i=0;i<v[a].size();i++){
        if(i<=p&&p-i-1<=len) f[i][0]=f[i][0]+v[a][i]*v[b][p-i-1];
        if(i<=q&&q-i-1<=len) f[i][1]=f[i][1]+v[a][i]*v[b][q-i-1];
    }
    for(int i=1;i<v[a].size();i++){
        v[a][i]+=v[b][i-1];
    }
}

inline int Dp(int k){
    int id=-1;
    if(Son[k]) id=Dp(Son[k]);
    else id=++tot;
    v[id].insert(v[id].begin(),1);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Son[k]||to==Fa[k]) continue;
        int toid=Dp(to);
        Merge(id,to);
    }
    return id;
}

int main(){
    Init();Subdivision();Dp(1);

}