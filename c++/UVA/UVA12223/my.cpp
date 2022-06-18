#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500100
#define M number
using namespace std;

const int INF=1e18;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

int f[N],t,n,Size[N],ans=INF,m,a[N],sum;

inline void Init(){
    tail=0;ans=INF;sum=0;
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to,w;read(from);read(to);read(w);
        Add(from,to,w);Add(to,from,w);
    }
    read(m);
    for(int i=1;i<=m;i++){
        int id,val;read(id);read(val);
        a[id]=val;sum+=a[id]*2;
    }
}

inline void Dfs(int k,int fa){
    Size[k]=a[k]*2;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(to==fa) continue;
        Dfs(to,k);Size[k]+=Size[to];
        f[1]+=Size[to]*w;
    }
}

inline void Dp(int k,int fa){
    ans=Min(ans,f[k]);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to,w=li[x].w;
        if(to==fa) continue;
        f[to]=f[k]-Size[to]*w+(sum-Size[to])*w;
        Dp(to,k);
    }
}

vector<int> Ans;

inline void Print(){
    printf("%lld",ans);puts("");
    for(int i=1;i<=n;i++){
        if(f[i]==ans) Ans.push_back(i);
    }
    for(int i=0;i<Ans.size();i++){
        printf("%lld",Ans[i]);if(i!=Ans.size()-1) printf(" ");
    }
    Ans.clear();
}

inline void Clear(){
    for(int i=1;i<=n;i++) head[i]=0;tail=0;
    for(int i=1;i<=n;i++) f[i]=0;ans=INF;sum=0;
    for(int i=1;i<=n;i++) a[i]=0;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Dfs(1,0);
        Dp(1,0);Print();
        Clear();
        puts("");
    }
}//