#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

inline int random(int n){
    return 1ll*rand()*rand()%n+1;
}

typedef pair<int,int> P;

struct Node{
    int val,ls,rs,cnt,id,key;
    P tag;
    inline void Print(){
        printf("val=%d ls=%d rs=%d cnt=%d id=%d tag=%d\n",val,ls,rs,cnt,id,tag.first);
    }
    inline Node(){}
    inline Node(int val,int ls,int rs,int cnt,int id,int key) : val(val),ls(ls),rs(rs),cnt(cnt),id(id),key(key) {}
}p[N];

int root,tot,ans[N];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct FHQ_Treap{
    inline int NewNode(int val,int id){
        ++tot;p[tot]=Node(val,0,0,0,id,random(INF));return tot;
    }
    inline void A(int k,P x){
        if(!k) return;
        p[k].val-=x.first;p[k].tag.first+=x.first;
        p[k].tag.second+=x.second;p[k].cnt+=x.second;
    }
    inline void PushDown(int k){
        if(p[k].tag.first){
            A(ls(k),p[k].tag);A(rs(k),p[k].tag);p[k].tag=make_pair(0,0);
        }
    }
    inline void Split(int k,int val,int &x,int &y){
        if(!k){x=y=0;return;}PushDown(k);
        // printf("split k=%d\n",k);p[k].Print();
        if(p[k].val<=val){x=k;Split(rs(k),val,rs(x),y);}
        else{y=k;Split(ls(k),val,x,ls(y));}
    }
    inline int Merge(int x,int y){
        PushDown(x);PushDown(y);if(!x||!y) return x+y;
        if(p[x].key<=p[y].key){ls(y)=Merge(x,ls(y));return y;}
        else{rs(x)=Merge(rs(x),y);return x;}
    }
    inline void Insert(int val,int id){
        int x,y;Split(root,val,x,y);root=Merge(Merge(x,NewNode(val,id)),y);
    }
    inline void Add(int &k,int q){
        int x,y;Split(k,p[q].val,x,y);k=Merge(Merge(x,q),y);
    }
    inline void dfs(int k,int c,int &rt){
        if(!k) return;PushDown(k);dfs(ls(k),c,rt);dfs(rs(k),c,rt);
        p[k].val-=c;p[k].cnt++;p[k].ls=p[k].rs=0;Add(rt,k);
    }
    inline void Opera(int c){
        // printf("c=%d\n",c);
        int x,y,z;Split(root,c-1,x,y);Split(y,2*c-1,y,z);A(z,make_pair(c,1));
        // printf("x=%d y=%d z=%d\n",x,y,z);
        // p[x].Print();p[y].Print();p[z].Print();
        dfs(y,c,x);
        // printf("now x is %d\n",x); p[x].Print();
        root=Merge(x,z);
    }
    inline void dfs2(int k){
        if(!k) return;PushDown(k);ans[p[k].id]=p[k].cnt;
        dfs2(ls(k));dfs2(rs(k));
    }
}tr;

struct node{
    int c,q;
    inline node(){}
    inline node(int c,int q) : c(c),q(q) {}
    inline bool operator < (const node &b) const{
        if(q!=b.q) return q>b.q;
        return c<b.c;
    }
}a[N];

int n,m;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++){read(a[i].c);read(a[i].q);}read(m);
    for(int i=1;i<=m;i++){
        int x;read(x);tr.Insert(x,i);
    }
    // printf("root=%d\n",root);p[root].Print();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        tr.Opera(a[i].c);
        // tr.dfs2(root);
        // for(int j=1;j<=m;j++) printf("%d ",ans[j]);puts("");
        // p[1].Print();p[2].Print();
        // printf("_______________\n");
    }
    tr.dfs2(root);
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}