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
    printf("1\n");
    int n=10000,m=10010;printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        int from,to,w,h;from=random(n);to=random(n);w=random(100);h=random(100);
        printf("%d %d %d %d\n",from,to,w,h);
    }
    int q=1000,K=0,P=random(50);
    printf("%d %d %d\n",q,K,P);
    for(int i=1;i<=q;i++){
        int k=random(n),p=random(P);
        printf("%d %d\n",k,p);
    }
}