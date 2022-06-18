#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30000010
#define M number
using namespace std;

const int INF=2147483647;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct Node{
    int val,size,ls,rs,key;
    inline Node(){}
    inline Node(int val,int size,int ls,int rs,int key) : val(val),size(size),ls(ls),rs(rs),key(key) {}
    inline void Print(){
        printf("%d %d %d %d %d\n",val,size,ls,rs,key);
    }
};

Node p[N];
int tot,root[N],rt;

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct FHQ_Treap{
    inline int NewNode(int val){
        ++tot;p[tot]=Node(val,1,0,0,random(INF));return tot;
    }
    inline void PushUp(int k){p[k].size=p[ls(k)].size+p[rs(k)].size+1;}
    inline void Split(int k,int val,int &x,int &y){
        if(!k){x=y=0;return;}
        if(p[k].val<=val){x=k;Split(rs(k),val,rs(k),y);}
        else{y=k;Split(ls(k),val,x,ls(y));}PushUp(k);
    }
    inline int Merge(int x,int y){
        if(!x||!y) return x+y;
        if(p[x].key<=p[y].key){ls(y)=Merge(x,ls(y));PushUp(y);return y;}
        else{rs(x)=Merge(rs(x),y);PushUp(x);return x;}
    }
    inline void Split_(int k,int val,int &x,int &y){
        // printf("k=%d\n",k);printf("ls=%d rs=%d\n",ls(k),rs(k));
        if(!k){x=y=0;return;}
        if(p[k].val<=val){++tot;p[tot]=p[k];x=tot;Split_(rs(x),val,rs(x),y);PushUp(x);}
        else{++tot;p[tot]=p[k];y=tot;Split_(ls(y),val,x,ls(y));PushUp(y);}
    }
    inline int Merge_(int x,int y){
        if(!x||!y) return x+y;
        if(p[x].key<=p[y].key){int k=++tot;p[k]=p[y];ls(k)=Merge_(x,ls(k));PushUp(k);return k;}
        else{int k=++tot;p[k]=p[x];rs(k)=Merge_(rs(k),y);PushUp(k);return k;}
    }
    inline void Insert(int last,int val,int id){
        int x,y;Split_(root[last],val,x,y);root[id]=Merge_(Merge_(x,NewNode(val)),y);
    }
    inline void Delete(int last,int val,int id){
        int x,y,z;Split_(root[last],val-1,x,y);
        Split_(y,val,y,z);if(y) y=Merge_(ls(y),rs(y));
        root[id]=Merge_(Merge_(x,y),z);
    }
    inline int GetRank(int last,int val,int id){
        root[id]=root[last];int x,y;Split(root[id],val-1,x,y);int ans=p[x].size+1;
        root[id]=Merge(x,y);return ans;
    }
    inline int GetVal(int last,int rank,int id){
        root[id]=root[last];int k=root[id];
        // printf("root[%d]=%d\n",id,root[id]);
        // printf("ls=%d rs=%d val=%d\n",ls(k),rs(k),p[k].val);
        // printf("%d\n",p[1].val);
        while(k){
            if(p[ls(k)].size+1==rank) return p[k].val;
            else if(p[ls(k)].size+1>rank) k=ls(k);
            else{rank-=p[ls(k)].size+1;k=rs(k);}
        }return INF-3;
    }
    inline int GetNext(int last,int val,int id){
        root[id]=root[last];int x,y;Split(root[id],val,x,y);
        int k=y;while(ls(k)) k=ls(k);int ans;if(!k) ans=INF;else ans=p[k].val;
        root[id]=Merge(x,y);return ans;
    }
    inline int GetPre(int last,int val,int id){
        root[id]=root[last];int x,y;Split(root[id],val-1,x,y);
        int k=x;while(rs(k)) k=rs(k);int ans;if(!k) ans=-INF;else ans=p[k].val;
        root[id]=Merge(x,y);return ans;
    }
}tr;

int n;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        int last,op,val;
        read(last);read(op);read(val);
        if(op==1) tr.Insert(last,val,i);
        else if(op==2) tr.Delete(last,val,i);
        else if(op==3) printf("%d\n",tr.GetRank(last,val,i));
        else if(op==4) printf("%d\n",tr.GetVal(last,val,i));
        else if(op==5) printf("%d\n",tr.GetPre(last,val,i));
        else if(op==6) printf("%d\n",tr.GetNext(last,val,i));
    }
    return 0;
}