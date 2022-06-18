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
#define N 2000010
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

map<P,int> id;
P rk[N],s[N];
int n,tot,d[N],ans[N];
vi v[N],a,b;

const int fx[]={0,1,-1,0,0};
const int fy[]={0,0,0,1,-1};

bool op=0;

inline int ge(int x,int y){
    if(!id[mp(x,y)]){
        id[mp(x,y)]=++tot;
        if(op==0) a.pb(tot);
        else b.pb(tot);
        rk[tot]=mp(x,y);
    }
    return id[mp(x,y)];
}

bool vis[N];

queue<int> q;

inline void bfs(int k){
    for(int now:b){
        q.push(now);vis[now]=1;
        ans[now]=now;
    }
    while(q.size()){
        int top=q.front();q.pop();
        for(int to:v[top]){
            if(vis[to]) continue;
            vis[to]=1;
            d[to]=d[top]+1;
            q.push(to);ans[to]=ans[top];
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    tot++;
    rep(i,1,n){
        int x,y;read(x);read(y);
        ge(x,y);
        s[i].fi=x;s[i].se=y;
    }
    op=1;
    rep(i,1,n){
        int now=id[s[i]];
        rep(j,1,4){
            int dx=s[i].fi+fx[j];
            int dy=s[i].se+fy[j];
            v[ge(dx,dy)].pb(now);
            v[now].pb(ge(dx,dy));
        }
    }
    bfs(1);
    rep(i,2,n+1){
        printf("%d %d\n",rk[ans[i]].fi,rk[ans[i]].se);
    }
    return 0;
}
