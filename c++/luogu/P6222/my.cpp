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
#define N 10001000
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
// #define int long long
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

int n,m;
uint k;
uint pr[N<<1],ta,h[N<<1],g[N<<1],len,t;
bool no[N<<1];

inline uint ksm(uint a,uint b){uint res=1;while(b){if(b&1) res=a*res;a=a*a;b>>=1;}return res;}

inline void sieve(){
    no[1]=1;h[1]=1;g[1]=1;
    rep(i,2,len){
        if(!no[i]) pr[++ta]=i,h[i]=ksm(i,k),g[i]=i-1;
        for(int j=1;j<=ta&&i*pr[j]<=len;j++){
            no[i*pr[j]]=1;
            if(i%pr[j]) h[i*pr[j]]=h[i]*h[pr[j]],g[i*pr[j]]=g[i]*g[pr[j]];
            else{
                h[i*pr[j]]=h[i]*h[pr[j]];
                if((i/pr[j])%pr[j]==0) g[i*pr[j]]=0;
                else g[i*pr[j]]=g[i/pr[j]]*(-pr[j]);
                break;
            }
        }
    }
    rep(i,1,len) pr[i]=(pr[i-1]+h[i]);
    rep(i,1,(len>>1)) g[i]=(g[i-1]+h[i]*g[i]);
    rep(i,1,(len>>1)) h[i]=(h[i-1]+2*(pr[i*2]-pr[i])-h[i*2]);
    
}

signed main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(t);read(n);len=n<<1;read(k);sieve();
    rep(i,1,t){
        uint x;read(x);
        uint Ans=0;
        for(int i=1,j;i<=x;i=j+1){
            j=x/(x/i);
            Ans=(Ans+h[x/i]*((g[j]-g[i-1])));
        }
        printf("%u\n",Ans);
    }
    return 0;
}