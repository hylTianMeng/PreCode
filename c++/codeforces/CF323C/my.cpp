#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30000100
#define M 1000100
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Node{
    int sum,ls,rs;
}p[N];
int Root[M],tot;

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct SegmentTree{
    inline int NewNode(){return ++tot;}
    inline void PushUp(int k){p[k].sum=p[ls(k)].sum+p[rs(k)].sum;}
    inline int Insert(int &k,int l,int r,int w,int x){
        int now=NewNode();
        p[now]=p[k];
        if(l==r){p[now].sum++;return now;}
        int mid=(l+r)>>1;
        if(w<=mid) ls(now)=Insert(ls(k),l,mid,w,x);
        else rs(now)=Insert(rs(k),mid+1,r,w,x); 
        PushUp(now);return now;
    }  
    inline int AskSum(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k].sum;
        int mid=(l+r)>>1;
        if(y<=mid) return AskSum(ls(k),l,mid,z,y);
        else if(z>mid) return AskSum(rs(k),mid+1,r,z,y);
        else return AskSum(ls(k),l,mid,z,mid)+AskSum(rs(k),mid+1,r,mid+1,y);
    }
}st;

int a[M],b[M],id[M],n,m,ans;

inline int f(int x){return (x-1+ans)%n+1;}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){read(a[i]);id[a[i]]=i;}
    for(int i=1;i<=n;i++){
        read(b[i]);Root[i]=st.Insert(Root[i-1],1,n,id[b[i]],1);
        // printf("id=%d\n",id[b[i]]);
        printf("tot=%d\n",tot);
    }
    // printf("here\n");
    printf("tot=%d\n",tot);
    read(m);
    // printf("m=%d\n",m);
    for(int i=1;i<=m;i++){
        // printf("i=%d\n",i);
        int A,B,C,D;read(A);read(B);read(C);read(D);
        A=f(A),B=f(B),C=f(C),D=f(D);
        if(A>B) swap(A,B);if(C>D) swap(C,D);
        // printf("A=%d B=%d C=%d D=%d\n",A,B,C,D);
        ans=st.AskSum(Root[D],1,n,A,B)-st.AskSum(Root[C-1],1,n,A,B);
        printf("%d\n",ans);
        ans++;
    }
    return 0;
}