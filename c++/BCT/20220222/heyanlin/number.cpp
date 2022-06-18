#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 100010
#define M 25
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k,X,f[N][M];

namespace Subtask1{

    int ans[N],Ans=INF,a[N];

    inline void dfs(int p){
        if(p==n+1){
            int maxx=-INF;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    maxx=max(maxx,f[i][a[i]]+f[j][a[j]]+X*abs(a[i]-a[j]));
            if(maxx<Ans){
                Ans=maxx;
                for(int i=1;i<=n;i++) ans[i]=a[i];
            }
            return;
        }
        for(int i=1;i<=k;i++){
            a[p]=i;dfs(p+1);
        }
    }

    inline void Solve(){
        dfs(1);
        printf("%lld\n",Ans);
        for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    }
}

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    read(n);read(k);read(X);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++) read(f[i][j]);
    }
    if(n<=10&&k<=3) Subtask1::Solve();
    return 0;
}