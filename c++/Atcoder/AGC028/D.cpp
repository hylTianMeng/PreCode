#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 610
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k;

typedef pair<int,int> P;
P a[N];
bool vis[N];

int f[N][N],c[N][N],p[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);
    n<<=1;
    rep(i,1,k){
        read(a[i].fi);read(a[i].se);
        if(a[i].se<a[i].fi) swap(a[i].se,a[i].fi);
        vis[a[i].fi]=vis[a[i].se]=1;   
    }
    rep(i,1,n)rep(j,i,n)rep(o,i,j) if(!vis[o]) c[i][j]++;
    p[0]=1;for(int i=2;i<=n;i+=2) p[i]=1ll*p[i-2]*(i-1)%mod;
    rep(i,1,n)rep(j,i+1,n){
        bool op=1;
        rep(o,1,k){
            if(a[o].fi<i&&i<=a[o].se&&a[o].se<=j){op=0;break;}
            if(i<=a[o].fi&&a[o].fi<=j&&a[o].se>j){op=0;break;}
        }
        if(!op) continue;
        f[i][j]=(f[i][j]+p[c[i][j]])%mod;
        dec(r,i+1,j-1){
            f[i][j]=(f[i][j]-1ll*f[i][r]*p[c[r+1][j]]%mod)%mod;
        }
    }
    int Ans=0;
    rep(i,1,n)rep(j,i+1,n){
        Ans=(Ans+1ll*f[i][j]*p[n-2*k-c[i][j]]%mod)%mod;
        // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
    }
    printf("%d\n",Ans);
    return 0;
}