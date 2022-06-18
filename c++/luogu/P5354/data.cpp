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
#define N number
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

inline int random(int n){return 1ll*rand()*rand()%n+1;}

signed main(){
    freopen("my.in","w",stdout);
    srand(time(0));
    int n,m;
    n=m=5;
    printf("%lld %lld ",n,m);
    printf("64\n");
    rep(i,1,n){
        int op=random(3);
        int x=random(10000000000);
        printf("%lld %lld\n",op,x);
    }
    rep(i,2,n){printf("%d %d\n",random(i-1),i);}
    rep(i,1,m){
        int op=random(2);
        if(op==1){
            printf("%d %d %d %lld\n",op,random(n),random(n),random(10000000000));
        }
        else{
            printf("%d %d %d %lld\n",op,random(n),random(3),random(10000000000));
        }
    }
    return 0;
}