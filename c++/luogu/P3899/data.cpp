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
    freopen("my.in","w",stdout);
    srand(time(0));
    int n=200;printf("%d ",n);int q=200;printf("%d\n",q);
    for(int i=2;i<=n;i++){
        printf("%d %d\n",i,random(i-1));
    }
    for(int i=1;i<=q;i++){
        printf("%d %d\n",random(n),random(n));
    }
    return 0;
}