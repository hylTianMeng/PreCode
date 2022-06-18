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

int n,m;

signed main(){
    read(n);read(m);
    ll now=n*m;
    int w=0;while(now){w++;now>>=1;}
    ll L=(1ll<<(w-1))-1;
    printf("%lld\n",(1ll<<w)-1);
    // if(n*m==(1ll<<w)-1){
    //     printf("%lld %lld %lld %lld\n",n,m,n,m);return 0;
    // }
    if(L%m==0){
        int h1=(L-1)/m+1;int h2=h1+1;
        printf("%lld %lld %lld %lld\n",h1,1,h2,m);
        return 0;
    }
    else{
        int h=(L-1)/m+1;int l=L-(h-1)*m;
        printf("%lld %lld %lld %lld\n",h,l,h,l+1);
    }
    return 0;
}