#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 110
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

int n,a[N],f[N][2],Sum;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]),Sum+=a[i];
    sort(a+1,a+n+1);f[n][0]=-a[n];f[n][1]=+a[n];
    // printf("f[%d][0]=%d f[%d][1]=%d\n",n,f[n][0],n,f[n][1]);
    for(int i=n-1;i>=1;i--){
        if(a[i]>=4){
            f[i][0]=Min(-a[i]+f[i+1][1],-(a[i]-4)+4+f[i+1][0]);
            f[i][1]=Max(a[i]+f[i+1][0],(a[i]-8)+f[i+1][1]);
        }
        else{
            f[i][0]=f[i+1][1]-a[i];
            f[i][1]=f[i+1][0]+a[i];
        }
        // printf("f[%d][0]=%d f[%d][1]=%d\n",i,f[i][0],i,f[i][1]);
    }
    int all=Sum-f[1][0];
    int Ans2=all/2;int Ans1=Sum-Ans2;
    printf("%lld %lld\n",Ans1,Ans2);
    return 0;
}