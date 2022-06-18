#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 1000100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N];
int c[10][10][10][10][10][10];

#define C(x) c[(x/100000)%10][(x/10000)%10][(x/1000)%10][(x/100)%10][(x/10)%10][x%10]

signed main(){
    // freopen("my.in","r",stdin);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        C(a[i])++;
    }
    rep(i,0,9)rep(j,0,9)rep(k,0,9)rep(o,0,9)rep(p,0,9)rep(q,1,9)c[i][j][k][o][p][q]+=c[i][j][k][o][p][q-1];
    rep(i,0,9)rep(j,0,9)rep(k,0,9)rep(o,0,9)rep(p,1,9)rep(q,0,9)c[i][j][k][o][p][q]+=c[i][j][k][o][p-1][q];
    rep(i,0,9)rep(j,0,9)rep(k,0,9)rep(o,1,9)rep(p,0,9)rep(q,0,9)c[i][j][k][o][p][q]+=c[i][j][k][o-1][p][q];
    rep(i,0,9)rep(j,0,9)rep(k,1,9)rep(o,0,9)rep(p,0,9)rep(q,0,9)c[i][j][k][o][p][q]+=c[i][j][k-1][o][p][q];
    rep(i,0,9)rep(j,1,9)rep(k,0,9)rep(o,0,9)rep(p,0,9)rep(q,0,9)c[i][j][k][o][p][q]+=c[i][j-1][k][o][p][q];
    rep(i,1,9)rep(j,0,9)rep(k,0,9)rep(o,0,9)rep(p,0,9)rep(q,0,9)c[i][j][k][o][p][q]+=c[i-1][j][k][o][p][q];
    // printf("here\n");
    int ans=0;
    rep(i,1,n){
        // printf("i=%d\n",i);
        // printf("%lld\n",999999-a[i]);
        // printf("C(x)=%lld\n",C((999999-a[i])));
        ans+=C((999999-a[i]));
        if((a[i]/100000)%10<=4&&(a[i]/10000)%10<=4&&(a[i]/1000)%10<=4&&(a[i]/100)%10<=4&&(a[i]/10)%10<=4&&a[i]%10<=4) ans--;
    }
    assert(ans%2==0);
    printf("%lld\n",ans/2);
    return 0;
}
