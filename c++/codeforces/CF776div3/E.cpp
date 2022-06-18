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

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n,d,a[N],c[N],id[N],sum[N],f[N],g[N],ans,U,tail;
P b[N];

inline void Clear(){
    rep(i,0,U) a[i]=c[i]=id[i]=sum[i]=f[i]=g[i]=b[i].fi=b[i].se=0;
    ans=0;U=0;tail=0;
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(d);
        a[0]=0;
        rep(i,1,n) read(a[i]);
        int m=INF;
        rep(i,1,n) m=min(m,a[i]-a[i-1]-1);
        ans=m;
        rep(i,1,n){
            if(a[i]-a[i-1]-1==m) continue;
            b[i].fi=max(1ll,a[i]-m);
            b[i].se=min(d,a[i]+m);
            // printf("%d %d\n",b[i].fi,b[i].se);
        }
        c[++tail]=1;c[++tail]=d;
        rep(i,1,n){
            if(a[i]-a[i-1]-1==m) continue;
            c[++tail]=b[i].fi,c[++tail]=b[i].se;
            c[++tail]=b[i].fi-1;c[++tail]=b[i].se+1;
        }
        sort(c+1,c+tail+1);int len=unique(c+1,c+tail+1)-c-1;
        rep(i,1,n){
            if(a[i]-a[i-1]-1==m) continue;
            int rk=lower_bound(c+1,c+len+1,b[i].fi)-c;
            id[rk]=b[i].fi;b[i].fi=rk;
            rk=lower_bound(c+1,c+len+1,b[i].se)-c;
            id[rk]=b[i].se;b[i].se=rk;
        }
        U=n<<2;
        rep(i,1,U){
            sum[b[i].fi]++;sum[b[i].se+1]--;
        }
        rep(i,1,U) sum[i]+=sum[i-1];
        // rep(i,1,U){
        //     printf("%lld ",sum[i]);
        // }puts("");
        id[1]=1;id[U]=d;
        int now=1+m;
        rep(i,1,U){
            if(sum[i]) now=i;
            f[i]=now;
        }
        now=U-m;
        dec(i,1,U){
            if(sum[i]) now=i;
            g[i]=now;
        }
        rep(i,1,U){
            if(sum[i]) continue;
            int L=id[f[i]]-m,R=id[g[i]]+m;
            if(!f[i]||!g[i]) continue;
            // printf("L=%d R=%d\n",L,R);
            int x=(L+R)/2;
            ans=max(ans,x-L-1);
        }
        printf("ans=%d\n",ans);
        rep(i,1,n){
            if(a[i]-a[i-1]-1==m){a[i]=0;continue;}
            ans=min(ans,a[i]-a[i-1]-1);
        }
        printf("%lld\n",ans);
        Clear();
    }
}