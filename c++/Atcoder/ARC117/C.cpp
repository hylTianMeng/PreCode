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
const int mod=3;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,fac[N];

inline int inv(int x){return x;}

char s[N];
map<char,int> m1;
map<int,char> m2;
int a[N];

inline ll c(ll n,ll m){
	if(n<m) return 0;
    // printf("fac[%d]=%d\n",n,fac[n]);
    // printf("invfac[%d]=%d\n",m,inv(fac[m]));
    // printf("invfac[%d]=%d\n",n-m,inv(fac[n-m]));
    // printf("ans=%d\n",fac[n]*inv(fac[m])*inv(fac[n-m])%mod);
	return fac[n]*inv(fac[m])*inv(fac[n-m])%mod;
}

inline ll C(ll n,ll m){
	if(n<m) return 0;
	else if(n<mod) return c(n,m);
	else return C(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);fac[0]=1;fac[1]=1;fac[2]=2;
    m1['B']=0;m1['W']=1;m1['R']=2;
    m2[0]='B';m2[1]='W';m2[2]='R';
    scanf("%s",s+1);
    rep(i,1,n) a[i]=m1[s[i]];
    int ans=0;
    // cout<<C(2,0);
    // cout<<endl<<endl;
    rep(i,1,n){
        ans=inc(ans,a[i]*C(n-1,i-1));
        // printf("%d\n",a[i]*C(n-1,i-1));
        // cout<<C(n-1,i-1)<<endl;
    }
    if((n&1)==0) ans=mod-ans;
    ans%=3;
    printf("%c",m2[ans]);
    return 0;
}