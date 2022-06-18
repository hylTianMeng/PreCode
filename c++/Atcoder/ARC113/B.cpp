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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int p[N<<2],n,a[N],b[N],pa[N],pb[N],c[N],tail;

#define ls(k) k<<1
#define rs(k) k<<1|1
struct Segment_Tree{
    inline int GetMax(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;
        if(y<=mid) return GetMax(ls(k),l,mid,z,y);
        else if(z>mid) return GetMax(rs(k),mid+1,r,z,y);
        else return Max(GetMax(ls(k),l,mid,z,mid),GetMax(rs(k),mid+1,r,mid+1,y));
    }
    inline void PushUp(int k){p[k]=Max(p[ls(k)],p[rs(k)]);}
    inline void Change(int k,int l,int r,int w,int x){
        if(l==r){p[k]=x;return;}
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls(k),l,mid,w,x);
        else Change(rs(k),mid+1,r,w,x);PushUp(k);
    }
}tr;

int main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]),pa[a[i]]=i;for(int i=1;i<=n;i++) read(b[i]),pb[b[i]]=i;
    for(int i=1;i<=n;i++){
        // printf("i=%d\n",i);
        tail=0;
        for(int j=a[i];j<=n;j+=a[i]){
            c[++tail]=pb[j];
        }
        sort(c+1,c+tail+1);
        for(int j=tail;j>=1;j--){
            // printf("j=%d\n",j);
            int posi=c[j];
            // printf("posi=%d\n",posi);
            int maxx=tr.GetMax(1,0,n,0,posi-1);
            // printf("maxx=%d\n",maxx);
            tr.Change(1,0,n,posi,maxx+1);
        }
    }
    printf("%d\n",tr.GetMax(1,1,n,1,n));
    return 0;
}