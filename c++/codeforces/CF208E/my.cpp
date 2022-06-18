#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 400010
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

int n,fa[N][25],root,Son[N],Size[N],Dep[N],m;

struct Ques{
    int deep,sign,id;
    inline Ques(){}
    inline Ques(int deep,int sign,int id) : deep(deep),sign(sign),id(id) {}
};
vector<Ques> v[N];
typedef pair<int,int> P;
vector<P> ques[N];

inline int Get(int u,int k){
    for(int i=20;i>=0;i--){
        if((1<<i)>k) continue;
        u=fa[u][i];k-=(1<<i);
    }
    return u;
}

inline void dfs(int k){
    Dep[k]=Dep[fa[k][0]]+1;
    for(int i=1;i<=20;i++) fa[k][i]=fa[fa[k][i-1]][i-1];
    Size[k]=1;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;dfs(to);
        Size[k]+=Size[to];if(Size[Son[k]]<Size[to]) Son[k]=to;
    }
    // printf("k=%d\n",k);
    for(auto i:ques[k]){
        if(Get(k,i.first)==0) continue;
        v[Get(k,i.first)].push_back(Ques(Dep[k],1,i.second));
        // printf("k=%d Deep=%d op=%d id=%d\n",Get(k,i.first),Dep[k],1,i.second);
    }
}

int cnt[N],ans[N],ban;

inline void Add(int k){
    cnt[Dep[k]]++;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==ban) continue;
        Add(to);
    }
}

inline void Del(int k){
    cnt[Dep[k]]--;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        Del(to);
    }
}

inline void Dfs(int k,bool op){
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==Son[k]) continue;
        Dfs(to,0);
    }
    if(Son[k]){Dfs(Son[k],1);ban=Son[k];}
    Add(k);ban=-1;
    for(auto i:v[k]){
        ans[i.id]+=i.sign*cnt[i.deep];
    }
    if(!op){Del(k);}
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        int a;read(a);
        fa[i][0]=a;if(a) Add(a,i);
    }
    read(m);
    for(int i=1;i<=m;i++){
        int u,k;read(u);read(k);
        ques[u].push_back(make_pair(k,i));
    }
    for(int i=1;i<=n;i++){
        if(!fa[i][0]){dfs(i);Dfs(i,0);}
    }
    for(int i=1;i<=m;i++){
        printf("%d ",max(ans[i]-1,0));
    }
    return 0;
}