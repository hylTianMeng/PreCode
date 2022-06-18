#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000000
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int Len=100000;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

inline void GMax(ll &a,ll b){a=Max(a,b);}

struct Node{
    ll sum;
    int size,ls,rs;
    inline Node(){}
    inline Node(ll sum,int size,int ls,int rs) : sum(sum),size(size),ls(ls),rs(rs) {}
}p[N];

int root[N],tot,n,s,d,a[N],b[N];
ll ans=-INF;

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct segment_tree{
    inline void PushUp(int k){p[k].sum=p[ls(k)].sum+p[rs(k)].sum;p[k].size=p[ls(k)].size+p[rs(k)].size;}
    inline void Insert(int last,int &k,int l,int r,int w,int val){
        k=++tot;p[k]=p[last];
        if(l==r){p[k].sum+=val;p[k].size++;return;}
        int mid=(l+r)>>1;
        if(w<=mid) Insert(ls(last),ls(k),l,mid,w,val);
        else if(w>mid) Insert(rs(last),rs(k),mid+1,r,w,val);
        PushUp(k);
    }
    inline ll Query(int lk,int rk,int l,int r,int k){
        int rsize=p[rs(rk)].size-p[rs(lk)].size,mid=(l+r)>>1;ll rsum=p[rs(rk)].sum-p[rs(lk)].sum;
        if(l==r){
            if(p[rk].size==p[lk].size) return 0;
            return 1ll*(p[rk].sum-p[lk].sum)/(p[rk].size-p[lk].size)*Min(k,p[rk].size-p[lk].size);
        }
        if(rsize>=k) return Query(rs(lk),rs(rk),mid+1,r,k);
        else return Query(ls(lk),ls(rk),l,mid,k-rsize)+rsum;
    }
    inline void Clear(){
        memset(p,0,sizeof(p));memset(root,0,sizeof(root));tot=0;
    }
}tr;

inline ll Calc(int l,int r){
    int times=d-(2*(r-s)+s-l);if(times<0) return -INF;
    return tr.Query(root[l-1],root[r],1,Len,times);
}

inline void Solve(int l,int r,int z,int y){
    if(l>r||z>y) return;
    int mid=(l+r)>>1;
    int id=z;ll maxx=Calc(mid,z);
    for(int i=z+1;i<=y;i++){
        if(maxx<Calc(mid,i)){maxx=Calc(mid,i);id=i;}
    }
    GMax(ans,maxx);
    Solve(l,mid-1,z,id);Solve(mid+1,r,id,y);
}

inline void work(){
    tr.Clear();
    for(int i=1;i<=n;i++){
        tr.Insert(root[i-1],root[i],1,Len,a[i],b[a[i]]);
        // printf("a[i]=%d b[a[i]]=%d\n",a[i],b[a[i]]);
    }
    for(int i=1;i<=s;i++) GMax(ans,Calc(i,s));
    Solve(1,s,s+1,n);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(s);read(d);s++;
    for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
    sort(b+1,b+n+1);int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
    work();s=n-s+1;reverse(a+1,a+n+1);work();printf("%lld\n",ans);
    return 0;
}