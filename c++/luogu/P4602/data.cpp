#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
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

inline int random(int n){return 1ll*rand()*rand()%n+1;}

signed main(){
    srand(time(0));
    freopen("my.in","w",stdout);
    int n=100000,m=1;
    printf("%lld %lld\n",n,m);
    for(int i=1;i<=n;i++){
        int d=random(10000)+90000,p=random(10000)+80000,l=random(10000)+80000;
        printf("%lld %lld %lld\n",d,p,l);
    }
    for(int i=1;i<=m;i++){
        int g,l;g=random(10000000000)+10000000000,l=random(1000000)+900000;
        printf("%lld %lld\n",g,l);
    }
    return 0;
}