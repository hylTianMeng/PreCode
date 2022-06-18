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

int n;

int main(){
    read(n);
    if(n<9){
        puts("-1");exit(0);
    }
    printf("%d\n",n);
    printf("1 2\n2 3\n1 4\n4 5\n5 6\n6 7\n");
    for(int i=8;i<=n;i++){
        printf("1 %d\n",i);
    }
    return 0;
}