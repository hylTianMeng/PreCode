#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3010
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

int k,a[N][N],n;

int main(){
    read(k);
    if(k<=500) n=k;
    else n=500;
    printf("%d\n",n);
    for(int j=1;j<=n;j++) a[1][j]=j;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=a[i-1][j];
        int last=a[i][n];
        for(int j=n;j>=2;j--){
            a[i][j]=a[i][j-1];
        }
        a[i][1]=last;
    }
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=n;j++){
            if(a[i][j]<=k-n) a[i][j]+=n;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
        puts("");
    }
}