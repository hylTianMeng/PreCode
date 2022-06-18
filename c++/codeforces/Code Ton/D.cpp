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

int t,n;

inline void write(int x){
    if(!x) return;
    if(x) write(x/10);putchar(x%10+'0');
}

signed main(){
    read(t);
    while(t--){
        read(n);
        int now=n;bool op=0;
        while(now){if((now&1)&&now!=1){op=1;break;}now>>=1;}
        // printf("op=%d\n",op);
        if(!op){puts("-1");continue;}
        if(n&1){puts("2");continue;}
        else{
            now=n;int cnt=0;while(now){if(now&1)break;now>>=1;cnt++;}
            // printf("cnt=%d\n",cnt);
            int la=n/(1ll<<cnt);
            ull a=1;rep(i,1,cnt+1) a*=2;
            if(a>la){
                // printf("here\n");
                printf("%lld\n",la);
            }
            else{cout<<a<<'\n';}
        }
    }
    return 0;
}