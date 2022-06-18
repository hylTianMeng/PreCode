#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M 200010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m;
struct node{
    int l,r;
};
int root[N],fa[N*40],deep[N*40],tail;
node p[N*40];


struct kcjbcj{
    int size;
    inline int new_node(){
        size++;p[size].l=p[size].r=0;return size;
    }
    inline void build(int &k,int l,int r){
        k=new_node();
        if(l==r){fa[k]=l;return;}
        int mid=(l+r)>>1;build(p[k].l,l,mid);build(p[k].r,mid+1,r);
    }
    inline int getposi(int k,int l,int r,int x){
        if(l==r) return k;
        int mid=(l+r)>>1;
        if(x<=mid) return getposi(p[k].l,l,mid,x);
        else return getposi(p[k].r,mid+1,r,x);
    }
    inline int find(int k,int x){
        int now=getposi(k,1,n,x);
        if(fa[now]==x) return now;
        else return find(k,fa[now]);
    }
    inline void change(int &k,int last,int l,int r,int x,int val){
        k=new_node();
        p[k]=p[last];
        if(l==r){deep[k]=deep[last];fa[k]=val;return;}
        int mid=(l+r)>>1;
        if(x<=mid) change(p[k].l,p[last].l,l,mid,x,val);
        else change(p[k].r,p[last].r,mid+1,r,x,val);
    }
    inline void update(int &k,int last,int l,int r,int x){
//         if(l==r){deep[k]++;return;}
//         int mid=(l+r)>>1;
//         if(x<=mid) update(p[k].l,p[last].l,l,mid,x);
//         else update(p[k].r,p[last].r,mid+1,r,x);
        k=new_node();p[k]=p[last];
        if(l==r){fa[k]=fa[last];deep[k]=deep[last]+1;return;}
        int mid=(l+r)>>1;
        if(x<=mid) update(p[k].l,p[last].l,l,mid,x);
        else update(p[k].r,p[last].r,mid+1,r,x);
    }
    
    inline bool merge(int &k,int a,int b){
        int faa=find(k,a),fab=find(k,b);
        if(fa[faa]==fa[fab]) return 0;
        if(deep[faa]>deep[fab]) swap(faa,fab);
        change(k,root[tail-1],1,n,fa[faa],fa[fab]);
        if(deep[faa]==deep[fab]) update(k,k,1,n,fa[fab]);
        return 1;
    }
    inline bool belong_to_the_same(int k,int a,int b){
        int faa=find(k,a),fab=find(k,b);
        return fa[faa]==fa[fab];
    }
};
kcjbcj bcj;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    bcj.build(root[0],1,n);
    for(int i=1;i<=m;i++){
        int op;read(op);
        if(op==1){
            int a,b;read(a);read(b);tail++;root[tail]=root[tail-1];
            bcj.merge(root[tail],a,b);
        }
        else if(op==2){
            int k;read(k);tail++;
            root[tail]=root[k];
        }
        else if(op==3){
            int a,b;read(a);read(b);tail++;root[tail]=root[tail-1];
            printf("%d\n",(int)bcj.belong_to_the_same(root[tail],a,b));
        }
    }
    return 0;
}
