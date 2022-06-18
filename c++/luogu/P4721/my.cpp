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
#define N 400100
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
const int mod=998244353;
const int g=3;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int tr[N];
inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*a*res%mod;a=1ll*a*a%mod;b>>=1;}return res;}

inline void Gettr(int n){
    for(int i=0;i<n;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?(n>>1):0);
}
inline void NTT(int *f,int len,int flag){
    for(int i=0;i<len;i++) if(i<tr[i]) swap(f[i],f[tr[i]]);
    for(int p=2;p<=len;p<<=1){
        int md=ksm(g,(mod-1)/p,mod),l=p>>1;
        if(flag==-1) md=ksm(md,mod-2,mod);
        for(int i=0;i<len;i+=p){
            int buf=1;
            for(int j=i;j<i+l;j++){
                int tt=1ll*f[j+l]*buf%mod;
                f[j+l]=((f[j]-tt)%mod+mod)%mod;
                f[j]=(f[j]+tt)%mod;buf=1ll*buf*md%mod;
            }
        }
    }
}

int n,m,c[N],a[N],b[N];

inline void GetInv(int len,int *a,int *b){
    if(len==1){b[0]=ksm(a[0],mod-2,mod);return;}
    GetInv((len+1)>>1,a,b);m=1;while(m<(len<<1)) m<<=1;
    Gettr(m);for(int i=0;i<len;i++) c[i]=a[i];
    for(int i=len;i<m;i++) c[i]=0;
    // printf("m=%d\n",m);
    // for(int i=0;i<m;i++) printf("%d ",c[i]);
    NTT(c,m,1);NTT(b,m,1);
    for(int i=0;i<m;i++) b[i]=1ll*(2-1ll*b[i]*c[i]%mod+mod)%mod*b[i]%mod;
    NTT(b,m,-1);int inv=ksm(m,mod-2,mod);for(int i=0;i<m;i++) b[i]=1ll*b[i]*inv%mod;
    for(int i=len;i<m;i++) b[i]=0;
    // printf("len=%d\n",len);
    // for(int i=0;i<n;i++) printf("%d ",b[i]);puts("");
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<n;i++) read(a[i]);
    rep(i,0,n-1) a[i]=-a[i];a[0]++;
    GetInv(n,a,b);
    rep(i,0,n-1) printf("%d ",b[i]);
    return 0;
}
