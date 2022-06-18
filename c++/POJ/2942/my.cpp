#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

int a[N][N],n,m;
int dfn[N],low[N],Stack[N],top,c[N],root,dcctot,Size[N],col[N],tot;
vector<int> vdcc[N];
bool cut[N],vis[N],ans[N],sign[N];

inline void Tarjan(int k){
    // printf("k=%d\n",k);
    int child=0;
    dfn[k]=low[k]=++tot;Stack[++top]=k;bool op=0;
    for(int i=1;i<=n;i++) if(a[i][k]){op=1;break;}
    if(root==k&&!op){dcctot++;vdcc[dcctot].push_back(k);top--;c[k]=dcctot;Size[dcctot]++;}
    for(int i=1;i<=n;i++){
        if(!a[k][i]) continue;
        // printf("i=%d\n",i);
        if(!dfn[i]){
            Tarjan(i);low[k]=min(low[k],low[i]);
            // printf("i=%d low[i]=%d\n",i,low[i]);
            // printf("k=%d dfn[k]=%d\n",k,dfn[k]);
            if(low[i]>=dfn[k]){
                // printf("here\n");
                child++;
                if(k!=root||child>1) cut[k]=1;
                int val;dcctot++;
                do{
                    val=Stack[top--];c[val]=dcctot;vdcc[dcctot].push_back(val);Size[dcctot]++;
                }while(val!=i);vdcc[dcctot].push_back(k);Size[dcctot]++;
                c[k]=dcctot;
                // printf("dcctot=%d\n",dcctot);
            }
        }
        else low[k]=min(low[k],dfn[i]);
    }
}

inline bool dfs(int k,int dcc,int cc){
    vis[k]=1;col[k]=cc;
    for(int i=1;i<=n;i++){
        if(!a[i][k]||!sign[i]) continue;
        if(col[i]!=0){
            if(col[i]!=3-cc) return 0;
            continue;
        }
        if(!dfs(i,dcc,3-cc)) return 0;
    }
    return 1;
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
        // printf("n=%d m=%d\n",n,m);
        // read(n);read(m);
        memset(a,1,sizeof(a));
        for(int i=1;i<=m;i++){
            int from,to;read(from);read(to);a[from][to]=a[to][from]=0;
        }
        for(int i=1;i<=n;i++) a[i][i]=0;
        for(int i=1;i<=n;i++) if(!dfn[i]){root=i;Tarjan(i);}
        for(int i=1;i<=n;i++) if(cut[i]) c[i]=0;

        // for(int i=0;i<=dcctot;i++){
        //     for(int k:vdcc[i]) printf("%d ",k);puts("");
        // }
        // for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");

        for(int i=1;i<=n;i++){
            if(vis[i]||cut[i]) continue;
            if(Size[c[i]]==1){vis[i]=1;continue;}
            for(int k:vdcc[c[i]]) sign[k]=1;
            if(!dfs(i,c[i],1)){
                for(int j=0;j<vdcc[c[i]].size();j++) ans[vdcc[c[i]][j]]=1;
            }
            for(int j=1;j<=n;j++) c[j]=0;
            for(int j=1;j<=n;j++) sign[j]=0;
        }
        int Ans=0;
        for(int i=1;i<=n;i++) if(!ans[i]) Ans++;
        printf("%d\n",Ans);

        top=0;tot=0;dcctot=0;
        for(int i=1;i<=n;i++){
            dfn[i]=low[i]=0;Size[i]=0;col[i]=0;
            vdcc[i].clear();cut[i]=vis[i]=sign[i]=ans[i]=0;
        }
    }
    return 0;
}