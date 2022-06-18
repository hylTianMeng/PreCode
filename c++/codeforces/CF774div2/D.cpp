#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(mod-1):1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 200010
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

#define int long long

int n,d[N],ans[N];
P f[N][2];
vi e[N];

int nxt[N][2];

inline P operator + (const P &a,const P &b){
    return mp(a.fi+b.fi,a.se+b.se);
}

inline void dfs(int k,int fa){
    f[k][1]=mp(1,-d[k]);
    f[k][0]=mp(0,-1);
    for(int to:e[k]){
        if(to==fa) continue;
        dfs(to,k);
        f[k][1]=f[k][1]+f[to][0];
    }
    for(int to:e[k]){
        if(to==fa) continue;
        f[k][0]=f[k][0]+max(f[to][1],f[to][0]);
        if(f[to][1]<f[to][0]) nxt[to][0]=1;
        else nxt[to][1]=1;
    }
}

inline void Solve(int k,int x,int fa){
    if(x==1) ans[k]=d[k];else ans[k]=1;
    if(x==1){
        for(int to:e[k]){
            if(to==fa) continue;
            Solve(to,0,k);
        }
    }
    else{
        for(int to:e[k]){
            if(to==fa) continue;
            if(nxt[to][0]) Solve(to,0,k);
            else if(nxt[to][1]) Solve(to,1,k);
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
        d[from]++;d[to]++;
    }
    if(n==2){
        printf("2 2\n1 1\n");return 0;
    }
    dfs(1,0);
    P Ans=max(f[1][0],f[1][1]);
    printf("%d %d\n",Ans.fi,-Ans.se);
    if(f[1][0]<f[1][1]) Solve(1,1,0);
    else Solve(1,0,0);
    rep(i,1,n) printf("%lld ",ans[i]);
    return 0;
}