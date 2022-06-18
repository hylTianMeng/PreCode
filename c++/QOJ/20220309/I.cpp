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
#define N 1000010
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

int f[N],n,sum[N],cnt[N],d[N],yy;
char s[N];
int q[N],l,r;

inline int x(int id){
    return d[id];
}

inline int y(int id){
    return f[id]-sum[id]+cnt[id]*d[id];
}

inline dd k(int a,int b){
    if(fabs(x(a)-x(b))<=eps){
        return INF;
    }
    return (dd)(y(a)-y(b))/(dd)(x(a)-x(b));
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(yy);
    scanf("%s",s+1);
    int c=0;
    rep(i,1,n){
        if(s[i]=='+') c++;
        if(s[i]=='?') sum[i]=c;
    }
    rep(i,1,n) sum[i]+=sum[i-1];
    rep(i,1,n){
        if(s[i]=='?') cnt[i]++;
    }
    rep(i,1,n) cnt[i]+=cnt[i-1];
    rep(i,1,n) if(s[i]=='+') d[i]++;
    rep(i,1,n) d[i]+=d[i-1];
    l=1;r=0;
    f[0]=0;q[++r]=0;
    rep(i,1,n){
        while(r-l+1>=2&&k(q[l],q[l+1])<=(cnt[i])){
            l++;
        }
        int now=q[l];
        f[i]=f[now]+(sum[i]-sum[now])-(cnt[i]-cnt[now])*d[now]+yy;
        while(r-l+1>=2&&k(q[r],i)<k(q[r-1],q[r])) r--;
        q[++r]=i;
    }
    printf("%lld\n",f[n]-yy);
    return 0;
}
