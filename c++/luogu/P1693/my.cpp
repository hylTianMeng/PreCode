#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5000
#define M 12
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[2][N],t,n,m,a[M][M],op;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) read(a[i][j]);
}

inline void Solve(int id){
    memset(f,0,sizeof(f));
    op=0;f[0][0]=1;
    for(int i=1;i<=n;i++){
        // printf("i=%lld\n",i);
        for(int j=0;j<=m-1;j++){
            // printf("j=%lld\n",j);
            op^=1;memset(f[op],0,sizeof(f[op]));
            for(int s=0;s<(1<<(m+1));s++){
                if(!f[op^1][s]) continue;
                int L=(s>>j)&1,U=(s>>(j+1))&1;
                if(!a[i][j+1]){
                    if(!L&&!U){
                        f[op][s]+=f[op^1][s];
                        // printf("No f[%lld][%lld]=%lld <- f[%lld][%lld]=%lld\n",op,s,f[op][s],op^1,s,f[op^1][s]);
                    }
                }
                else{
                    f[op][s^(3<<j)]+=f[op^1][s];
                    // printf("f[%lld][%lld]=%lld <- f[%lld][%lld]=%lld\n",op,s^(3<<j),f[op][s^(3<<j)],op^1,s,f[op^1][s]);
                    if(L!=U){
                        f[op][s]+=f[op^1][s];
                        // printf("f[%lld][%lld]=%lld <- f[%lld][%lld]=%lld\n",op,s,f[op][s],op^1,s,f[op^1][s]);
                    }
                }
            }
        }
        op^=1;memset(f[op],0,sizeof(f[op]));
        for(int s=0;s<(1<<m);s++) f[op][s<<1]=f[op^1][s];
    }
    printf("Case %lld: There are %lld ways to eat the trees.\n",id,f[op][0]);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    for(int i=1;i<=t;i++){
        Init();Solve(i);
    }
}