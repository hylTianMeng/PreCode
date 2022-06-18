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
#define N 34
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

int m,n;

inline void Ask(int x){
    assert(1<=x);assert(x<=m);
    printf("%d\n",x);cout<<flush;
}

inline int GetAns(){
    int x;read(x);
    if(x==-2||x==0) exit(0);
    return x;
}

bool a[N];
int cnt=0;

inline bool check(int mid){
    Ask(mid);int now=GetAns();
    cnt++;if(cnt==n+1) cnt=1;
    if(a[cnt]==1) return now>0;
    else return now<0;
}

int main(){
    read(m);read(n);
    rep(i,1,n){
        Ask(1);int now=GetAns();
        if(now<0) a[i]=0;else a[i]=1;
    }
    int l=1,r=m;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    check(l);
    return 0;
}