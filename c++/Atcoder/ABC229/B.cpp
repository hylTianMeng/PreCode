
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

ll a,b,na,nb;

int main(){
    read(a);read(b);
    while(a||b){
        na=a%10;nb=b%10;
        if(na+nb>=10){puts("Hard");return 0;}
        a/=10;b/=10;
    }
    puts("Easy");return 0;
}