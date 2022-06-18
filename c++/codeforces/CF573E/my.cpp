#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 100010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct Node{
    int ls,rs,val,Lazy1,Lazy2,Size,key;
    int maxx;
    inline Node(){ls=rs=val=Lazy1=Lazy2=Size=key=maxx=0;}
}p[N];

int rt,tot;

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct FHQ_Treap{
    inline FHQ_Treap(){NewNode(0);rt=1;}
    inline int NewNode(int val){
        ++tot;ls(tot)=rs(tot)=0;p[tot].Lazy1=p[tot].Lazy2=0;p[tot].Size=1;p[tot].key=random(INF);
        p[tot].val=val;p[tot].maxx=val;return tot;
    }
    inline void PushUp(int k){p[k].Size=p[ls(k)].Size+p[rs(k)].Size+1;}
    inline void PushDown(int k){
        if(!p[k].Lazy1&&!p[k].Lazy2) return;
        if(ls(k)) A(ls(k),p[k].Lazy1,p[k].Lazy2);
        if(rs(k)) A(rs(k),p[k].Lazy1,p[k].Lazy2+p[k].Lazy1*(p[ls(k)].Size+1));
        p[k].Lazy1=p[k].Lazy2=0;
    }
    inline void A(int k,int lz1,int lz2){
        if(!k) return;
        p[k].Lazy1+=lz1;p[k].Lazy2+=lz2;p[k].val+=lz2+lz1*(p[ls(k)].Size+1);
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a+b;
        PushDown(a);PushDown(b);
        if(p[a].key<p[b].key){ls(b)=Merge(a,ls(b));PushUp(b);return b;}
        else{rs(a)=Merge(rs(a),b);PushUp(a);return a;}
    }
    inline void Split(int k,int &x,int &y,int Size){
        if(!k){x=y=0;return;}
        PushDown(k);
        if(p[ls(k)].Size+1<=Size){x=k;Split(rs(k),rs(x),y,Size-p[ls(k)].Size-1);PushUp(x);}
        else{y=k;Split(ls(k),x,ls(y),Size);PushUp(y);}
    }
    inline void Insert(int res,int val){
        int x,y;Split(rt,x,y,res);rt=Merge(Merge(x,NewNode(val)),y);
    }
    inline void Add(int posi,int lz1,int lz2){
        int x,y;Split(rt,x,y,posi);
        A(y,lz1,lz2);rt=Merge(x,y);
    }
    inline int GetVal(int k,int rank){
        if(!k) return 0;PushDown(k);
        if(p[ls(k)].Size+1==rank) return p[k].val;
        else if(p[ls(k)].Size+1<rank) return GetVal(rs(k),rank-p[ls(k)].Size-1);
        else return GetVal(ls(k),rank);
    }
    inline int GetAns(int k){
        if(!k) return 0;
        int now=p[k].val;PushDown(k);
        return Max(Max(now,GetAns(ls(k))),GetAns(rs(k)));
    }
}tr;

int n;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int a;scanf("%lld",&a);
        int l=0,r=i-1,res=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(tr.GetVal(rt,mid+1)+a*(mid+1)>tr.GetVal(rt,mid+2)){
                res=mid;r=mid-1;
            }
            else l=mid+1;
        }
        int t=tr.GetVal(rt,res+1);
        tr.Insert(res+1,t);
        tr.Add(res+1,a,res*a);
    }
    printf("%lld\n",tr.GetAns(rt));
    return 0;
}