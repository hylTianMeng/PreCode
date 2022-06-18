#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 16
#define M N*N*N*N
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int to,next,f;
    inline void Init(int to_,int ne_,int f_){
        to=to_;next=ne_;f=f_;
    }
}li[M*16];
int head[M],tail=1,now[M];

inline void Add(int from,int to){
    li[++tail].Init(to,head[from],1);
    head[from]=tail;swap(from,to);
    li[++tail].Init(to,head[from],0);
    head[from]=tail;
}

bool sol[N][N];
int n,m,k,s,t;

const int fx[]={0,-2,-1,1,2,2,1,-1,-2};
const int fy[]={0,1,2,2,1,-1,-2,-2,-1};

inline void Init(){
    read(n);read(m);read(k);
    for(int i=1;i<=k;i++){
        int a,b;read(a);read(b);
        sol[a][b]=1;
    }
}

namespace Work1{
    inline int ID(int x,int y){
        return (x-1)*n+y;
    }

    inline pair<int,int> PID(int x){
        int a=x/n+1,b=x%n;
        if(b==0){a--;b+=n;}
        return make_pair(a,b);
    }

    vector<int> L,R;

    inline void Build(){
        s=n*n+1;t=n*n+2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sol[i][j]) continue;
                if((i+j)&1) R.push_back(ID(i,j));
                else L.push_back(ID(i,j));
                if((i+j)&1) continue;
                for(int k=1;k<=8;k++){
                    int dx=i+fx[k],dy=j+fy[k];
                    if(sol[dx][dy]||dx<=0||dy<=0||dx>n||dy>n) continue;
                    Add(ID(i,j),ID(dx,dy));
                    // printf("Add edge %d %d\n",ID(i,j),ID(dx,dy));
                }
            }
        }
        for(int i:L) Add(s,i);
        for(int i:R) Add(i,t);
        // printf("Compelete Initing\n");
        // puts("L:");
        // for(int i:L) printf("%d ",i);
        // puts("\nR:");
        // for(int i:R) printf("%d ",i);puts("");
    }

    int d[M];
    queue<int> q;
    inline bool bfs(){
        // printf("here\n");
        memset(d,0,sizeof(d));
        while(q.size()) q.pop();
        q.push(s);d[s]=1;now[s]=head[s];
        while(q.size()){
            int top=q.front();q.pop();
            for(int x=head[top];x;x=li[x].next){
                int to=li[x].to,f=li[x].f;
                if(d[to]||!f) continue;
                q.push(to);d[to]=d[top]+1;
                now[to]=head[to];if(to==t) return 1;
            }
        }
        return d[t];
    }

    inline int dinic(int k,int flow){
        if(k==t) return flow;
        int rest=flow,x;
        for(x=now[k];x&&rest;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(d[to]!=d[k]+1||!f) continue;
            int val=dinic(to,Min(flow,f));
            if(!val) d[to]=0;
            li[x].f-=val;li[x^1].f+=val;rest-=val;
        }
        now[k]=x;return flow-rest;
    }

    bool Ans[M],vis[M];

    inline void dfs(int k,int c,int now){
        vis[k]=1;
        if(now==c) Ans[k]=0;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(f!=c||vis[to]) continue;
            dfs(to,c,now^1);
        }
    }

    inline void Solve(){
        int ans=0;
        while(bfs()) ans+=dinic(s,INF);
        // printf("ans=%d\n",ans);
        for(int i:L) Ans[i]=1;
        for(int i:R) Ans[i]=1;
        // printf("Ans[1]=%d\n",Ans[1]);
        dfs(s,1,0);memset(vis,0,sizeof(vis));
        dfs(t,0,1);
        int res=0;
        for(int i=1;i<=n*n;i++) if(Ans[i]) res++;
        printf("%d\n",res);
    }
};

namespace Work2{

    vector<int> L,R;
    int id[N][N][N][N],tot;
    
    inline void Trans(int &a,int &b,int &c,int &d){
        if(make_pair(a,b)>make_pair(c,d)){swap(a,c);swap(b,d);}
    }

