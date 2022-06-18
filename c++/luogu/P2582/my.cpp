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
#define N 800010
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
    for(;!isdigit(c);c=getchar()) if(c ==  '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],L[N],R[N],g[N],siz[N],val[N],sta[N],top;
bool vis[N];

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);rep(i,1,n) read(a[i]),L[a[i]]=i,R[i]=a[i];
    rep(i,1,n){
        if(vis[i]) continue;
        int tot=0,k=i;
        while(!vis[k]){
            vis[k]=1;sta[++top]=k;tot++;
            k=R[k];
        }
        rep(j,1,top) siz[sta[j]]=tot;
        top=0;
    }
    rep(i,1,n) val[i]=INF,vis[i]=0;
    rep(i,1,n) cmin(val[siz[i]],i);
    rep(i,1,n) for(int j=i;j<=n;j+=i) cmin(val[j],val[i]);
    rep(i,1,n){
        if(vis[i]) continue;
        int k=i,now=val[siz[i]];
        while(!vis[k]){
            vis[k]=1;
            g[k]=now;k=L[k];now=L[now];
        }
    }
    rep(i,1,n) printf("%d ",g[i]);
    return 0;
}