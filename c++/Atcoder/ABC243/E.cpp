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
#define N 310
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
const dd eps=1e18;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int cnt[N][N],n,m,d[N][N],a[N*N],b[N*N],c[N*N];

signed main(){
    read(n);read(m);
    rep(i,1,n)rep(j,1,n)d[i][j]=INF;
    rep(i,1,m){
        read(a[i]);read(b[i]);read(c[i]);
        cnt[a[i]][b[i]]=1;
        cnt[b[i]][a[i]]=1;
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)
        if(d[i][k]+d[k][j]==d[i][j]) cnt[i][j]++;
        else if(d[i][k]+d[k][j]<d[i][j]){cnt[i][j]=cnt[i][k]*cnt[k][j];d[i][j]=d[i][k]+d[k][j];}
    int ans=0;
    rep(i,1,m){
        // printf("i=%d\n",i);
        // printf("%d\n",d[a[i]][b[i]]);
        // printf("%d\n",cnt[a[i]][b[i]]);
        if(d[a[i]][b[i]]==c[i]){
            if(cnt[a[i]][b[i]]>1) ans++;
        }
        else if(d[a[i]][b[i]]<c[i]) ans++;
    }
    printf("%lld\n",ans);
    return 0;
}