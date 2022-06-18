#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

ld f[N][N],g[N][N],c[N][N];
int n,d,r;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(d);read(r);
    f[n][n]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++){
            if(j==0||j==i) c[i][j]=1;
            else c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    for(int j=n+1;j<=n+d;j++){
        for(int i=1;j-i>=n&&i<=n;i++){
            //f[i][j]
            for(int k=i;k<=n;k++){
                f[i][j]+=f[k][j-i]*c[k][i];
                g[i][j]+=(g[k][j-i]+min(i,r)*f[k][j-i])*c[k][i];
            }
        }
    }
    ld sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        sum1+=f[i][n+d];
        sum2+=g[i][n+d];
    }
    printf("%0.8Lf\n",sum2/sum1+r);
    return 0;
}