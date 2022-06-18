#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 510
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
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

int n,mod,f[N][N],Ans=1;
P a[N];

inline void PreWork(){
    read(n);read(mod);
    rep(i,0,2*n-1){
        if(i<n) a[i+1].fi=ceil(sqrt(dd(n*n-i*i)))-1,a[i+1].se=min((int)floor(sqrt(dd(4*n*n-i*i))),2*n-1);
        else a[i+1].fi=min((int)floor(sqrt(dd(4*n*n-i*i))),2*n-1),a[i+1].se=0;
    }
    dec(i,0,2*n-1){
        if(i<n) Ans=1ll*Ans*(a[i+1].se+1-(2*n-1-i))%mod;
        else Ans=1ll*Ans*(a[i+1].fi+1-(2*n-1-i))%mod;
    }
    // printf("Ans=%d\n",Ans);puts("");
    // rep(i,1,2*n){
    //     printf("a[i]=%d %d\n",a[i].fi,a[i].se);
    // }

    sort(a+1,a+2*n+1);

    // printf("HaveSorted\n");
    // rep(i,1,2*n){
    //     printf("a[i]=%d %d\n",a[i].fi,a[i].se);
    // }
}

inline int Calc(int k){
    // printf("k=%d\n",k);
    mset(f,0);
    int cnt=0,cnt2=0;
    f[0][0]=1;
    rep(i,1,2*n){
        if(a[i].se==0){
            rep(j,0,k) f[i][j]=(f[i][j]+1ll*f[i-1][j]*(a[i].fi+1-j-cnt)%mod)%mod;
            cnt++;
        }
        else{
            rep(j,1,k) f[i][j]=(f[i][j]+1ll*f[i-1][j-1]*(a[i].fi+1-cnt-(j-1))%mod)%mod;
            rep(j,0,k) f[i][j]=(f[i][j]+1ll*f[i-1][j]*(a[i].se+1-k-n-(cnt2-j))%mod)%mod;
            cnt2++;
        }
        // rep(j,0,k){
        //     printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        // }
    }
    // puts("");
    return f[2*n][k];
}

inline void Solve(){
    rep(i,1,n)
        if(i&1) Ans=(Ans-Calc(i))%mod;
        else Ans=(Ans+Calc(i))%mod;
    printf("%d\n",(Ans%mod+mod)%mod);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();
    Solve();
    return 0;
}