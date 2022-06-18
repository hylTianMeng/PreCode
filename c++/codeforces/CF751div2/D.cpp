#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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
    int to,next,w;
    inline void Init(int to_,int ne_,int w_){
        to=to_;next=ne_;w=w_;
    }
}li[20*N];
int head[5*N],tail,tot,rt,rk[N*5];
int id[N],n,a[N],b[N],ID[N],at,flag;
int d[N*5],s,nowtot;
bool vis[N*5];
pair<int,int> Pre[N*5];
typedef pair<int,int> P;
pair<int,P> ans[N*5];

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

#define ls(k) p[k].ls
#define rs(k) p[k].rs

struct Node{
    int ls,rs;
}p[N<<2];

inline int Build(int l,int r){
    if(l==r){
        ++tot;id[l]=tot;rk[tot]=l;
        if(l==0) flag=tot;
        return tot;
    }
    tot++;int k=tot;
    int mid=(l+r)>>1;
    ls(k)=Build(l,mid);rs(k)=Build(mid+1,r);
    Add(k,ls(k),0);Add(k,rs(k),0);
    return k;
}

inline void Find(int k,int now,int l,int r,int z,int y){
    if(l==z&&r==y){Add(now,k,1);return;}
    int mid=(l+r)>>1;
    if(y<=mid) Find(ls(k),now,l,mid,z,y);
    else if(z>mid) Find(rs(k),now,mid+1,r,z,y);
    else{Find(ls(k),now,l,mid,z,mid);Find(rs(k),now,mid+1,r,mid+1,y);}
}

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
}

inline void Mapping(){
    nowtot=tot;
    for(int i=1;i<=n;i++){
        ID[i]=++tot;
    }
    // for(int i=1;i<=n;i++) printf("id[%d]=%d\n",i,id[i]);
    for(int i=1;i<=n;i++) Add(id[i],ID[i+b[i]],0);
    for(int i=1;i<=n;i++){
        Find(rt,ID[i],0,n,i-a[i],i);
    }
}

deque<int> q;
inline void bfs(){
    memset(d,INF,sizeof(d));
    d[s]=0;
    q.push_back(s);
    while(q.size()){
        int top=q.front();q.pop_front();
        if(vis[top]) continue;
        vis[top]=1;
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,w=li[x].w;
            if(d[to]<=d[top]+w) continue;
            d[to]=d[top]+w;Pre[to]=make_pair(top,w);
            if(w) q.push_back(to);
            else q.push_front(to);
        }
    }
}

inline void Print(){
    if(d[id[0]]==INF){puts("-1");return;}
    printf("%d\n",d[id[0]]);
    int now=id[0];
    while(now){
        P pre=Pre[now];
        ans[++at]=make_pair(pre.first,make_pair(pre.second,now));
        now=pre.first;
    }
    reverse(ans+1,ans+at+1);
    // printf("flag=%d\n",flag);printf("id[0]=%d\n",id[0]);
    bool op=0;
    for(int i=1;i<=at;i++){
        if(ans[i].second.first) op=1;
        if(rk[ans[i].second.second]||ans[i].second.second==flag){
            op=0;printf("%d ",rk[ans[i].second.second]);
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    
    // printf("Complete Initing\n");
    Init();rt=Build(0,n);Mapping();
    s=ID[n];bfs();Print();
}