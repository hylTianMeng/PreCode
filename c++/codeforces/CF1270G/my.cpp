#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int t,n,a[N],Stack[N],top,beg;
bool vis[N];

inline bool dfs(int k){
    vis[k]=1;
    Stack[++top]=k;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[to]){beg=to;return 1;}
        if(dfs(to)) return 1;
    }
    top--;
    return 0;
}

int main(){
    // freopen("my.in","r",stdin);
    read(t);
    while(t--){
        top=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        read(n);for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++){
            Add(i,i-a[i]);
            // printf("%d %d\n",i,i-a[i]);
        }
        for(int i=1;i<=n;i++) if(!vis[i]){if(dfs(i)) break;}
        int w=0;
        for(int i=1;i<=top;i++) if(Stack[i]==beg){w=i;break;}
        printf("%d\n",top-w+1);
        for(int i=w;i<=top;i++) printf("%d ",Stack[i]);
        puts("");
    }
    return 0;
}