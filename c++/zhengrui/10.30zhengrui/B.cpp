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

int n,m,Sum,Fa[N],Dep[N];
bool vis[N];

struct node{
    int val,id;
    inline node(){}
    inline node(int val,int id) : val(val),id(id) {}
    inline bool operator < (const node &b)const{return val<b.val;}
};

inline void Dfs(int k,int fa){
    Fa[k]=fa;Dep[k]=Dep[fa]+1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,k);
    }
}

inline int Sign(int k){
    int now=k;int cnt=0;
    while(!vis[now]&&now!=1){
        vis[now]=1;now=Fa[now];
        cnt++;
    }
    return cnt;
}

inline void Insert(int k){
    int len=Sign(k);
    Sum+=len*2;
    printf("%d\n",Sum-Dep[k]+1);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    Dfs(1,0);
    for(int i=1;i<=m;i++){
        int x;read(x);Insert(x);
    }
}