    inline void Build(){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(sol[i][j]) continue;
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++){
                        if(sol[k][l]) continue;
                        if(make_pair(i,j)>=make_pair(k,l)) continue;
                        id[i][j][k][l]=++tot;
                        // printf("id[%d][%d][%d][%d]=%d\n",i,j,k,l,id[i][j][k][l]);
                        if((i+j+k+l)&1) R.push_back(tot);
                        else L.push_back(tot);
                    }
            }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sol[i][j]) continue;
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=n;l++){
                        if(sol[k][l]) continue;
                        if(make_pair(i,j)>=make_pair(k,l)) continue;
                        if((i+j+k+l)&1) continue;
                        for(int q=1;q<=8;q++){
                            int x=k,y=l;
                            int dx=i+fx[q],dy=j+fy[q];
                            if(sol[dx][dy]||(dx==x&&dy==y)||dx<=0||dy<=0||dx>n||dy>n) continue;
                            Trans(x,y,dx,dy);
                            Add(id[i][j][k][l],id[x][y][dx][dy]);
                            // printf("%d %d\n",id[i][j][k][l],id[x][y][dx][dy]);
                        }
                        for(int q=1;q<=8;q++){
                            int x=i,y=j;
                            int dx=k+fx[q],dy=l+fy[q];
                            if(sol[dx][dy]||(dx==x&&dy==y)||dx<=0||dy<=0||dx>n||dy>n) continue;
                            Trans(x,y,dx,dy);
                            Add(id[i][j][k][l],id[x][y][dx][dy]);
                            // printf("%d %d\n",id[i][j][k][l],id[x][y][dx][dy]);
                        }
                    }
                }
            }
        }
        s=++tot;t=++tot;
        for(int i:L) Add(s,i);
        for(int i:R) Add(i,t);
        // puts("L:");for(int i:L) printf("%d ",i);printf("\nsize=%d",L.size());
        // puts("\nR:");for(int i:R) printf("%d ",i);printf("\nsize=%d\n",R.size());
    }

    int d[M];
    queue<int> q;
    inline bool bfs(){
        // printf("here\n");
        memset(d,0,sizeof(d));
        while(q.size()) q.pop();
        q.push(s);d[s]=1;now[s]=head[s];
        while(q.size()){
            int top=q.front();q.pop();
            for(int x=head[top];x;x=li[x].next){
                int to=li[x].to,f=li[x].f;
                if(d[to]||!f) continue;
                q.push(to);d[to]=d[top]+1;
                now[to]=head[to];if(to==t) return 1;
            }
        }
        return d[t];
    }

    inline int dinic(int k,int flow){
        if(k==t) return flow;
        int rest=flow,x;
        for(x=now[k];x&&rest;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(d[to]!=d[k]+1||!f) continue;
            int val=dinic(to,Min(flow,f));
            if(!val) d[to]=0;
            li[x].f-=val;li[x^1].f+=val;rest-=val;
        }
        now[k]=x;return flow-rest;
    }

    bool Ans[M],vis[M];

    inline void dfs(int k,int c,int now){
        vis[k]=1;
        if(now==c) Ans[k]=0;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(f!=c||vis[to]) continue;
            dfs(to,c,now^1);
        }
    }

    inline void Solve(){
        int ans=0;
        while(bfs()) ans+=dinic(s,INF);
        // printf("ans=%d\n",ans);
        for(int i:L) Ans[i]=1;
        for(int i:R) Ans[i]=1;
        // printf("Ans[1]=%d\n",Ans[1]);
        dfs(s,1,0);memset(vis,0,sizeof(vis));
        dfs(t,0,1);
        int res=0;
        for(int i=1;i<=tot;i++) if(Ans[i]) res++;
        printf("%d\n",res);
    }
};

inline void Solve(){
    if(m==1){
        Work1::Build();Work1::Solve();
    }
    else{
        Work2::Build();Work2::Solve();
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}

