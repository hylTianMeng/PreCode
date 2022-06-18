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
#define N 1000100
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

const int INF=1e18+1;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,len,m,a[N];

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(len);
    rep(i,1,n){
        int c,d,h;read(c);read(d);read(h);
        a[c]=max(a[c],d*h);
    }
    dec(i,1,len){
        if(!a[i]) continue;
        for(int j=i;j<=len;j+=i){
            a[j]=max(a[j],a[i]*(j/i));
        }
    }
    rep(i,1,len) a[i]=max(a[i],a[i-1]);
    // printf("%lld\n",a[1000000]);
    a[len+1]=INF;
    read(m);
    rep(i,1,m){
        int d,h;read(d);read(h);d*=h;
        // printf("%lld\n",d);
        // int w=upper_bound(a+1,a+len+1,d)-a;
        int l=1,r=len+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[mid]<=d) l=mid+1;
            else r=mid;
        }
        // printf("w=%lld\n",w);
        // assert(w);
        if(l==len+1){printf("-1 ");}
        else printf("%lld ",l);
    }
    return 0;
}