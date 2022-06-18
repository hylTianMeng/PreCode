#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

int f[N][2],n,a[N],sum[N],g[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    f[1][0]=a[1];f[1][1]=a[1];
    for(int i=2;i<=n;i++){
        f[i][0]=Min(f[i-1][0],f[i-1][1])+a[i];
        f[i][1]=f[i-2][0]+a[i];
    }
    printf("%d\n",Min(f[n][0],f[n][1]));
    return 0;
}