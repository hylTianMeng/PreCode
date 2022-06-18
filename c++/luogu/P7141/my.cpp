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
#define N 310
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

int n,m,a[N],b[N][N];

inline void Change(int o,int p){
    rep(j,1,m){
        if(p==1){
            if(o==1) for(int i=1,k=1;i<=n&&k<=a[j];i+=2,k++) b[i][j]=1;
            else for(int i=2,k=1;i<=n&&k<=a[j];i+=2,k++) b[i][j]=1;
        }
        else{
            if(o==1) for(int i=n,k=1;i>=1&&k<=a[j];i-=2,k++) b[i][j]=1;
            else for(int i=n-1,k=1;i>=1&&k<=a[j];i-=2,k++) b[i][j]=1;
        }
        if((n&1)&&(a[j]>=n/2||a[j+1]>=n/2)) o^=1;
        p^=1;
    }
}

inline bool Check(){
    rep(i,1,n)rep(j,1,m){
        if(b[i][j]!=1) continue;
        if(b[i-1][j]||b[i][j-1]||b[i+1][j]||b[i][j+1]) return 0;
    }
    rep(j,1,m){
        int cnt=0;
        rep(i,1,n) cnt+=b[i][j];
        if(cnt!=a[j]) return 0;
    }
    return 1;
}

inline void Print(){
    rep(i,1,n){
        rep(j,1,m) printf("%d ",b[i][j]);
        puts("");
    }
    puts("");
}

int main(){
    // freopen("my.out","w",stdout);
    read(n);read(m);rep(i,1,m) read(a[i]);
    rep(i,0,1)rep(j,0,1){
        Change(i,j);
        if(Check()){
            puts("Yes");
            Print();return 0;
        }
        // Print();
        mset(b,0);
    }
    puts("No");
    return 0;
}