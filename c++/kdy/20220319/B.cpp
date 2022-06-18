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
#define N 100010
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

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],m;

namespace ST{
    struct Node{
        int ans,pre,suf,sum,al,ar,pr,sl;
        inline void Clear(){
            ans=-INF;pre=-INF;suf=-INF;
        }
        inline Node operator + (const Node &b)const{
            Node c;c.Clear();
            c.ans=max(ans,max(b.ans,suf+b.pre));
            if(c.ans==ans){
                c.al=al;c.ar=ar;
            }
            else if(c.ans==b.ans){
                c.al=b.al;c.ar=b.ar;
            }
            else{
                c.al=sl;c.ar=b.pr;
            }
            c.pre=max(pre,sum+b.pre);
            if(c.pre==pre){
                c.pr=pr;
            }
            else{
                c.pr=b.pr;
            }
            c.suf=max(b.suf,suf+b.sum);
            if(c.suf==b.suf){
                c.sl=b.sl;
            }
            else c.sl=sl;
            c.sum=sum+b.sum;return c;
        }
    }p[N<<2];
    #define ls(k) k<<1
    #define rs(k) k<<1|1
    inline void PushUp(int k){
        p[k]=p[ls(k)]+p[rs(k)];
    }
    inline void Build(int k,int l,int r){
        if(l==r){
            p[k].ans=p[k].suf=p[k].pre=p[k].sum=a[l];
            p[k].al=p[k].ar=p[k].sl=p[k].pr=l;
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
};

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);rep(i,1,n) read(a[i]);ST::Build(1,1,n);
    rep(i,1,m){
        int l,r;read(l);read(r);
        ST::Node Ans=ST::Ask(1,1,n,l,r);
        printf("%lld %lld %lld\n",Ans.al,Ans.ar,Ans.ans);
    }
    return 0;
}