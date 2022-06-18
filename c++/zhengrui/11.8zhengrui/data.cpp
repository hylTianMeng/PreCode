#include<bits/stdc++.h>
#define dd double
#define ld long double
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

inline int random(int n){return 1ll*rand()*rand()%n+1;}

int main(){
    srand(time(0));
    freopen("my.in","w",stdout);
    int n=1000,m=64;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int a=random(4)-1;
            printf("%d",a);
        }
        puts("");
    }
    return 0;
}