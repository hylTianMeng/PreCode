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

inline void Maped(int id){
    if(id==0) putchar('B');
    else if(id==1) putchar('G');
    else if(id==2) putchar('R');
    else putchar('Y');
}

int main(){
    srand(time(0));
    freopen("my.in","w",stdout);
    int t=40;printf("%d\n",t);
    while(t--){
        int n=random(1000);printf("%d\n",n);
        for(int i=1;i<=n;i++){
            for(int i=1;i<=4;i++){
                Maped(random(4)-1);
                printf("%d"random(10)-1);
            }
            puts("");
        }
        
    }
}