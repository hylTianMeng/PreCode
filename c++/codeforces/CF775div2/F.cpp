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
#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=9e18;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Node{
    int a,b,c;
    inline Node operator + (const Node &d)const{
        Node e;e.a=max(a,d.a);e.b=max(b,d.b);e.c=max(max(c,d.c),a+d.b);
        return e;
    }
}p[N<<2];

int a[4][N],sum[4][N],n,q;
vector<P> v[N];
int Ans=-INF;

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        p[k]=p[ls(k)]+p[rs(k)];
    }  
    inline void Build(int k,int l,int r){
        if(l==r){
            p[k].a=sum[1][l]-sum[2][l-1];
            p[k].b=sum[2][l]-sum[3][l-1]+sum[3][n];
            p[k].c=sum[1][l]+a[2][l]-sum[3][l-1]+sum[3][n];
            return;
        }
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);PushUp(k);
    }
    inline Node Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;
        if(y<=mid) return Ask(ls(k),l,mid,z,y);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
        else return Ask(ls(k),l,mid,z,mid)+Ask(rs(k),mid+1,r,mid+1,y);
    }
    inline void Change(int k,int l,int r,int w,int x){
        if(l==r){p[k].a=max(p[k].a,x);p[k].c=max(p[k].c,p[k].a+p[k].b);return;}
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls(k),l,mid,w,x);
        else if(w>mid) Change(rs(k),mid+1,r,w,x);
        PushUp(k);
    }
}st;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    rep(i,1,3){
        rep(j,1,n) read(a[i][j]),sum[i][j]=sum[i][j-1]+a[i][j];
    }
    rep(i,1,q){
        int l,r,k;read(l);read(r);read(k);
        v[r].pb(mp(l,k));
    }
    st.Build(1,1,n);
    // printf("spe=%d\n",p[1].c);
    rep(i,1,n){
        for(P now:v[i]){
            // printf("l=%d r=%d\n",now.fi,i);
            Node nowans=st.Ask(1,1,n,now.fi,i);   
            // printf("nowans=%lld\n",nowans.c);
            Ans=max(Ans,nowans.c-now.se);
            if(i<n) st.Change(1,1,n,i+1,nowans.a-now.se);
        }
    }
    printf("%lld\n",Ans);
    return 0;
}