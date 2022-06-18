#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
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

struct ODTNode{
    int l,r,val;
    inline ODTNode(){}
    inline ODTNode(int l,int r,int val) : l(l),r(r),val(val) {}
    inline bool operator < (const ODTNode &b)const{return l<b.l;}
};
set<ODTNode> S;

int Col[N],n,q;

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    int p[N<<2],len[N<<2],tag[N<<2];
    inline void Build(int k,int l,int r){
        len[k]=r-l+1;
        if(l==r) return;
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);
    }
    inline void PushUp(int k){
        p[k]=p[ls(k)]+p[rs(k)];
    }
    inline void A(int k,int x){
        p[k]+=x*len[k];tag[k]+=x;
    }
    inline void PushDown(int k){
        if(tag[k]){
            A(ls(k),tag[k]);A(rs(k),tag[k]);tag[k]=0;
        }
    }
    inline void Update(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y){A(k,x);return;}
        int mid=(l+r)>>1;
        PushDown(k);
        if(y<=mid) Update(ls(k),l,mid,z,y,x);
        else if(z>mid) Update(rs(k),mid+1,r,z,y,x);
        else{Update(ls(k),l,mid,z,mid,x);Update(rs(k),mid+1,r,mid+1,y,x);}
        PushUp(k);
    }
    inline int Ask(int k,int l,int r,int w){
        if(l==r) return p[k];
        PushDown(k);
        int mid=(l+r)>>1;
        if(w<=mid) return Ask(ls(k),l,mid,w);
        else return Ask(rs(k),mid+1,r,w);
    }
}tr;

inline set<ODTNode>::iterator split(int x){
    if (x > n)
        return S.end();
    auto iter = --S.upper_bound(ODTNode(x, 0, 0));
    if (iter->l == x)
        return iter;
    int l = iter->l, r = iter->r;
    int v = iter->val;
    S.erase(iter);
    S.insert(ODTNode(l, x - 1, v));
    return S.insert(ODTNode(x, r, v)).first;
}

inline void assign(int l, int r, int v){
    // printf("here\n");
    auto itr = split(r + 1), itl = split(l);
    for(auto it=itl;it!=itr;it++){
        // printf("l=%d r=%d val=%d\n",(*it).l,(*it).r,Col[(*it).val]-Col[v]);
        tr.Update(1,1,n,(*it).l,(*it).r,Col[(*it).val]-Col[v]);
    }
    S.erase(itl, itr);
    S.insert(ODTNode(l, r, v));
}

inline int Find(int x){
    auto it=--S.upper_bound(ODTNode(x,0,0));
    return Col[(*it).val];
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    tr.Build(1,1,n);
    S.insert(ODTNode(1,n,1));
    for(int i=1;i<=q;i++){
        // printf("i=%d\n",i);
        string s;int l,r,x;
        cin>>s;
        if(s=="Color"){
            read(l);read(r);read(x);assign(l,r,x);
        }
        else if(s=="Add"){
            read(l);read(r);Col[l]+=r;
        }
        else if(s=="Query"){
            read(l);
            int ans=tr.Ask(1,1,n,l);
            ans+=Find(l);
            printf("%lld\n",ans);
        }
    }
    return 0;
}