#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M 1000100
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
}li[M];

int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,a[N],f[N],g[N],Max[N],Min[N];

int dfn[N],low[N],Stack[N],top,tot,scctot,c[N],d[N],Ans;
bool InStack[N];
vector<int> v[N];

inline void Tarjan(int k){
    // printf("enter %d\n",k);
    dfn[k]=low[k]=++tot;
    Stack[++top]=k;InStack[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!dfn[to]){
            Tarjan(to);low[k]=min(low[k],low[to]);
        }
        else if(InStack[to]) low[k]=min(low[k],dfn[to]);
    }
    // printf("k=%d low=%d dfn=%d\n",k,low[k],dfn[k]);
    if(dfn[k]==low[k]){
        int val;scctot++;
        do{
            val=Stack[top--];InStack[val]=0;
            c[val]=scctot;
            // printf("val=%d c=%d\n",val,scctot);
        }while(val!=k);
    }
}

queue<int> q;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        int op;read(op);if(op==1) Add(from,to);else{Add(from,to);Add(to,from);}
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
    memset(Min,INF,sizeof(Min));
    for(int i=1;i<=n;i++){
        Max[c[i]]=max(Max[c[i]],a[i]);
        Min[c[i]]=min(Min[c[i]],a[i]);
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;
            if(c[i]!=c[to]) v[c[i]].push_back(c[to]);
        }
    }
    memset(g,INF,sizeof(g));g[c[1]]=Min[c[1]];f[c[1]]=Max[c[1]]-g[c[1]];
    for(int i=c[1];i>=1;i--){
        if(g[i]==INF) continue;
        f[i]=max(f[i],Max[i]-g[i]);
        for(int to:v[i]){
            g[to]=min(g[i],Min[to]);
            f[to]=max(f[i],f[to]);
        }
    }
    printf("%d\n",f[c[n]]);
    return 0;
}