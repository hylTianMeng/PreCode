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
    int k=2,n=10,m=5;
    printf("%d %d %d\n",k,n,m);
    for(int i=1;i<=k;i++){
        int x=random(100);
        printf("%d ",x);
    }puts("");
    for(int i=1;i<=n;i++){
        int op=random(3);
        int id=random(k);
        int val=random(10);
        printf("%d %d %d\n",op,id,val);
    }
}
