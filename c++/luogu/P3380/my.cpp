#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M 50010
using namespace std;

const int INF=2147483647;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}
template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Node{
        int val,size,ls,rs,key;
        inline Node(){}
        inline Node(int val,int size,int ls,int rs,int key) : val(val),size(size),ls(ls),rs(rs),key(key) {}
}p[N];

int tot,a[N],n,m;
int Stack[N],top;

inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct FHQTreap{
    #define ls(k) p[k].ls
    #define rs(k) p[k].rs
    
    int root,x,y,z,Ans,k,Now;
    inline FHQTreap(){x=y=z=0;root=0;}
    inline int NewNode(int val){
        Now=(top)?(Stack[top--]):(++tot); p[Now]=Node(val,1,0,0,random(INF));return Now;
    }
    inline void PushUp(int k){p[k].size=p[ls(k)].size+p[rs(k)].size+1;}
    inline void Split(int k,int val,int &x,int &y){
        if(!k){x=y=0;return;}
        if(p[k].val<=val){x=k;Split(rs(k),val,rs(x),y);PushUp(x);return;}
        else{y=k;Split(ls(k),val,x,ls(y));PushUp(y);return;}
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a|b;
        if(p[a].key<p[b].key){ls(b)=Merge(a,ls(b));PushUp(b);return b;}
        else{rs(a)=Merge(rs(a),b);PushUp(a);return a;}
    }
    inline void Insert(int val){
        Split(root,val,x,y);z=Merge(x,NewNode(val));root=Merge(z,y);
    }
    inline void Delete(int val){
        Split(root,val,x,y);Split(x,val-1,x,z);if(z){Stack[++top]=z;z=Merge(ls(z),rs(z));}root=Merge(Merge(x,z),y);
    }
    inline int GetRank(int val){
        Split(root,val-1,x,y);Ans=p[x].size;root=Merge(x,y);return Ans;
    }
    inline int GetVal(int Size){
        k=root;
        while(k){
            if(p[ls(k)].size+1==Size) return k;
            else if(p[ls(k)].size+1<Size){Size-=p[ls(k)].size+1;k=rs(k);}
            else{k=ls(k);}
        }
        return k==0?INF:p[k].val;
    }
    inline int GetPre(int val){
        Split(root,val-1,x,y);k=x;while(rs(k)) k=rs(k);Ans=p[k].val;root=Merge(x,y);return k==0?-INF:Ans;
    }
    inline int GetNext(int val){
        Split(root,val,x,y);k=y;while(ls(k)) k=ls(k);Ans=p[k].val;root=Merge(x,y);return k==0?INF:Ans;
    }
    inline void Build(int l,int r){
        // printf("l=%d r=%d\n",l,r);
        for(int i=l;i<=r;i++) Insert(a[i]);
    }
};
FHQTreap Tr[M<<2];

struct SegmentTree{
    #define Ls(k) k<<1
    #define Rs(k) k<<1|1
    int L,R,mid,Ans;
    inline int GetRank(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y){return Tr[k].GetRank(x);}
        int mid=(l+r)>>1;
        if(y<=mid) return GetRank(Ls(k),l,mid,z,y,x);
        else if(z>mid) return GetRank(Rs(k),mid+1,r,z,y,x);
        else return GetRank(Ls(k),l,mid,z,mid,x)+GetRank(Rs(k),mid+1,r,mid+1,y,x);
    }
    inline int GetVal(int Rank,int l,int r){
        L=0;R=1e8;Ans=L;
        while(L<=R){
            int mid=(L+R)>>1;
            if(GetRank(1,1,n,l,r,mid)+1<=Rank){L=mid+1;Ans=mid;}else R=mid-1;
        }
        return Ans;
    }
    inline void Change(int k,int l,int r,int w,int x){
        Tr[k].Delete(a[w]);Tr[k].Insert(x);
        if(l==r) return;
        int mid=(l+r)>>1;
        if(w<=mid) Change(Ls(k),l,mid,w,x);
        else Change(Rs(k),mid+1,r,w,x);
    }
    inline int GetPre(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y) return Tr[k].GetPre(x);
        int mid=(l+r)>>1;
        if(y<=mid) return GetPre(Ls(k),l,mid,z,y,x);
        else if(z>mid) return GetPre(Rs(k),mid+1,r,z,y,x);
        else return Max(GetPre(Ls(k),l,mid,z,mid,x),GetPre(Rs(k),mid+1,r,mid+1,y,x));
    }
    inline int GetNext(int k,int l,int r,int z,int y,int x){
        if(l==z&&r==y) return Tr[k].GetNext(x);
        int mid=(l+r)>>1;
        if(y<=mid) return GetNext(Ls(k),l,mid,z,y,x);
        else if(z>mid) return GetNext(Rs(k),mid+1,r,z,y,x);
        else return Min(GetNext(Ls(k),l,mid,z,mid,x),GetNext(Rs(k),mid+1,r,mid+1,y,x));
    }
    inline void Build(int k,int l,int r){
        // printf("k=%d l=%d r=%d\n",k,l,r);
        Tr[k].Build(l,r);
        if(l==r) return;
        int mid=(l+r)>>1;
        Build(Ls(k),l,mid);Build(Rs(k),mid+1,r);
    }
}st;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    st.Build(1,1,n);
    // printf("Completing Build\n");
}

inline void Solve(){
    for(int i=1;i<=m;i++){
        int op,l,r,k;
        // printf("i=%d\n",i);
        read(op);
        if(op==1){
            read(l);read(r);read(k);
            printf("%d\n",st.GetRank(1,1,n,l,r,k)+1);
        }
        else if(op==2){
            read(l);read(r);read(k);
            printf("%d\n",st.GetVal(k,l,r));
        }
        else if(op==3){
            read(l);read(r);st.Change(1,1,n,l,r);
            a[l]=r;
        }
        else if(op==4){
            read(l);read(r);read(k);
            printf("%d\n",st.GetPre(1,1,n,l,r,k));
        }
        else if(op==5){
            read(l);read(r);read(k);
            printf("%d\n",st.GetNext(1,1,n,l,r,k));
        }
    }
}

inline void Init(){
    
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}