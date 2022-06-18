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
}li[N];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,a[N],b[N],id[N],ans[N];
int root[N*20],tot;

struct Node{
    int Size,ls,rs;
}p[N*20];


#define ls(k) p[k].ls
#define rs(k) p[k].rs

inline void PushUp(int k){
    p[k].Size=p[ls(k)].Size+p[rs(k)].Size;
}

inline void Change(int &k,int l,int r,int w,int x){
    if(!k) k=++tot;
    if(l==r){p[k].Size+=x;return;}
    int mid=(l+r)>>1;
    if(w<=mid) Change(ls(k),l,mid,w,x);
    else if(w>mid) Change(rs(k),mid+1,r,w,x);
    PushUp(k);
}

inline void Merge(int &a,int b,int l,int r){
    if(!a||!b){a=a+b;return;}
    if(l==r){p[a].Size+=p[b].Size;return;}
    int mid=(l+r)>>1;
    Merge(ls(a),ls(b),l,mid);
    Merge(rs(a),rs(b),mid+1,r);
    PushUp(a);
}

inline int Ask(int k,int l,int r,int rk){
    // printf("k=%d l=%d r=%d",k,l,r);
    // printf("p[k].size=%d\n",p[k].Size);
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(p[rs(k)].Size>=rk) return Ask(rs(k),mid+1,r,rk);
    else return Ask(ls(k),l,mid,rk-p[rs(k)].Size);
}

typedef pair<int,int> P;
vector<P> v[N];

inline void dfs(int k,int fa){
    // printf("k=%d\n",k);
    Change(root[k],1,n,a[k],1);
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        dfs(to,k);
        Merge(root[k],root[to],1,n);
    }
    // printf("nowk=%d\n",k);
    for(P now:v[k]){
        // printf("ask=%d\n",Ask(root[k],1,n,now.first));
        // printf("fi=%d\n",now.first);
        ans[now.second]=id[Ask(root[k],1,n,now.first)];
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){read(a[i]);b[i]=a[i];}
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    sort(b+1,b+n+1);int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++){
        int rk=lower_bound(b+1,b+len+1,a[i])-b;
        id[rk]=a[i];a[i]=rk;
    }
    for(int i=1;i<=m;i++){
        int k,rk;read(k);read(rk);
        v[k].push_back(make_pair(rk,i));
    }
    dfs(1,0);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}