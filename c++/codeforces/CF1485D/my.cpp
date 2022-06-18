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

int n,m,a[N][N],b[N][N];

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
    // int lc=1;
    // for(int i=2;i<=16;i++){
    //     int g=gcd(lc,i);
    //     lc=lc*i/g;
    // }
    // printf("%d\n",lc);
    // return 0;
    //720720
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i&1)==(j&1)) b[i][j]=720720;
            else b[i][j]=720720+pow(a[i][j],4);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",b[i][j]);
        puts("");
    }
    return 0;
}