#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 15
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

int n,f[N][2],g[N][2],w[N],t;

inline void Solve(int k){
    while(k){
        w[++t]=k%10;k/=10;
    }
    for(int i=t+1;i>=2;i--){
        if(f[i][0]&&g[i][0]&&f[i][1]&&g[i][1]) f[i-1][0]=10*f[i][0]+g[i][0]*45+w[i-1]*f[i][1]+w[i-1]*(w[i-1]-1)/2*g[i][1];
        if(f[i][1]) f[i-1][1]=f[i][1]+w[i-1];
        if(g[i][0]&&g[i][1]) g[i-1][0]=g[i][0]*10+w[i-1]*g[i][1];
        if(g[i][1]) g[i-1][1]=g[i][1];
        int up=(i==t+1)?w[i-1]:9;
        for(int j=1;j<=up;j++){
            f[i-1][(j==up)&&(i==t+1)]+=j;
            g[i-1][(j==up)&&(i==t+1)]++;
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);Solve(n);
    // printf("%lld\n",g[1][0]+g[1][1]);
    printf("%lld\n",f[1][0]+f[1][1]);
    return 0;
}