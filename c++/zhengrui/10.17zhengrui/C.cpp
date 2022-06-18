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

inline int Solve(int n){
    if(n<=2||n==4){puts("No");return 0;}
    puts("Yes");
    if(n==3){
        printf("1 2\n3 3\n4 1\n2 2\n4 3\n3 1\n2 3\n1 1\n3 2\n1 3\n2 1\n4 2");
        return 0;
    };
    if(n==5){
        printf("1 2\n3 1\n4 3\n3 5\n1 4\n2 2\n4 1\n3 3\n4 5\n2 4\n3 2\n1 1\n2 3\n4 4\n2 5\n1 3\n2 1\n4 2\n3 4\n1 5");
        return 0;
    }
    if(n==6){
        printf("1 2\n3 1\n4 3\n3 5\n1 6\n2 4\n4 5\n2 6\n1 4\n2 2\n4 1\n3 3\n2 1\n1 3\n2 5\n4 6\n3 4\n4 2\n2 3\n1 1\n3 2\n4 4\n3 6\n1 5");
        return 0;
    }
    if(n==7){
        printf("1 2\n3 1\n4 3\n2 4\n1 6\n3 7\n4 5\n3 3\n4 1\n2 2\n3 4\n4 6\n2 7\n1 5\n3 6\n1 7\n2 5\n1 3\n2 1\n4 2\n2 3\n1 1\n3 2\n4 4\n3 5\n4 7\n2 6\n1 4");
        return 0;
    }
}

int main(){
    int t;read(t);
    while(t--){
        int n;
        read(n);Solve(n);
    }
}