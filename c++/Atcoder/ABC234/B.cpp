#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
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

struct Point{
    ld x,y;
    inline void Init(){read(x);read(y);}
};
Point a[N];

inline ld s(ld x){return x*x;}

inline ld Get(Point a,Point b){
    return sqrt(s(b.y-a.y)+s(b.x-a.x));
}

int n;
ld Ans;

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        a[i].Init();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Ans=max(Ans,Get(a[i],a[j]));
        }
    }
    printf("%0.10Lf",Ans);
    return 0;
}