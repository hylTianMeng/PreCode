#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300100
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

int a[N],n,ans[N],m,U=100000,cnt[N];
int fa[N],Dep[N],Size[N],Son[N],ban;

struct BIT{
    int p[N];
    inline int lowbit(int k){return k&(-k);}
    inline void Add(int k,int x){
        for(int i=k;i;i-=lowbit(i)) p[i]+=x;
    }
    inline int AskSum(int k){
        int res=0;for(int i=k;i<=U;i+=lowbit(i)) res+=p[i];return res;
    }
}bit;

typedef pair<int,int> P;
vector<P> v[N];

inline void dfs(int k,int fat){
    Dep[k]=Dep[fat]+1;Size[k]=1;
    fa[k]=fat;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fat) continue;
        dfs(to,k);Size[k]+=Size[to];
        if(Size[Son[k]]<Size[to]) Son[k]=to;
    }
}

inline void Add(int k){
    bit.Add(cnt[a[k]],-1);cnt[a[k]]++;bit.Add(cnt[a[k]],1);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa[k]||to==ban) continue;Add(to);
    }
}

inline void Del(int k){
    bit.Add(cnt[a[k]],-1);cnt[a[k]]--;bit.Add(cnt[a[k]],1);
    for(int x=head[k];x;x=li[x].next){int to=li[x].to;if(to==fa[k]) continue;Del(to);}
}

inline void Dfs(int k,int op){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Son[k]||to==fa[k]) continue;
        Dfs(to,0);
    }
    if(Son[k]){Dfs(Son[k],1);ban=Son[k];}
    Add(k);ban=-1;
    for(auto i:v[k]){
        ans[i.second]=bit.AskSum(i.first);
    }
    if(!op){Del(k);}
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=m;i++){
        int u,k;read(u);read(k);
        v[u].push_back(make_pair(k,i));
    }
    dfs(1,0);Dfs(1,0);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}