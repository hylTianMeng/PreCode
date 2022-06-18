#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 5000
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

int f[2][N],n,m,op,J;

inline void Solve(){
    op=0;f[0][0]=1;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            op^=1;memset(f[op],0,sizeof(f[op]));
            for(int s=0;s<=(1<<m)-1;s++){
                if(!f[op^1][s]) continue;
                if((s>>(j))&1){
                    f[op][s^(1<<(j))]+=f[op^1][s];
                    // printf("f[%d][%d]=%d <- f[%d][%d]=%d\n",op,s^(1<<(j)),f[op][s^(1<<(j))],op^1,s,f[op^1][s]);
                }
                else{
                    if(j<=m-2&&!((s>>(j+1))&1)){
                        f[op][s^(1<<(j+1))]+=f[op^1][s];
                        // printf("f[%d][%d]=%d <- f[%d][%d]=%d\n",op,s^(1<<(j+1)),f[op][s^(1<<(j+1))],op^1,s,f[op^1][s]);
                    }
                    f[op][s^(1<<(j))]+=f[op^1][s];
                    // printf("f[%d][%d]=%d <- f[%d][%d]=%d\n",op,s^(1<<(j)),f[op][s^(1<<(j))],op^1,s,f[op^1][s]);
                }
            }
        }
    }
    printf("%lld\n",f[op][0]);
}

inline void Clear(){
    memset(f,0,sizeof(f));
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    while(scanf("%lld%lld",&n,&m)!=EOF&&n&&m){
        Solve();Clear();
    }
    return 0;
}