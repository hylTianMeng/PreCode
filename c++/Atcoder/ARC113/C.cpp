#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int n,m,k,a[N],b[N],sum1,sum2,sum3,sum4,sum;

signed main(){
    read(n);read(m);read(k);sum=(k-1)*n*m;
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++) read(b[i]);
    for(int i=1;i<=n;i++) sum1+=a[i];
    for(int i=1;i<=m;i++) sum2+=b[i];
    if(sum1%k!=sum2%k){return puts("-1"),0;}
    sum1=n*(k-1)%k;sum2=m*(k-1)%k;
    // printf("sum1=%d sum2=%d\n",sum1,sum2);
    for(int i=1;i<=n;i++){int now=((sum2-a[i])%k+k)%k;sum3+=now;}
    for(int i=1;i<=m;i++){int now=((sum1-b[i])%k+k)%k;sum4+=now;}
    // printf("sum3=%d sum4=%d\n",sum3,sum4);
    printf("%lld\n",sum-max(sum3,sum4));
    return 0;
}