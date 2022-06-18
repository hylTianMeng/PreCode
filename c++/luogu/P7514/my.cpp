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
#define N 1000100
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

int n,m,a[N],b[N],c[N<<1],pre[N][2],suf[N][2];

inline bool check(int mid){
    int l=1,r=0;
    rep(i,1,2*n){
        int wl=c[i],wr=c[i]+mid;
        // printf("wl=%d wr=%d\n",wl,wr);
        while(a[l]<wl&&l<=n) l++;
        while(a[r+1]<=wr&&r+1<=n) r++;
        // printf("l=%d r=%d\n",l,r);
        // if(l>n||r>n||r<l) continue;
        if(l-1+n-r>m) continue;
        bool o1=1,o2=1;
        if(l!=1){
            o1=(pre[l-1][0]<=wr&&pre[l-1][1]>=wl);
        }
        if(r!=n){
            // printf("%d %d\n",suf[r+1][0],suf[r+1][1]);
            o2=(suf[r+1][0]<=wr&&suf[r+1][1]>=wl);
        }
        // printf("o1=%d o2=%d\n",o1,o2);
        if(o1&&o2) return 1;
    }
    return 0;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n) read(a[i]);rep(i,1,n) read(b[i]);
    pre[1][0]=b[1];pre[1][1]=b[1];
    rep(i,2,n) pre[i][0]=max(pre[i-1][0],b[i]),pre[i][1]=min(pre[i-1][1],b[i]);
    suf[n][0]=b[n];suf[n][1]=b[n];
    dec(i,1,n-1) suf[i][0]=max(suf[i+1][0],b[i]),suf[i][1]=min(suf[i+1][1],b[i]);
    rep(i,1,n) c[i]=a[i];rep(i,1,n) c[i+n]=b[i];
    sort(c+1,c+2*n+1);
    int l=1,r=1e9,ans=r;
    // printf("spe:%d check(8)\n",check(8));
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    printf("%d\n",ans);
}