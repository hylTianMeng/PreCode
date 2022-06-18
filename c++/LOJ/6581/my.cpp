#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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
    int to,next,from;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;li[tail].from=from;
}

int n,m,dfn[N],low[N],tot;
bool bridge[N<<1];
vector<int> edcc[N];

inline void Tarjan(int k,int inedge){
    dfn[k]=low[k]=++tot;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(!dfn[to]){
            Tarjan(to,x);low[k]=min(low[k],low[to]);
            if(low[to]>dfn[k]){
                bridge[x]=bridge[x^1]=1;
                // printf("x=%d",x);
            }
        }
        else if(x!=(inedge^1)) low[k]=min(low[k],dfn[to]);
    }
}

int dcc,c[N],Size[N];
bool vis[N];

inline void dfs(int k){
    vis[k]=1;Size[dcc]++;c[k]=dcc;
    edcc[dcc].push_back(k);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(vis[to]||bridge[x]) continue;
        dfs(to);
    }
}

vector<int> v[N],v2[N];
int d[N];
typedef pair<int,int> P;
vector<P> ans;
vector<int> vv;

int f[N];

inline void dp1(int k,int fa){
    vis[k]=1;vv.push_back(k);
    for(int to:v[k]){
        if(to==fa) continue;
        dp1(to,k);f[k]+=f[to];
    }
    if(Size[k]>1) f[k]++;
}

inline void dfs2(int k,int fa){
    int cuttot=0;
    for(int to:v[k]){
        if(to==fa) continue;
        dfs2(to,k);if(d[to]==1) cuttot++;
    }
    if(cuttot==d[k]-1){
        d[k]=1;return;
    }
    else{
        // if(k==c[214]||k==c[212]){
        //     printf("cuttot=%d\n",cuttot);
        //     printf("fa=%d\n",fa);
        //     printf("k=%d\n",k);
        //     printf("c=%d\n",c[k]);
        //     printf("d=%d\n",d[k]);
        // }
        for(int i=0;i<v[k].size();i++){
            int to=v[k][i],x=v2[k][i];
            if(d[to]==1){
                // printf("to=%d\n",to);
                ans.push_back(make_pair(li[x].from,li[x].to));
                // if(li[x].from==214&&li[x].to==212){
                //     printf("c[214]=%d c[212]=%d\n",c[214],c[212]);
                //     printf("to=%d\n",to);
                //     printf("d[to]=%d\n",d[to]);
                //     puts("FADSFA");
                // }
            }
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,0);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dcc++;dfs(i);
    }
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;
            if(c[i]==c[to]) continue;
            v[c[i]].push_back(c[to]);d[c[to]]++;
            v2[c[i]].push_back(x);
        }
    }
    // for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
    for(int i=1;i<=dcc;i++) if(Size[i]>1) d[i]=INF;

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=dcc;i++){
        // printf("i=%d\n",i);
        if(vis[i]) continue;
        vector<int>().swap(vv);
        dp1(i,0);int op=0;
        // printf("here\n");
        for(int j=0;j<vv.size();j++){
            int to=vv[j];
            if(f[to]>0){op=to;break;}
        }
        // printf("op=%d\n",(int)op);
        if(!op){
            for(int j=0;j<(int)vv.size();j++){
                int to=vv[j];
                if(d[to]==1){
                    int k=edcc[to][0];
                    for(int x=head[k];x;x=li[x].next){
                        int to=li[x].to;
                        ans.push_back(make_pair(k,to));
                        // if(k==214&&to==212){puts("fjdasl");}
                    }
                }
            }
        }
        else{
            for(int j=0;j<vv.size();j++){
                if(Size[vv[j]]>1){op=vv[j];break;}
            }
            dfs2(op,0);
        }
    }

    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(P now:ans){
        printf("%d %d\n",now.first,now.second);
    }
    return 0;
}