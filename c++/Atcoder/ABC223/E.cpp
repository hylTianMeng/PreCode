#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
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

int x,y,a,b,c;

inline bool Check(int x,int y,int b,int c){
    for(int i=1;i<=2;i++){
        int len=(b+x-1)/x;
        if(len<y&&(y-len)*x>=c) return 1;
        swap(x,y);
    }
    return 0;
}

inline bool Solve(int x,int y,int a,int b,int c){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=3;j++){
            int len=(a+x-1)/x;
            if(len<y&&Check(x,y-len,b,c)) return 1;
            swap(a,b);swap(b,c);
        }
        swap(x,y);
    }
    return 0;
}

signed main(){
    read(x);read(y);read(a);read(b);read(c);
    puts(Solve(x,y,a,b,c)?"Yes":"No");
    return 0;
}