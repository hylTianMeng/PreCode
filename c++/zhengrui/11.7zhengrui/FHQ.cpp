#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
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
// #define fre

inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct FHQ_Treap{
    #define ls p[k].l
    #define rs p[k].r
    struct node{
        int size,val,l,r,key,lazy;
        inline node(){}
        inline node(int size,int val,int l,int r,int key,int lazy) : size(size),val(val),l(l),r(r),key(key),lazy(lazy) {}
    }p[N];
    int tot,root;
    inline void Init(){tot=0;}
    inline int NewNode(int val){p[++tot]=node(1,val,0,0,random(INF),0);return tot;}
    inline void PushUp(int k){p[k].size=p[ls].size+p[rs].size+1;}
    inline void PushDown(int k){if(p[k].lazy){R(ls);R(rs);p[k].lazy=0;}}
    inline void Split(int k,int size,int &x,int &y){
        if(!k){x=0;y=0;return;}PushDown(k);
        if(p[ls].size+1<=size){x=k;Split(p[k].r,size-p[ls].size-1,p[x].r,y);PushUp(x);}
        else{y=k;Split(p[k].l,size,x,p[y].l);PushUp(y);}
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a+b;
        if(p[a].key<=p[b].key){PushDown(b);p[b].l=Merge(a,p[b].l);PushUp(b);return b;}
        else{PushDown(a);p[a].r=Merge(p[a].r,b);PushUp(a);return a;}
    }
    inline void Insert(int posi,int val){
        int x,y;Split(root,posi-1,x,y);root=Merge(Merge(x,NewNode(val)),y);
    }
    inline void R(int k){swap(ls,rs);p[k].lazy^=1;}
    inline void Reverse(int l,int r){
        int x,y,z;Split(root,l-1,x,y);Split(y,r-l+1,y,z);R(y);root=Merge(Merge(x,y),z);
    }
    inline void Print(int k){
        if(!k) return;PushDown(k);Print(p[k].l);printf("%d ",p[k].val);Print(p[k].r);
    }
    inline void TreePrint(){Print(root);}
}tr;

int n,m;

int main(){
    #ifdef fre
        freopen("my.in","r",stdin);
        freopen("my.out","w",stdout);
    #endif
    read(n);read(m);tr.Init();
    for(int i=1;i<=n;i++) tr.Insert(i,i);
    for(int i=1;i<=m;i++){
        int l,r;read(l);read(r);tr.Reverse(l,r);
    }
    tr.TreePrint();
    return 0;
}