#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 20000000
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int len=1000000;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Node{
    int ls,rs,Size,sum;
    inline Node(){}
    inline Node(int ls,int rs,int Size,int sum) : ls(ls),rs(rs),Size(Size),sum(sum) {}
}p[N];

int tot,root[N],n,m,a[N];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct SegmentTree{
    inline void PushUp(int k){
        p[k].sum=p[ls(k)].sum+p[rs(k)].sum;
        p[k].Size=p[ls(k)].Size+p[rs(k)].Size;
    }
    inline void Insert(int &k,int last,int l,int r,int w,int val){
        k=++tot;p[k]=p[last];
        if(l==r){p[k].sum+=w;p[k].Size++;return;}int mid=(l+r)>>1;
        if(w<=mid) Insert(ls(k),ls(last),l,mid,w,val);
        else Insert(rs(k),rs(last),mid+1,r,w,val);
        PushUp(k);
    }
    inline int Solve(int lk,int rk,int k,int l,int r,int rank){
        int nowsize=p[rk].Size-p[lk].Size,nowsum=p[rk].sum-p[lk].sum;
        // printf("lk=%d rk=%d k=%d l=%d r=%d rank=%d\n",lk,rk,k,l,r,rank);
        if(nowsize==0||nowsum==0) return 0;int mid=(l+r)>>1;
        if(l<=k+rank-1&&r<=k+rank+nowsize-2) return (2*k+2*rank+nowsize-3)*(nowsize)/2-nowsum;
        else if(l>=k+rank-1&&r>=k+rank+nowsize-2) return nowsum-(2*k+2*rank+nowsize-3)*(nowsize)/2;
        else return Solve(ls(lk),ls(rk),k,l,mid,rank)+Solve(rs(lk),rs(rk),k,mid+1,r,rank+p[ls(rk)].Size-p[ls(lk)].Size);
    }
}tr;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);tr.Insert(root[i],root[i-1],1,len,a[i],1);
    }
    for(int i=1;i<=m;i++){
        int l,r,k;read(l);read(r);read(k);
        printf("%lld\n",tr.Solve(root[l-1],root[r],k,1,len,1));
    }
    return 0;
}