#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

int a[N],n;

signed main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++) sum1=max(sum1,a[i]);
    for(int i=1;i<=n-1;i++) sum2+=abs(a[i]-a[i+1]);
    sum2+=abs(a[n]-a[1]);
    sum2/=2;
    printf("%lld\n",max(sum1,sum2));
}