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
#define N 1000100
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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][10],n;

int main(){
    read(n);
    rep(i,1,9) f[1][i]=1;
    rep(i,1,n-1){
        rep(j,1,9){
            if(j==1){
                f[i+1][j]=inc(f[i+1][j],f[i][j]);
                f[i+1][j+1]=inc(f[i+1][j+1],f[i][j]);
            }
            else if(j==9){
                f[i+1][j]=inc(f[i+1][j],f[i][j]);
                f[i+1][j-1]=inc(f[i+1][j-1],f[i][j]);
            }
            else {
                f[i+1][j]=inc(f[i+1][j],f[i][j]);
                f[i+1][j+1]=inc(f[i+1][j+1],f[i][j]);
                f[i+1][j-1]=inc(f[i+1][j-1],f[i][j]);
            }
        }
    }
    int ans=0;
    rep(i,1,9) ans=inc(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}