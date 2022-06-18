#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

int f[15][2],a,b,c[10],d[10][2],w[15],t,e[10][2];

inline void Solve(int k){
    t=0;memset(w,0,sizeof(w));
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    while(k){
        w[++t]=k%10;k/=10;
    }
    for(int i=t+1;i>=2;i--){
        // printf("i=%d\n",i);
        for(int j=0;j<=9;j++) e[j][1]=e[j][0]=0;
        if(f[i][0]){
            for(int j=0;j<=9;j++){
                f[i-1][0]+=f[i][0];
                e[j][0]+=d[j][0]*10+f[i][0];
            }
        }
        // printf("_________________\n");
        // for(int j=0;j<=9;j++){
        //     printf("e[%lld][0]=%lld e[%lld][1]=%lld\n",j,e[j][0],j,e[j][1]);
        // }
        // printf("_________________over\n");
        if(f[i][1]){
            for(int j=0;j<=w[i-1];j++){
                f[i-1][j==w[i-1]]+=f[i][1];
                // e[j][j==w[i-1]]+=d[j][1]*(w[i-1]+1)+f[i][1];
                if(j!=w[i-1]){
                    e[j][0]+=d[j][1]*w[i-1]+f[i][1];
                    e[j][1]+=d[j][1];
                }
                else{
                    e[j][0]+=d[j][1]*w[i-1];
                    e[j][1]+=d[j][1]+1;
                }
            }
            for(int j=w[i-1]+1;j<=9;j++){
                e[j][0]+=d[j][1]*w[i-1];
                e[j][1]+=d[j][1];
            }
        }
        int up=(i==(t+1))?w[i-1]:9;
        for(int j=1;j<=up;j++){
            f[i-1][(j==up)&&(i==t+1)]++;
            e[j][(j==up)&&(i==t+1)]++;
        }
        for(int j=0;j<=9;j++){
            d[j][0]=e[j][0];d[j][1]=e[j][1];
        }
        // for(int j=0;j<=9;j++){
        //     printf("d[%lld][0]=%lld d[%lld][1]=%lld\n",j,d[j][0],j,d[j][1]);
        // }
        // printf("f[i-1][0]=%lld\n",f[i-1][0]);
        // printf("f[i-1][1]=%lld\n",f[i-1][1]);
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(a);read(b);
    Solve(b);for(int i=0;i<=9;i++) c[i]=d[i][0]+d[i][1];
    Solve(a-1);
    for(int i=0;i<=9;i++) printf("%lld ",c[i]-d[i][0]-d[i][1]);
    return 0;
}