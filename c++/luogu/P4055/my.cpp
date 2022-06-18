#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 110
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
    int from,to,next;
    inline void Init(int fr_,int to_,int ne_){
        from=fr_;to=to_;next=ne_;
    }
}li[(N*N)<<2];
int head[N*N],tail;

inline void Add(int from,int to){
    li[++tail].Init(from,to,head[from]);
    head[from]=tail;
}

int n,m;
char a[N][N];
inline char GetChar(){
    char c=getchar();
    while(c!='#'&&c!='.'){
        c=getchar();
    }
    return c;
}

const int fx[]={0,0,0,1,-1};
const int fy[]={0,1,-1,0,0};
vector<int> L,R;

inline int ID(int x,int y){
    return (x-1)*m+y;
}

inline pair<int,int> PID(int x){
    int a=x/m+1,b=x%m;
    if(b==0){a--;b+=m;}
    return make_pair(a,b);
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=GetChar();
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#') continue;
            if((i+j)&1) R.push_back(ID(i,j));
            else L.push_back(ID(i,j));
            for(int k=1;k<=4;k++){
                int dx=i+fx[k],dy=j+fy[k];
                if(a[dx][dy]=='#'||dx>n||dy>m||dx<=0||dy<=0) continue;
                Add(ID(i,j),ID(dx,dy));
                // printf("Add edge: %d %d\n",ID(i,j),ID(dx,dy));
            }
        }
    // puts("L");
    for(int i=1;i<=n;i++){
        
    }
    // for(int i:L) printf("%d ",i);
    // puts("\nR");
    // for(int i:R) printf("%d ",i);puts("");
}

int Match[N*N];
bool vis[N*N],Not[N*N],Ans[N*N];

inline bool dfs(int k){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!vis[to]){
            vis[to]=1;
            if(!Match[to]||dfs(Match[to])){
                Match[to]=k;Match[k]=to;
                return 1;
            }
        }
    }
    return 0;
}

inline void Dfs(int k){
    vis[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[Match[to]]) continue;
        Ans[Match[to]]=0;Dfs(Match[to]);
    }
}

vector<int> ans;

inline void Solve(){
    for(int i:L){
        dfs(i);
        memset(vis,0,sizeof(vis));
    }
    // puts("Match");
    // for(int i:R){
    //     printf("Match[%d]=%d\n",i,Match[i]);
    // }
    // for(int i:L){
    //     printf("Match[%d]=%d\n",i,Match[i]);
    // }
    for(int i:R){
        if(!Match[i]) continue;
        Not[Match[i]]=1;Not[i]=1;
    }
    memset(Ans,1,sizeof(Ans));
    for(int i:L){if(!Not[i]) Ans[i]=0;}
    for(int i:R){if(!Not[i]) Ans[i]=0;}
    for(int i:L){
        if(Not[i]) continue;
        if(vis[i]) continue;
        Dfs(i);
    }
    for(int i:R){
        if(Not[i]) continue;
        if(vis[i]) continue;
        Dfs(i);
    }
    // for(int i:L) printf("Ans[%d]=%d\n",i,Ans[i]);
    // for(int i:R) printf("Ans[%d]=%d\n",i,Ans[i]);
    bool op=0;
    for(int i:L){
        if(!Ans[i]){op=1;break;}
    }
    for(int i:R){
        if(!Ans[i]){op=1;break;}
    }
    if(!op){puts("LOSE");exit(0);}
    if(op){
        puts("WIN");
        for(int i:L){
            if(!Ans[i]) ans.push_back(i);
        }
        for(int i:R){
            if(!Ans[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(int i:ans){
            printf("%d %d\n",PID(i).first,PID(i).second);
        }
        return;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}