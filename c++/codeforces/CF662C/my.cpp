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
#define N 2000100
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

int f[N],a[N],b[N],n,m;

char s[21][100010];

inline void FWT(int *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                int a=f[i],b=f[i+mid];
                if(op==0){f[i]=(a+b);f[i+mid]=(a-b);}
                else{f[i]=(a+b)/2;f[i+mid]=(a-b)/2;}
            }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(j,1,m){
        int x=0;
        rep(i,1,n) x=(x<<1)+s[i][j]-'0';
        a[x]++;
    }
    int len=(1<<n);
    rep(i,1,len-1) b[i]=b[i>>1]+(i&1);
    rep(i,1,len-1) b[i]=min(b[i],n-b[i]); 
    // rep(i,0,len) printf("%d ",a[i]);puts("");
    // rep(i,0,len) printf("%d ",b[i]);puts("");
    FWT(a,len,0);FWT(b,len,0);
    // rep(i,0,len) printf("%d ",a[i]);puts("");
    // rep(i,0,len) printf("%d ",b[i]);puts("");
    rep(i,0,len) f[i]=a[i]*b[i];FWT(f,len,1);
    // rep(i,0,len) printf("%d ",f[i]);puts("");
    int ans=INF;
    rep(i,0,len-1) cmin(ans,f[i]);printf("%lld\n",ans);
    return 0;
}