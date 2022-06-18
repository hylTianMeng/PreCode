#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
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

int n,l,f[N];

inline void Init(){
    for(int i=1;i<=n;i++) read(f[i]);
}

inline void Solve(){
    if(n==2){
        printf("%d\n",f[1]+f[2]);return;
    }
    else if(n==1){
        printf("%d\n",f[1]);
    }
}

int main(){
    while(scanf("%d %d",&n,&l)!=EOF&&n&&l){
        Init();Solve();
    }
}