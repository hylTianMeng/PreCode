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

int m,maxy=-INF,miny=INF;

int main(){
    read(m);
    for(int i=1;i<=m;i++){
        int x,y01,y11;read(x);read(y01);read(y11);
        maxy=max(maxy,y11);
        miny=min(miny,y01);
    }
    dd len=maxy-miny;
    printf("%0.2lf",(dd)len*len/2);
    return 0;
}