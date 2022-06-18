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
        A(ls(k),p[k].Lazy1,p[k].Lazy2);A(rs(k),p[k].Lazy1,p[k].Lazy2+p[k].Lazy1*(p[ls(k)].Size+1));p[k].Lazy1=p[k].Lazy2=0;
    }
    inline void A(int k,int lz1,int lz2){
        p[k].Lazy1+=lz1;p[k].Lazy2+=lz2;p[k].val+=lz2+lz1*(p[ls(k)].Size+1);
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a+b;
        PushDown(a);PushDown(b);
        if(p[a].key<p[b].key){ls(b)=Merge(a,ls(b));PushUp(b);return b;}
        else{rs(a)=Merge(rs(a),b);PushUp(a);return a;}
    }
}tr;