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

int a,b,c,d;

inline bool Check(int x){
    for(int i=2;i<=x-1;i++) if(x%i==0) return 0;
    return 1;
}

int main(){
    read(a);read(b);read(c);read(d);
    for(int i=a;i<=b;i++){
        bool op=0;
        for(int j=c;j<=d;j++){
            int now=i+j;
            if(Check(now)){op=1;break;}
        }
        // printf("i=%d\n",i);
        if(!op){
            puts("Takahashi");return 0;
        }
    }
    puts("Aoki");
    return 0;
}