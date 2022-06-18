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
#define N 100
#define M 7
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

#define int long long

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,a,nw,nx;
char s[M][N];
int f[2][1<<M][N*N],inv[N*N],Ans;

inline void add(int &a,int b){
    a=inc(a,b);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);rep(i,1,n)scanf("%s",s[i]+1);
    int a=n*(m-1)+(n-1)*m;
    inv[1]=1;for(int i=2;i<=a;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    f[0][0][0]=-1;
    rep(j,1,m)rep(i,1,n){
        nw=nx;nx^=1;mset(f[nx],0);
        rep(T,0,(1<<n)-1)rep(k,0,a){
            if(!f[nw][T][k]) continue;
            int nt=T&(((1<<n)-1)^(1<<(i-1)));
            // f[nx][nt][k]=inc(f[nx][nt][k],f[nw][T][k]);
            add(f[nx][nt][k],f[nw][T][k]);
            if(s[i][j]=='*'){
                nt|=(1<<(i-1));
                int c=0;
                if(i>1&&!((T>>(i-2))&1)) c++;
                if(j>1&&!((T>>(i-1))&1)) c++;
                if(i<n) c++;
                if(j<m) c++;
                add(f[nx][nt][k+c],mod-f[nw][T][k]);
            }
        }
    }
    rep(i,0,(1<<n)-1)rep(j,1,a){
        Ans=(Ans+1ll*f[nx][i][j]*inv[j]%mod)%mod;
    }
    printf("%lld\n",(1ll*Ans*a%mod+mod)%mod);
    return 0;
}