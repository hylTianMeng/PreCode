#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20
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

map<int,int> Map[N];

inline int random(int n){return 1ll*rand()*rand()%n+1;}

int main(){
    freopen("my.in","w",stdout);
    srand(time(0));
    int n=random(10);
    int m=random(n*n);
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        int a=random(n),b=random(n);
        if(Map[a].find(b)!=Map[a].end()){i--;continue;}
        Map[a][b]=1;
        printf("%d %d\n",a,b);
    }
}