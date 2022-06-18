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

int n,a[N];

int main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    if(n==1){
        printf("%d %d\n",1,n);
        printf("%lld\n",-1ll*a[1]);
        printf("%d %d\n",1,1);
        printf("%d\n",0);
        printf("%d %d\n",1,1);
        printf("%d\n",0);
        return 0;
    }
    printf("%d %d\n",1,n);
    for(int i=1;i<=n;i++) printf("%lld ",-1ll*a[i]*n);puts("");
    printf("%d %d\n",2,n);
    for(int i=2;i<=n;i++) printf("%lld ",1ll*a[i]*(n-1));puts("");
    printf("%d %d\n",1,1);
    printf("%lld\n",1ll*(n-1)*a[1]);
    return 0;
}