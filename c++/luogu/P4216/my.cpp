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
#define N 400010
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

int n,m;

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w,int x){
        for(int i=w;i<=n;i+=lowbit(i)) p[i]+=x;
    }
    inline int Ask(int w){
        int res=0;
        for(int i=w;i;i-=lowbit(i)) res+=p[i];
        return res;
    }
}bit;

vi e[N];
vi v[N];
int ans[N],l[N],r[N],id[N],rk[N],tot,f[N][21],dep[N];

struct Ques{
    int op,x,y;
}qu[N];

inline void dfs(int k,int fa){
    f[k][0]=fa;rep(i,1,20) f[k][i]=f[f[k][i-1]][i-1];dep[k]=dep[fa]+1;
    id[k]=++tot;rk[tot]=k;
    l[k]=tot;
    for(int to:e[k]){
        dfs(to,k);
    }
    r[k]=tot;
}

inline int ge(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    dec(i,0,20) if(dep[f[a][i]]>=dep[b]) a=f[a][i];
    if(a==b) return a;
    dec(i,0,20) if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    return f[a][0];
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n){
        int fat;read(fat);
        if(i==1) continue;
        e[fat].pb(i);
    }
    read(m);
    rep(i,1,m){
        int op;read(op);
        if(op==1){
            int x,y,c;read(x);read(y);read(c);
            // printf("x=%d y=%d c=%d\n",x,y,c);
            v[max(0,i-c-1)].pb(i);
            qu[i].op=1;qu[i].x=x;qu[i].y=y;
        }
        else{
            int x;
            read(x);
            qu[i].op=2;qu[i].x=x;
        }
    }
    dfs(1,0);
    n++;
    rep(i,1,m){
        if(qu[i].op==2){
            bit.Add(r[qu[i].x]+1,-1);
            bit.Add(l[qu[i].x],1);
        }
        for(int j:v[i]){
            // printf("i=%d j=%d\n",i,j);
            int lca=ge(qu[j].x,qu[j].y);
            ans[j]=bit.Ask(id[qu[j].x])+bit.Ask(id[qu[j].y])-bit.Ask(id[lca])-bit.Ask(id[f[lca][0]]);
        }
    }
    rep(i,1,m){
        if(qu[i].op==2) continue;
        // printf("x=%d y=%d\n",qu[i].x,qu[i].y);
        printf("%d ",dep[qu[i].x]+dep[qu[i].y]-2*dep[ge(qu[i].x,qu[i].y)]+1);
        printf("%d\n",ans[i]);
    }
    return 0;
}