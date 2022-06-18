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

struct Node{
    int a,b;
    inline bool operator < (const Node &c)const{
        if(a+b!=c.a+c.b) return a+b<c.a+c.b;
        return a<c.a;
    }
}a[N];

int n,f[N],m;
bool vis[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);rep(i,1,n) read(a[i].a),read(a[i].b);
    sort(a+1,a+n+1);
    mset(f,-1);f[0]=0;
    rep(i,1,n) f[0]+=a[i].a;
    int tot=0;
    read(m);
    rep(i,1,n){
        dec(j,0,tot){
            if(f[j]+a[i].b>=m) cmax(f[j+1],f[j]-a[i].a);
            if(f[tot+1]!=-1) tot++;
        }
        // while(f[tot+1]!=-1) tot++;
        // rep(j,0,tot) printf("f[%d]=%d\n",j,f[j]);
    }
    printf("%d\n",tot);
    return 0;
}