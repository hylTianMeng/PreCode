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
#define N 12
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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][N],n,p[N][N],m;

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    read(n);read(m);
    rep(i,1,n*(n-1)){
        int from,to;read(from);read(to);
        int x,y;read(x);read(y);
        p[from][to]=mul(x,ksm(y,mod-2,mod));
    }
    f[1][0]=1;
    rep(i,1,n){
        rep(j,1,n){
            int now=0;
            rep(k,1,n){
                if(j==k) continue;
                now=inc(now,mul(f[k][i-1],p[k][j]));
            }
            int all=1;
            rep(x,0,i-1) all=inc(all,-p[j][x]);
            f[j][i]=mul(now,all);
        }
    }
    int ans=1;
    rep(i,1,n){
        int now=0;
        rep(j,0,m){
            now=inc(now,f[i][j]);
        }
        ans=mul(ans,now);
    }
    printf("%d\n",(ans%mod+mod)%mod);
    return 0;
}