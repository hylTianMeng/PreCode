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
#define N 8000100
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

int ch[N][2];
int tot=1,n,a[N],f[N],e[N];
vi v;

inline void Insert(int x){
    int p=1;
    dec(i,0,30){
        int c=(x>>i)&1;
        if(!ch[p][c]) ch[p][c]=++tot;
        p=ch[p][c];
    }
    e[p]++;v.pb(p);
}

inline void dfs(int k){
    if(ch[k][0]) dfs(ch[k][0]);
    if(ch[k][1]) dfs(ch[k][1]);
    e[k]+=e[ch[k][0]]+e[ch[k][1]];
}

inline void dfs2(int k){
    if(ch[k][0]) f[ch[k][0]]+=f[k]+max(0,e[ch[k][1]]-1),dfs2(ch[k][0]);
    if(ch[k][1]) f[ch[k][1]]+=f[k]+max(0,e[ch[k][0]]-1),dfs2(ch[k][1]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);rep(i,1,n) read(a[i]),Insert(a[i]);
    dfs(1);dfs2(1);
    int ans=INF;
    for(int now:v){
        cmin(ans,f[now]);
    }
    printf("%d\n",ans);
    return 0;
}