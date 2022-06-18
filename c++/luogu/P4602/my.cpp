#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 100010
#define M 2000010
using namespace std;

const int INF=(1e18)+1;
const int Len=1e5;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Node{
    int SumP,SumL,ls,rs;
    inline Node(){}
    inline Node(int SumP,int SumL) : SumP(SumP),SumL(SumL) {}
};

int Root[N],rtt,tot;
Node p[M];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct Segment_Tree{
    inline int NewNode(){return ++tot;}
    inline void PushUp(int k){
        p[k].SumL=p[ls(k)].SumL+p[rs(k)].SumL;
        p[k].SumP=p[ls(k)].SumP+p[rs(k)].SumP;
    }
    inline void Insert(int &k,int last,int l,int r,int w,int P,int L){
        k=NewNode();p[k]=p[last];
        if(l==r){
            p[k].SumL+=L;p[k].SumP+=P*L;return;
        }
        int mid=(l+r)>>1;
        if(w<=mid) Insert(ls(k),ls(last),l,mid,w,P,L);
        else Insert(rs(k),rs(last),mid+1,r,w,P,L);
        PushUp(k);
    }
    inline int Binary(int k,int l,int r,int L){
        if(p[k].SumL<L) return INF;
        if(l==r){
            if(p[k].SumL<L) return INF;
            return p[k].SumP/p[k].SumL*L;
        }
        int mid=(l+r)>>1;
        if(p[ls(k)].SumL>=L) return Binary(ls(k),l,mid,L);
        else return p[ls(k)].SumP+Binary(rs(k),mid+1,r,L-p[ls(k)].SumL);
    }
}tr;

struct Juice{
    int jd,jp,jl;
    inline Juice(){}
    inline Juice(int jd,int jp,int jl) : jd(jd),jp(jp),jl(jl) {}
    inline bool operator < (const Juice &b)const{return jd>b.jd;}
}a[N];

int n,m;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i].jd);read(a[i].jp);read(a[i].jl);
    }
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++){
    //     printf("%lld %lld %lld\n",a[i].jd,a[i].jp,a[i].jl);
    // }puts("");
    for(int i=1;i<=n;i++){
        rtt++;
        tr.Insert(Root[rtt],Root[rtt-1],1,Len,a[i].jp,a[i].jp,a[i].jl);
    }
}

inline bool Check(int mid,int G,int L){
    int NowAns=tr.Binary(Root[mid],1,Len,L);
    return NowAns<=G;
}

inline int Binary(int G,int L){
    int l=1,r=n,ans=n+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(mid,G,L)){
            ans=mid;r=mid-1;
        }
        else l=mid+1;
    }
    // printf("ans=%lld\n",ans);
    return ans!=n+1?a[ans].jd:(-1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    for(int i=1;i<=m;i++){
        int G,L;read(G);read(L);
        int ans=Binary(G,L);
        printf("%lld\n",ans);
    }
    return 0;
}