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

int t,n,Ans[N],c[N],lg2[N];
vector<int> S[2];
bool vis[N];

inline void dfs(int k,int fa,int col){
    c[k]=col;S[col].push_back(k);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to==fa) continue;
        dfs(to,k,col^1);
    }
}

inline void Clear(){
    vector<int>().swap(S[0]);vector<int>().swap(S[1]);
    for(int i=1;i<=n;i++) head[i]=vis[i]=c[i]=Ans[i]=0;
    tail=0;
}

inline void Init(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
}

inline void Solve(){
    dfs(1,0,0);int now=0;if(S[0].size()<S[1].size()) now=1;
    int k=1;while((k<<1)<=n) k<<=1;
    int cnt=k,j;
    for(j=0;j<S[now].size();j++){
        int x=S[now][j];
        Ans[x]=k;vis[k]=1;
        k++;if(k==n+1) break;
    }
    int sheng=S[now].size()-j-1;
    cnt--;
    // printf("sheng=%d\n",sheng);
    if(sheng){
        for(int k=lg2[cnt];k>=0;k--){
            if(sheng<(1<<k)) continue;
            int l=(1<<k),r=(1<<(k+1))-1;
            for(int o=l;o<=r;o++){
                j++;int x=S[now][j];
                Ans[x]=o;sheng--;
                vis[o]=1;
            }
        }
    }
    now^=1;
    j=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int x=S[now][j];
        Ans[x]=i;j++;
    }
}

inline void Print(){
    for(int i=1;i<=n;i++){
        printf("%d ",Ans[i]);
    }puts("");
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    lg2[0]=-1;for(int i=1;i<=200000;i++) lg2[i]=lg2[i>>1]+1;
    read(t);
    while(t--){
        Init();Solve();Print();Clear();
    }
    return 0;
}