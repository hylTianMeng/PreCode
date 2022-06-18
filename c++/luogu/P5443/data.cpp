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
#define N number
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

int random(int n){
    return 1ll*rand()*rand()%n+1;
}

int main(){
    srand(time(0));
    assert(freopen("my.in","w",stdout));
    int n=5,m=8;printf("%d %d\n",n,m);
    rep(i,1,m){
        int a=random(n),b=random(n);
        if(a==b){i--;continue;}
        printf("%d %d %d\n",a,b,random(100));
    }
    int q=200;
    printf("%d\n",q);
    rep(i,1,q){
        int op=random(2);
        printf("%d ",op);
        if(op==1){
            int a=random(m),b=random(100);
            printf("%d %d\n",a,b);
        }
        else{
            int a=random(n),b=random(100);
            printf("%d %d\n",a,b);
        }
    }

}