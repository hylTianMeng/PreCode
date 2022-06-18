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

int n,a[N],p[N<<2],q;
ll Ans;

#define ls(k) k<<1
#define rs(k) k<<1|1

inline void PushUp(int k){p[k]=p[ls(k)]&p[rs(k)];}

inline void Build(int k,int l,int r){
    if(l==r){p[k]=a[l];return;}
    int mid=(l+r)>>1;Build(ls(k),l,mid);Build(rs(k),mid+1,r);PushUp(k);
}

inline int Ask(int k,int l,int r,int z,int y){
    if(l==z&&r==y) return p[k];
    int mid=(l+r)>>1;if(y<=mid) return Ask(ls(k),l,mid,z,y);else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
    else return Ask(ls(k),l,mid,z,mid)&Ask(rs(k),mid+1,r,mid+1,y);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    read(q);Build(1,1,n);
    for(int i=1;i<=q;i++){
        int l,r;read(l);read(r);Ans=Ans^(1ll*i*Ask(1,1,n,l,r));
    }
    printf("%lld\n",Ans);return 0;
}