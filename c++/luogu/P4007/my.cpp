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
#define N 210
#define M 100
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Matrix{
    int a[N][N],n,m;
    inline void Clear(){mset(a,0);n=m=0;}
    inline Matrix operator * (const Matrix &b)const{
        Matrix c;c.Clear();c.n=n;c.m=b.m;
        rep(i,1,c.n)rep(j,1,c.m){
            __int128 now=0;
            rep(k,1,m){
                now=now+(__int128)a[i][k]*b.a[k][j];
            }
            c.a[i][j]=(now%mod+mod)%mod;
        }
        return c;
    }
    inline void Print(){
        printf("n=%d m=%d\n",n,m);
        rep(i,1,n){
            rep(j,1,m) printf("%d ",a[i][j]);
            puts("");
        }
    }
}I,A,p[M],B;

int t,m,n,id[9][9][9],inv[11],tot;

namespace m3{
    inline void Init(){
        tot=0;
        mset(id,-1);
        rep(i,0,8)rep(j,0,8)rep(k,0,8)if(i+j+k<=n)id[i][j][k]=++tot;
        ++tot;
        rep(i,0,8)rep(j,0,8)rep(k,0,8)if(id[i][j][k]!=-1){
            if(i+j+k==n){
                if(k>=1) A.a[id[i][j][k]][id[i][j][k-1]]=1ll*k*inv[i+j+k+1]%mod;
                if(i>=1) A.a[id[i][j][k]][id[i-1][j+1][k]]=1ll*i*inv[i+j+k+1]%mod;
                if(j>=1) A.a[id[i][j][k]][id[i][j-1][k+1]]=1ll*j*inv[i+j+k+1]%mod;
            }
            else{
                if(k>=1) A.a[id[i][j][k]][id[i][j][k-1]]=1ll*k*inv[i+j+k+1]%mod;
                if(i>=1) A.a[id[i][j][k]][id[i][j+1][k]]=1ll*i*inv[i+j+k+1]%mod;
                if(j>=1) A.a[id[i][j][k]][id[i+1][j-1][k+1]]=1ll*j*inv[i+j+k+1]%mod;
            }
            A.a[id[i][j][k]][tot]=inv[i+j+k+1];
            A.a[id[i][j][k]][id[i][j][k]]=inv[i+j+k+1];
        }
        A.a[tot][tot]=1;
    }
}

namespace m2{
    inline void Init(){
        tot=0;
        mset(id,-1);
        rep(i,0,8)rep(j,0,8)if(i+j<=n) id[0][i][j]=++tot;
        ++tot;
        rep(i,0,8)rep(j,0,8)if(id[0][i][j]!=-1){
            if(i+j==n){
                if(j>=1) A.a[id[0][i][j]][id[0][i][j-1]]=1ll*j*inv[i+j+1]%mod;
                if(i>=1) A.a[id[0][i][j]][id[0][i-1][j+1]]=1ll*i*inv[i+j+1]%mod;
            }
            else{
                if(j>=1) A.a[id[0][i][j]][id[0][i][j-1]]=1ll*j*inv[i+j+1]%mod;
                if(i>=1) A.a[id[0][i][j]][id[0][i][j+1]]=1ll*i*inv[i+j+1]%mod;
            }
            A.a[id[0][i][j]][tot]=inv[i+j+1];
            A.a[id[0][i][j]][id[0][i][j]]=inv[i+j+1];
        }
        A.a[tot][tot]=1;
    }
}

namespace m1{
    inline void Init(){
        tot=0;
        mset(id,-1);
        rep(i,0,8)if(i<=n)id[0][0][i]=++tot;
        ++tot;
        rep(i,0,8)if(id[0][0][i]!=-1){
            if(i>=1) A.a[id[0][0][i]][id[0][0][i-1]]=1ll*i*inv[i+1]%mod;
            A.a[id[0][0][i]][tot]=inv[i+1];
            A.a[id[0][0][i]][id[0][0][i]]=inv[i+1];
        }
        A.a[tot][tot]=1;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    inv[1]=1;rep(i,2,10) inv[i]=mul((mod-mod/i),inv[mod%i]);
    read(t);read(m);read(n);
    if(m==3) m3::Init();else if(m==2) m2::Init();else m1::Init();
    A.n=A.m=tot;
    p[0]=A;
    // A.Print();
    rep(i,1,63) p[i]=p[i-1]*p[i-1];
    // rep(i,0,8)rep(j,0,8)rep(k,0,8)printf("id[%d][%d][%d]=%d\n",i,j,k,id[i][j][k]);
    while(t--){
        ll no;read(no);
        B.Clear();
        if(m==1) B.a[1][id[0][0][1]]=1;
        else if(m==2) B.a[1][id[0][1][0]]=1;
        else if(m==3) B.a[1][id[1][0][0]]=1;
        B.n=1;B.m=tot;
        // B.Print();
        rep(i,0,63){
            if((no>>i)&1){
                B=B*p[i];
                // printf("i=%d\n",i);
            }
        }
        printf("%d\n",B.a[1][tot]);
        // B.Print();
    }
    return 0;
}