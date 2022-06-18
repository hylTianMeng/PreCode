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
#define N 1010
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

bitset<1010> a[N];
int n,t;

namespace sub1{
    inline void Solve(){
        rep(i,1,n)rep(j,1,n){
            bitset<1010> now;now.reset();
            now=a[i]&a[j];
            if(now!=a[i]&&now!=a[j]&&now.count()){puts("YES");printf("%d %d\n",i,j);return;}
        }
        puts("NO");
    }
}
inline void Clear(){
    rep(i,1,n) a[i].reset();
}

int main(){
    // freopen("discuss.in","r",stdin);
    // freopen("discuss.out","w",stdout);
    read(t);
    while(t--){
        read(n);
        rep(i,1,n){
            int k;read(k);
            rep(j,1,k){int x;read(x);a[i][x]=1;}
        }
        if(n<=1000) sub1::Solve();
    }
    return 0;
}