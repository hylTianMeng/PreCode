#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M 200010
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
}li[N<<2];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int Fa[N],Size[N],Col[N];
int n,m,a[N];
bool No[N];

inline int Find(int x){assert(x&&x<=n);return x==Fa[x]?x:Fa[x]=Find(Fa[x]);}

inline void dfs(int k,int fa){
    Col[k]=Col[fa]^1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa) continue;dfs(to,k);
    }
}

inline void Merge(int a,int b){
    // printf("a=%lld b=%lld\n",a,b);
    int faa=Find(a),fab=Find(b);
    if(Size[faa]<Size[fab]){swap(faa,fab);swap(a,b);}
    // printf("faa=%lld fab=%lld\n",faa,fab);
    if(faa==fab){
        // printf("Now Col[%lld]=%lld Col[%lld]=%lld\n",a,Col[a],b,Col[b]);
        if(Col[a]==Col[b]) No[faa]=1;
        return;
    }
    Size[faa]+=Size[fab];Fa[fab]=faa;
    Add(a,b);Add(b,a);
    if(No[faa]||No[fab]){
        No[faa]=1;return;
    }
    dfs(b,a);
    // printf("Col:");for(int i=1;i<=n;i++) printf("%lld ",Col[i]);puts("");
    // printf("Fa:");for(int i=1;i<=n;i++) printf("%lld ",Fa[i]);puts("");
    // printf("No:");for(int i=1;i<=n;i++) printf("%lld ",No[i]);puts("");
}

inline void Init(){
    read(n);read(m);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) Fa[i]=i;
    for(int i=1;i<=n;i++) Size[i]=1;
}

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

inline void Solve(){
    int op;read(op);
    // printf("op=%d\n",op);
    if(op==1){
        int x,c;read(x);read(c);a[x]=c;
    }
    else if(op==2){
        int x,y;read(x);read(y);if(x==y) return;
        Merge(x,y);
    }
    else{
        int x,y,v;read(x);read(y);read(v);
        // printf("x=%d y=%d v=%d\n",x,y,v);
        // printf("here\n");
        int faa=Find(x),fab=Find(y);
        // printf("faa=%d fab=%d\n",faa,fab);
        if(faa!=fab||No[faa]||No[fab]) return(void)puts("0");
        int fenzi=a[x]*v;int fenmu=a[y];int g=gcd(a[x]*v,a[y]);
        // printf("g=%d\n",g);
        fenzi/=g;fenmu/=g;
        if((Col[x]^Col[y])==1) printf("-");
        printf("%lld/%lld\n",abs(fenzi),abs(fenmu));
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    while(m--){
        // printf("m=%d\n",m);
        Solve();
    }
    return 0;
}