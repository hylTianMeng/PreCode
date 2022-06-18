#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int fa[N],Root[N],tot,P[N];

inline int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct Node{
    int ls,rs,val,Size,key;
    inline Node(){}
    inline Node(int ls,int rs,int val,int Size,int key) : ls(ls),rs(rs),val(val),Size(Size),key(key) {}
}p[N];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct FHQ_Treap{
    inline int NewNode(int val){++tot;p[tot]=Node(0,0,val,1,random(INF));return tot;}
    inline void PushUp(int k){p[k].Size=p[ls(k)].Size+p[rs(k)].Size+1;}
    inline void Split(int k,int &x,int &y,int val){
        if(!k){x=0;y=0;return;}
        if(p[k].val<=val){x=k;Split(rs(k),rs(x),y,val);PushUp(x);}else{y=k;Split(ls(k),x,ls(y),val);PushUp(y);}
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a+b;
        if(p[a].key>p[b].key){rs(a)=Merge(rs(a),b);PushUp(a);return a;}
        else{ls(b)=Merge(a,ls(b));PushUp(b);return b;}
    }
    inline int Insert(int rt,int val){
        int x,y;Split(rt,x,y,val);
        // printf("here\n");printf("x=%d y=%d\n",x,y);
        return Merge(Merge(x,NewNode(val)),y);
    }
    inline int Insert(int rt,int val,int now){
        int x,y;Split(rt,x,y,val);p[now].ls=p[now].rs=0;p[now].Size=1;
        return Merge(Merge(x,now),y);
    }
    inline int GetVal(int k,int rank){
        if(!k) return -1;
        if(p[ls(k)].Size+1==rank) return k;
        else if(p[ls(k)].Size+1<rank) return GetVal(rs(k),rank-p[ls(k)].Size-1);
        else return GetVal(ls(k),rank);
    }
    inline void Dfs(int k,int &rt){
        if(ls(k)) Dfs(ls(k),rt);
        if(rs(k)) Dfs(rs(k),rt);
        rt=Insert(rt,p[k].val,k);
    }
    inline int MergeTree(int rt1,int rt2){
        if(p[Root[rt1]].Size>p[Root[rt2]].Size) swap(rt1,rt2);
        Dfs(Root[rt1],Root[rt2]);fa[rt1]=rt2;return rt2;
    }
    inline void Init(int n){
        for(int i=1;i<=n;i++){
            fa[i]=i;Root[i]=Insert(Root[i],P[i]);
        }
    }
}tr;

int n,m,q;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(P[i]);
    // printf("here\n");
    tr.Init(n);
    // printf("here\n");
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        if(from==0||to==0) continue;
        int faf=Find(from),fato=Find(to);
        tr.MergeTree(faf,fato);
    }
    read(q);
}

inline char GetChar(){
    char c=getchar();
    while(c!='B'&&c!='Q') c=getchar();
    return c;
}

signed main(){
    // freopen("P3224_10.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    // printf("here\n");
    for(int i=1;i<=q;i++){
        char c;c=GetChar();
        int A,B;read(A);read(B);
        if(c=='B'){
            if(A==0||B==0) continue;
            int faa=Find(A),fab=Find(B);
            if(faa==fab) continue;
            tr.MergeTree(faa,fab);
        }
        else{
            if(A==0||B==0){puts("-1");continue;}
            int faa=Find(A);
            printf("%d\n",tr.GetVal(Root[faa],B));
        }
    }
    return 0;
}