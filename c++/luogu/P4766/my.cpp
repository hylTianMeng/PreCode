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
#define N 2010
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

struct squ{
    int l,r,x;
}a[N];

int t,n,c[N],len;
int f[N][N];

inline void Init(){
    read(n);rep(i,1,n) read(a[i].l),read(a[i].r),read(a[i].x);
    rep(i,1,n) c[++len]=a[i].l,c[++len]=a[i].r;
    sort(c+1,c+len+1);len=unique(c+1,c+len+1)-c-1;
    rep(i,1,n) a[i].l=lower_bound(c+1,c+len+1,a[i].l)-c,a[i].r=lower_bound(c+1,c+len+1,a[i].r)-c;
}

inline void Solve(){
    int m=-1;rep(i,1,n) m=max(m,max(a[i].l,a[i].r));
    rep(i,1,m){
        f[i][i]=0;
        rep(j,1,n) if(a[j].l==a[j].r&&a[j].l==i) f[i][i]=a[j].x;
    }
    rep(i,2,m)rep(j,1,m-i+1){
        int l=j,r=j+i-1;
        f[l][r]=INF;
        int val=0;
        rep(i,1,n) if(a[i].l>=l&&a[i].r<=r) cmax(val,a[i].x);
        rep(k,l,r) cmin(f[l][r],f[l][k-1]+f[k+1][r]+val);
    }
    printf("%d\n",f[1][m]);
}

inline void Clear(){
    len=0;return;
} 

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve();Clear();
    }
    return 0;
}