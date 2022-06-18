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
#define N 200010
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

const int INF=1e18;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n,a[N],b[N];

signed main(){
    read(t);
    while(t--){
        read(n);
        rep(i,1,n) read(a[i]);
        rep(i,1,n) read(b[i]);
        int ans=abs(a[1]-b[1])+abs(a[n]-b[n]);

        int nowans=0;
        int minn=INF;

        rep(i,1,n) minn=min(minn,abs(a[1]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[n]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(b[1]-a[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(b[n]-a[i]));
        nowans+=minn;minn=INF;
        ans=min(ans,nowans);

        nowans=abs(a[1]-b[1]);minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[n]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[i]-b[n]));
        nowans+=minn;minn=INF;
        ans=min(ans,nowans);

        nowans=abs(a[n]-b[n]);minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[1]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(b[1]-a[i]));
        nowans+=minn;minn=INF;
        ans=min(ans,nowans);

        reverse(b+1,b+n+1);

        ans=min(ans,abs(a[1]-b[1])+abs(a[n]-b[n]));

        nowans=abs(a[1]-b[1]);minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[n]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[i]-b[n]));
        nowans+=minn;minn=INF;
        ans=min(ans,nowans);

        nowans=abs(a[n]-b[n]);minn=INF;
        rep(i,1,n) minn=min(minn,abs(a[1]-b[i]));
        nowans+=minn;minn=INF;
        rep(i,1,n) minn=min(minn,abs(b[1]-a[i]));
        nowans+=minn;minn=INF;
        ans=min(ans,nowans);

        printf("%lld\n",ans);
    }
    return 0;
}