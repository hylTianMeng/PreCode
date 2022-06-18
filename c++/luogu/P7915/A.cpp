#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10000010
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

int n,a[N];

int main(){
    read(n);
    for(int i=1;i<=(n<<1);i++) read(a[i]);
    for(int i=1;i<=(n<<1);i++) printf("%3d",i);puts("");
    for(int i=1;i<=(n<<1);i++) printf("%3d",a[i]);
}