#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 11000
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

int f[N],n,g[N],x;

int main(){
    read(n);read(x);
    f[0]=1;
    for(int i=1;i<=n;i++){
        int a,b;read(a);read(b);
        for(int j=0;j<=10000;j++){
            if(f[j]!=1) continue;
            g[j+a]=1;g[j+b]=1;
        }
        for(int j=0;j<=10000;j++) f[j]=g[j];
        for(int j=0;j<=10000;j++) g[j]=0;
    }
    if(f[x]){puts("Yes");}
    else puts("No");
    return 0;
}