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

int T[N],n;

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N];
int head[N],tail,d[N];

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(T[i]);int K;read(K);
        for(int j=1;j<=K;j++){
            int x;read(x);
            Add(i,x);d[x]++;
        }
    }
}

queue<int> q;
bool vis[N];
ll ans;

inline void Solve(){
    vis[n]=1;q.push(n);ans=T[n];
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to;
            if(vis[to]) continue;
            vis[to]=1;ans+=T[to];q.push(to);
        }
    }
    printf("%lld\n",ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}