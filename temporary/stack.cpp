#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define Next(k) for(int x=head[k];x;x=li[x].next)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 500010
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int a[N],b[N],n,m,L[N],sta[N],top,root[N],tot;
struct Node{
    int val,ls,rs;
}p[N*20];

#define ls(k) p[k].ls
#define rs(k) p[k].rs
inline void PushUp(int k){
    p[k].val=p[ls(k)].val+p[rs(k)].val;
}
inline void Add(int last,int &k,int l,int r,int w,int x){
    k=++tot;p[k]=p[last];
    if(l==r){p[k].val+=x;return;}int mid=(l+r)>>1;
    if(w<=mid) Add(ls(last),ls(k),l,mid,w,x);
    else if(w>mid) Add(rs(last),rs(k),mid+1,r,w,x);PushUp(k);
}
inline int Ask(int last,int k,int l,int r,int z,int y){
    // printf("last=%d k=%d l=%d r=%d z=%d y=%d\n",last,k,l,r,z,y);
    // assert(z>=l&&y<=r);
    if(l==z&&r==y) return p[k].val-p[last].val;
    int mid=(l+r)>>1;
    if(y<=mid) return Ask(ls(last),ls(k),l,mid,z,y);
    else if(z>mid) return Ask(rs(last),rs(k),mid+1,r,z,y);
    else return Ask(ls(last),ls(k),l,mid,z,mid)+Ask(rs(last),rs(k),mid+1,r,mid+1,y);
}

int main(){
    freopen("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    read(n);read(m);rep(i,1,n) read(a[i]);rep(i,1,n) read(b[i]);
    rep(i,1,n){
        while(top&&(a[sta[top]]==a[i]||b[sta[top]]<=b[i])) top--;
        L[i]=sta[top];sta[++top]=i;
    }
    rep(i,1,n){
        // printf("i=%d\n",i);
        Add(root[i-1],root[i],0,n,L[i],1);
        // printf("L[%d]=%d\n",i,L[i]);
        // printf("val=%d\n",p[root[i]].val);
    }
    rep(i,1,m){
        // printf("i=%d\n",i);
        int l,r;read(l);read(r);
        int ans=Ask(root[l-1],root[r],0,n,0,l-1);
        printf("%d\n",ans);
    }
    return 0;
}