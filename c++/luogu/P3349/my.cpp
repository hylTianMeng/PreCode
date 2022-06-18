#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(-1):1)
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
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

// #define int long long

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

vi e[N];
ull n,m,f[N],g[N][N],Ans;
bool v[N][N];

inline void dfs(int k,int fa,int S){
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k,S);
    }
    rep(i,0,n-1) g[k][i]=(S>>i)&1;
    // printf("k=%d fa=%d S=%d\n",k,fa,S);
    rep(i,0,n-1)if(g[k][i]){
        // printf("GOAL:k=%d i=%d\n",k,i);
        for(int to:e[k]){
            ull now=0;
            if(to==fa) continue;
            rep(j,0,n-1){
                if(v[i][j]){
                    // printf("Trans:j=%d\n",j);
                    // printf("g[%d][%d]=%llu\n",to,j,g[to][j]);
                    now+=g[to][j];
                    
                }
            }
            // printf("now=%d\n",now);
            g[k][i]*=now;
        }
        // puts("_____");
    }
}

signed main(){
    // freopen("2.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,m){
        int from,to;read(from);read(to);from--;to--;
        v[from][to]=1;v[to][from]=1;
    }
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    rep(i,1,(1<<n)-1){
        // puts("");puts("");puts("");
        // mset(g,0);
        dfs(1,0,i);
        ull now=0;
        // printf("i=%d\n",i);
        // rep(j,0,n-1)if((i>>j)&1)printf("g[1][%d]=%llu\n",j,g[1][j]);
        rep(j,0,n-1)now+=g[1][j];
        // printf("i=%d now=%d\n",i,now);
        f[__builtin_popcount(i)]+=now;
    }
    // rep(i,1,n) printf("f[%d]=%llu\n",i,f[i]);
    rep(i,1,n) Ans+=sgn(n-i)*f[i];
    printf("%llu\n",Ans);
    return 0;
}