#include<bits/stdc++.h>
// #include"swap.h"
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;

const int maxn=200010;
const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct edge{
    int from,to,next,w;
    inline void Init(int fr_,int to_,int ne_){
        from=fr_;to=to_;next=ne_;
    }
    inline bool operator < (const edge &b)const{return w<b.w;}
}li[maxn<<2],li2[maxn<<2];
int head[maxn],tail;

inline void Add(int from,int to){
    li[++tail].Init(from,to,head[from]);
    head[from]=tail;
}

int fa[maxn<<1],now,n,m;
int Ans[maxn<<1],P[maxn<<1][2],Tag[maxn<<1];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

inline bool IsNotThePoint(int p,int top){
    return p!=P[top][0]&&p!=P[top][1];
}

inline int OtherPoint(int p,int top){
    if(p==P[top][0]) return P[top][1];
    else return P[top][0];
}

inline void dfs(int k){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(Ans[k]&&!Ans[to]) Ans[to]=Ans[k];
        dfs(to);
    }
}

int Top[maxn],Dep[maxn],Size[maxn],Son[maxn],Fa[maxn];

inline void dfs1(int k,int fat){
    Dep[k]=Dep[fat]+1;Size[k]=1;Fa[k]=fat;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        dfs1(to,k);Size[k]+=Size[to];
        if(Size[Son[k]]<Size[to]) Son[k]=to;
    }
}

inline void dfs2(int k,int t){
    Top[k]=t;
    if(Son[k]) dfs2(Son[k],t);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Son[k]) continue;
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

inline void Kruskal(){
    sort(li2+1,li2+m+1);
    for(int i=1;i<=(n<<1);i++){
        fa[i]=i;Tag[i]=-1;P[i][0]=P[i][1]=i;
    }
    for(int i=1;i<=m;i++){
        int faa=Find(li2[i].from),fab=Find(li2[i].to);
        if(faa==fab){
            if(Ans[faa]) continue;
            Tag[faa]=2;Ans[faa]=li2[i].w;
        }   
        else{
            now++;
            fa[faa]=now;fa[fab]=now;Add(now,faa);Add(now,fab);
            if(Tag[faa]==2||Tag[fab]==2||(IsNotThePoint(li2[i].from,faa)||IsNotThePoint(li2[i].to,fab))){
                if(Ans[now]) continue;
                Ans[now]=li2[i].w;Tag[now]=2;
            }
            else{
                P[now][0]=OtherPoint(li2[i].from,faa);
                P[now][1]=OtherPoint(li2[i].to,fab);
                Tag[now]=1;
            }
        } 
    }
    dfs(now);dfs1(now,0);dfs2(now,now);
}

void init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W){
    n=N;m=M;
    for(int i=1;i<=M;i++){
        li2[i].from=U[i-1];li2[i].to=V[i-1];li2[i].w=W[i-1];
        li2[i].from++;li2[i].to++;
    }
    now=N;Kruskal();
}

int getMinimumFuelCapacity(int X, int Y){
    X++;Y++;
    int lca=GetLca(X,Y);
    return (!Ans[lca])?-1:Ans[lca];
}

// inline void Init(){
//     read(n);read(m);
//     for(int i=1;i<=m;i++){
//         read(li2[i].from);read(li2[i].to);read(li2[i].w);
//         li2[i].from++;li2[i].to++;
//     }
//     now=n;Kruskal();
// }

// int main(){
//     freopen("my.in","r",stdin);
//     freopen("my.out","w",stdout);
//     Init();
//     int Q;read(Q);
//     for(int i=1;i<=Q;i++){
//         int a,b;read(a);read(b);
//         a++;b++;
//         printf("%d\n",getMinimumFuelCapacity(a,b));
//     }
//     return 0;
// }