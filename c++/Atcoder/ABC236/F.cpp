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
#define N 20
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

int a[N],va[N],n,v[1<<N];

inline void Insert(int x,int vx){
    dec(i,0,n-1) if((x>>i)&1){
        if(!a[i]){a[i]=x;va[i]=vx;break;}else{
            if(vx<va[i]){swap(va[i],vx);swap(x,a[i]);}
            x^=a[i];
        }
    }
}

signed main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);rep(i,1,(1<<n)-1) read(v[i]);
    rep(i,1,(1<<n)-1){
        Insert(i,v[i]);
    }
    int Ans=0;
    rep(i,0,n-1) Ans+=va[i];
    printf("%lld\n",Ans);
    return 0;
}