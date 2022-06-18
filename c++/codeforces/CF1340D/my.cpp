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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

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

int d[N],D,n;

struct Operation{
    int id,w;
    inline Operation(){}
    inline Operation(int id,int w) : id(id),w(w) {}
}o[M];
int ot;

inline void Insert(int id,int w){o[++ot]=Operation(id,w);}

inline void Dfs(int k,int w,int fa){
    int now=w;
    Insert(k,now);
    if(now==D){
        now-=d[k];Insert(k,now);
    }
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,++now,k);
        Insert(k,now);
        if(now==D&&li[x].next){
            now-=d[k];Insert(k,now);
        }
    }
    if(k!=1&&now!=w-1) Insert(k,w-1);
}

inline void Print(){
    printf("%d\n",ot);
    for(int i=1;i<=ot;i++){
        printf("%d %d\n",o[i].id,o[i].w);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    if(n==1){
        printf("1\n1 0\n");return 0;
    }
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);d[from]++;d[to]++;
    }
    for(int i=1;i<=n;i++) D=Max(D,d[i]);
    Dfs(1,0,0);Print();
    return 0;
}