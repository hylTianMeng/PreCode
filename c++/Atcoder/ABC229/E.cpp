#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int fa[N];

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

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

int n,m,Ans[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=n;i>=1;i--){
        // printf("i=%d\n",i);
        Ans[i]=Ans[i+1]+1;
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;
            if(to>i){
                int faa=Find(i),fab=Find(to);if(faa==fab) continue;
                // printf("to=%d\n",to);
                fa[faa]=fab;Ans[i]--;
            }
        }
        // printf("Ans[%d]=%d\n",i,Ans[i]);
    }
    for(int i=2;i<=n;i++){
        printf("%d\n",Ans[i]);
    }
    puts("0");
    return 0;
}