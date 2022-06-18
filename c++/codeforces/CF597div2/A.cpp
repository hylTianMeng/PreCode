#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10100
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

int a,b,t;

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main(){
    read(t);
    while(t--){
        read(a);read(b);
        int g=gcd(a,b);
        if(g==1){printf("Finite\n");}
        else puts("Infinite");
    }
}