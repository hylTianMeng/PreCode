#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 4000100
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

int n,d,n1,n2;

int main(){
    read(n);read(d);
    n2=n/2;n1=n-n2;
    if((n+1)/2+2*(n/2)<=d){puts("-1");exit(0);}
    for(int i=1;i<=n;i+=2) printf("%d ",i);
    for(int i=2;i<=n;i+=2) printf("%d %d ",i,i);
    for(int i=1;i<=n;i+=2) printf("%d ",i);
    return 0;
}