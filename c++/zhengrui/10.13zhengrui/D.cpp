#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
//l+r 可能会超LongLong
#define uint unsigned int
#define ull unsigned long long
#define M 800010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

vector<int> e[M];

struct Node{
    int a,b,id;
    inline Node(){}
    inline Node(int a,int b,int id) : a(a),b(b),id(id) {}
    inline bool operator < (const Node &b)const{return a<b.a;}
}p[M];

struct Ques{
    int V,p,id;vector<int> s;
    inline bool operator < (const Ques &b)const{return V<b.V;}
}ques[M];

int n,m,K,Q;
int fa[M],tot,limit=(1ll<<31)-1,ans[M],cnt[M<<5],sum[M<<5];;
multiset<int> S;
bool vis[M];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

ll root[M],ls[M<<5],rs[M<<5];

inline int NewNode(){return ++tot;}
inline void PushUp(int k){sum[k]=sum[ls[k]]+sum[rs[k]];}

inline void Add(ll &k,int l,int r,int w,int x){
    if(!k) k=++tot;
    if(l==r){
        sum[k]=(((cnt[k]+=x)%=K)==0);
        return;
    }
    int mid=(l+r)>>1;
    if(w<=mid) Add(ls[k],l,mid,w,x);
    else Add(rs[k],mid+1,r,w,x);PushUp(k);
}

inline void Merge(ll &x,int y,int l,int r){
    if(!x||!y){x|=y;return;}
    if(l==r){
        sum[x]=(((cnt[x]+=cnt[y])%=K)==0);
        return;
    }
    int mid=(l+r)>>1;
    Merge(ls[x],ls[y],l,mid);Merge(rs[x],rs[y],mid+1,r);
    PushUp(x);
}

inline void Init(){
    read(n);read(m);read(K);
    for(int i=1;i<=n;i++){read(p[i].a);p[i].id=i;}
    for(int i=1;i<=n;i++) read(p[i].b);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        e[from].push_back(to);e[to].push_back(from);
    }
    read(Q);
    for(int i=1;i<=Q;i++){
        read(ques[i].V);read(ques[i].p);ques[i].id=i;
        for(int j=1;j<=ques[i].p;j++){int x;read(x);ques[i].s.push_back(x);}
    }
    sort(ques+1,ques+Q+1);sort(p+1,p+n+1);
    // printf("Complete Initing.\n");
}

inline void Solve(){
    for(int i=1,j=1;i<=n+1;i++){
        // printf("i=%d\n",i);
        int now=-1;
        while(j<=Q&&(i==n+1||p[i].a>ques[j].V)){
            for(int k:ques[j].s)
                if(fa[k]&&!vis[now=Find(k)]) S.erase(S.find(-sum[root[now]])),vis[now]=1;
            ans[ques[j].id]=-*S.begin();
            for(int k:ques[j].s)
                if(fa[k]&&vis[now=Find(k)]) S.insert(-sum[root[now]]),vis[now]=0;
            j++;
        }
        if(i==n+1) break;
        int id=p[i].id;fa[id]=id;
        Add(root[id],1,limit,p[i].b,1);S.insert(-sum[root[id]]);
        for(int to:e[id]){
            if(!fa[to]) continue;
            int u=Find(id),v=Find(to);if(u==v) continue;
            S.erase(S.find(-sum[root[u]]));S.erase(S.find(-sum[root[v]]));
            fa[v]=u;
            Merge(root[u],root[v],1,limit);
            S.insert(-sum[root[u]]);
        }
    }
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    Solve();
    return 0;
}
/*
5 4 2
3 7 2 5 4
1 3 3 2 2
1 3
1 2
1 4
1 5
5
4 0
4 1 3
1 0
5 0
10 0
*/